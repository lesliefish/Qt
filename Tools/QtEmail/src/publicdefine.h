#ifndef PUBLICDEFINE_H
#define PUBLICDEFINE_H
#include <QString>

namespace PublicDefine
{
    // 服务器认证类型
    enum AuthMethod
    {
        AuthPlain,
        AuthLogin
    };

    //Smtp错误信息
    enum SmtpError
    {
        ConnectionTimeoutError,
        ResponseTimeoutError,
        SendDataTimeoutError,
        AuthenticationFailedError,
        ServerError,    // 4xx 服务端错误
        ClientError     // 5xx 客户端错误
    };

    //服务器连接类型
    enum ConnectionType
    {
        TcpConnection,      // 无加密
        SslConnection,      // Ssl加密
        TlsConnection       // STARTTLS加密
    };

    //收件人类型
    enum RecipientType
    {
        To,                 // 普通收件人
        Cc,                 // 抄送
        Bcc                 // 密送
    };

    //smtp 服务器配置数据结构体
    typedef struct SMTPPARAMS
    {
        QString strHost;
        int     iPort;
        ConnectionType enumConnectionType;
        AuthMethod enumAuthMethod;
        QString strUserName;
        QString strPassword;
        int iConnectionTimeout;
        int iResponseTimeout;
        int iSendMessageTimeout;
    }SmtpParams;

    //邮箱地址，包括用户名和邮箱地址
    typedef struct EMAILADDRESS
    {
        QString strName;
        QString strAddr;
    }EmailAddress;


}




#endif // PUBLICDEFINE_H
