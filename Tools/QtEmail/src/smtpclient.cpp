/*******************************************************************
 *  文件名称:   smtpclient.cpp
 *  简要描述:   smtp客户端类，负责邮件信息初始化、连接、认证、发送等主要功能
 *
 *  创建日期:  2017年10月14日
 *  作者:        lesliefish
 *  说明:
 ******************************************************************/
#include "smtpclient.h"
#include <QtNetwork/qabstractsocket.h>
#include <QFileInfo>
#include <QByteArray>

/**
 *  功能描述:构造函数
 *  @name   SmtpClient(const SmtpParams& params)
 *  @author lesliefish
 *  @param params   smtp客户端配置参数
 *  @param enumConnectionType 连接类型
 *  @return 无返回值
 */
SmtpClient::SmtpClient(const SmtpParams& params) :
    m_pSocket(NULL),
    name(params.strHost)
{
    this->m_struSmtpParams = params;
    InitSocket();

    connect(m_pSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));
    connect(m_pSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(socketError(QAbstractSocket::SocketError)));
    connect(m_pSocket, SIGNAL(readyRead()),
            this, SLOT(socketReadyRead()));
}

SmtpClient::~SmtpClient()
{
    if (m_pSocket)
        delete m_pSocket;
}

/**
 *  功能描述:初始化通信socket对象
 *  @name   InitSocket()
 *  @author lesliefish
 *  @param 无
 *  @return 成功返回true，失败返回false
 */
bool SmtpClient::InitSocket()
{
    if (m_pSocket)
        delete m_pSocket;

    switch (m_struSmtpParams.enumConnectionType)
    {
    case TcpConnection:
        m_pSocket = new QTcpSocket(this);
        break;
    case SslConnection:
    case TlsConnection:
        m_pSocket = new QSslSocket(this);
    }
    if(NULL == m_pSocket)
        return false;
    else
        return true;
}

/**
 *  功能描述:获取服务器的响应字符串
 *  @name   GetResponseText()
 *  @author lesliefish
 *  @param  无
 *  @return 响应字符串
 */
const QString & SmtpClient::GetResponseText() const
{
    return m_strResponseText;
}

/**
 *  功能描述:获取服务器返回码
 *  @name   GetResponseCode()
 *  @author lesliefish
 *  @param  无
 *  @return 服务器返回码
 */
int SmtpClient::GetResponseCode() const
{
    return m_iResponseCode;
}

/**
 *  功能描述:连接邮件服务器
 *  @name   ConnectToHost()
 *  @author lesliefish
 *  @param  无
 *  @return 连接成功返回true，失败返回false
 */
bool SmtpClient::ConnectToHost()
{
    switch (m_struSmtpParams.enumConnectionType)
    {
    case TlsConnection:
    case TcpConnection:
        m_pSocket->connectToHost(m_struSmtpParams.strHost, m_struSmtpParams.iPort);
        break;
    case SslConnection:
        ((QSslSocket*) m_pSocket)->connectToHostEncrypted(m_struSmtpParams.strHost, m_struSmtpParams.iPort);
        break;
    }

    //连接
    if (!m_pSocket->waitForConnected(m_struSmtpParams.iConnectionTimeout))
    {
        emit smtpError(ConnectionTimeoutError);
        return false;
    }

    try
    {
        // 等待服务器响应
        WaitForResponse();

        // 连接成功响应码为220
        if (m_iResponseCode != 220)
        {
            emit smtpError(ServerError);
            return false;
        }

        // 客户端发送的第一个命令为 EHLO 或 HELO
        SendMessage("EHLO " + name);

        // 等待服务器响应
        WaitForResponse();

        // 服务端收到EHLO后返回码应是250，表示所要求的邮件动作完成,可以继续邮件对话
        if (m_iResponseCode != 250) {
            emit smtpError(ServerError);
            return false;
        }

        if (m_struSmtpParams.enumConnectionType == TlsConnection)
        {
            // STARTTLS加密，发送“STARTTLS”，开始TLS握手
            SendMessage("STARTTLS");
            // 等待服务器响应
            WaitForResponse();
            // 响应码须是220
            if (m_iResponseCode != 220)
            {
                emit smtpError(ServerError);
                return false;
            };

            ((QSslSocket*) m_pSocket)->startClientEncryption();

            if (!((QSslSocket*) m_pSocket)->waitForEncrypted(m_struSmtpParams.iConnectionTimeout))
            {
                //打印错误原因
                qDebug() << ((QSslSocket*) m_pSocket)->errorString();
                emit smtpError(ConnectionTimeoutError);
                return false;
            }
            // 再次发送ELHO命令
            SendMessage("EHLO " + name);
            // 等待服务器响应
            WaitForResponse();
            // 250 表示所要求的邮件动作完成,可以继续邮件对话
            if (m_iResponseCode != 250)
            {
                emit smtpError(ServerError);
                return false;
            }
        }
    }
    catch (ResponseTimeoutException)
    {
        return false;
    }
    catch (SendMessageTimeoutException)
    {
        return false;
    }

    return true;
}

/**
 *  功能描述:用户登录、认证
 *  @name   Login()
 *  @author lesliefish
 *  @return 成功返回 true 失败返回false
 */
bool SmtpClient::Login()
{
    QString user = m_struSmtpParams.strUserName;
    QString password = m_struSmtpParams.strPassword;
    AuthMethod method = m_struSmtpParams.enumAuthMethod;
    try
    {
        if (method == AuthPlain)
        {
            // 发送命令字符串格式: AUTH PLAIN base64('\0' + username + '\0' + password)
            SendMessage("AUTH PLAIN " + QByteArray().append((char) 0).append(user).append((char) 0).append(password).toBase64());
            // 等待服务器响应
            WaitForResponse();
            // 用户认证成功返回235
            if (m_iResponseCode != 235)
            {
                emit smtpError(AuthenticationFailedError);
                return false;
            }
        }
        else if (method == AuthLogin)
        {
            // 发送字符串命令格式为: AUTH LOGIN
            SendMessage("AUTH LOGIN");

            // 334 下一步
            WaitForResponse();
            if (m_iResponseCode != 334)
            {
                emit smtpError(AuthenticationFailedError);
                return false;
            }

            // 以base64形式发送用户名
            SendMessage(QByteArray().append(user).toBase64());

            // 334 下一步
            WaitForResponse();
            if (m_iResponseCode != 334)
            {
                emit smtpError(AuthenticationFailedError);
                return false;
            }

            // 以base64形式发送密码
            SendMessage(QByteArray().append(password).toBase64());

            // 等服务器响应
            WaitForResponse();

            // 认证码235为认证成功
            if (m_iResponseCode != 235)
            {
                emit smtpError(AuthenticationFailedError);
                return false;
            }
        }
    }
    catch (ResponseTimeoutException)
    {
        // 响应超时
        emit smtpError(AuthenticationFailedError);
        return false;
    }
    catch (SendMessageTimeoutException)
    {
        // 发送超时
        emit smtpError(AuthenticationFailedError);
        return false;
    }
    return true;
}

/**
 *  功能描述:连接邮件服务器
 *  @name   SendMail(MimeMessage& email)
 *  @author lesliefish
 *  @param  MimeMessage& 邮箱体
 *  @return 连接成功返回true，失败返回false
 */
bool SmtpClient::SendMail(MimeMessage& email)
{
    try
    {
        //MAIL FROM: 命令
        SendMessage("MAIL FROM: <" + email.m_struSender.strAddr + ">");
        WaitForResponse();

        if (m_iResponseCode != 250)
            return false;

        // 收件人命令 RCPT
        QList<EmailAddress>::const_iterator it, itEnd;
        // To 普通收件人
        for (it = email.m_listTos.begin(), itEnd = email.m_listTos.end();
             it != itEnd; ++it)
        {
            SendMessage("RCPT TO:<" + (*it).strAddr + ">");
            WaitForResponse();
            if (m_iResponseCode != 250)
                return false;
        }

        // Cc 抄送
        for (it = email.m_listCcs.begin(), itEnd = email.m_listCcs.end();
             it != itEnd; ++it)
        {
            SendMessage("RCPT TO:<" + (*it).strAddr + ">");
            WaitForResponse();

            if (m_iResponseCode != 250)
                return false;
        }

        // Bcc 密送
        for (it = email.m_listBccs.begin(), itEnd = email.m_listBccs.end();
             it != itEnd; ++it)
        {
            SendMessage("RCPT TO: <" + (*it).strAddr + ">");
            WaitForResponse();

            if (m_iResponseCode != 250)
                return false;
        }

        // DATA 命令
        SendMessage("DATA");
        WaitForResponse();

        if (m_iResponseCode != 354) return false;

        SendMessage(email.toString());

        // 发送 \r\n.\r\n 结束邮件体
        SendMessage(".");
        WaitForResponse();
        if (m_iResponseCode != 250) return false;
    }
    catch (ResponseTimeoutException)
    {
        return false;
    }
    catch (SendMessageTimeoutException)
    {
        return false;
    }

    return true;
}

/**
 *  功能描述: 断开连接
 *  @name  Quit()
 *  @author lesliefish
 *  @param  void
 *  @return void
 */
void SmtpClient::Quit()
{
    try 
    {
        SendMessage("QUIT");
    }
    catch(SmtpClient::SendMessageTimeoutException) 
    {
       //若 "QUIT"命令失效，手动关闭
        if(m_pSocket->state() == QAbstractSocket::ConnectedState
                || m_pSocket->state() == QAbstractSocket::ConnectingState
                || m_pSocket->state() == QAbstractSocket::HostLookupState)
            m_pSocket->disconnectFromHost();
    }
}

/**
 *  功能描述: 响应服务器
 *  @name  WaitForResponse()
 *  @author lesliefish
 *  @param  void
 *  @return void
 */
void SmtpClient::WaitForResponse()
{
    do
    {
        if (!m_pSocket->waitForReadyRead(m_struSmtpParams.iResponseTimeout))
        {
            emit smtpError(ResponseTimeoutError);
            throw ResponseTimeoutException();
        }

        while (m_pSocket->canReadLine())
        {
            // 获取服务器响应字符串
            m_strResponseText = m_pSocket->readLine();
            // 响应码  m_strResponseText前3位
            m_iResponseCode = m_strResponseText.left(3).toInt();

            //服务端错误
            if (m_iResponseCode / 100 == 4)
                emit smtpError(ServerError);
            //客户端错误
            if (m_iResponseCode / 100 == 5)
                emit smtpError(ClientError);

            if (m_strResponseText[3] == ' ') { return; }
        }
    } while (true);
}

/**
 *  功能描述: 发送数据到服务器
 *  @name  SendMessage(const QString &text)
 *  @author lesliefish
 *  @param const QString & 将要发送的文本
 *  @return void
 */
void SmtpClient::SendMessage(const QString &text)
{
    m_pSocket->write(text.toUtf8() + "\r\n");
    if (! m_pSocket->waitForBytesWritten(m_struSmtpParams.iSendMessageTimeout))
    {
      emit smtpError(SendDataTimeoutError);
      throw SendMessageTimeoutException();
    }
}

/**
 *  功能描述: 处理socket状态变化事件
 *  @name  socketStateChanged(QAbstractSocket::SocketState）
 *  @author lesliefish
 *  @param QAbstractSocket::SocketState socket状态码
 *  @return void
 */
void SmtpClient::socketStateChanged(QAbstractSocket::SocketState /*state*/)
{
}

/**
 *  功能描述: socket错误信息
 *  @name  socketError(QAbstractSocket::SocketError)
 *  @author lesliefish
 *  @param QAbstractSocket::SocketError 错误原因
 *  @return void
 */
void SmtpClient::socketError(QAbstractSocket::SocketError /*socketError*/)
{
}

/**
 *  功能描述: socket可读
 *  @name  socketReadyRead()
 *  @author lesliefish
 *  @param void
 *  @return void
 */
void SmtpClient::socketReadyRead()
{
}
