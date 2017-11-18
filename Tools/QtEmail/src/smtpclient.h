#ifndef SMTPCLIENT_H
#define SMTPCLIENT_H

#include <QObject>
#include <QtNetwork/QSslSocket>
#include "mimemessage.h"
#include "publicdefine.h"
using namespace PublicDefine;

class SmtpClient : public QObject
{
    Q_OBJECT
public:
    SmtpClient(const SmtpParams&);
    ~SmtpClient();
    bool InitSocket();
    const QString & GetResponseText() const;
    int GetResponseCode() const;
    bool ConnectToHost();
    bool Login();
    bool SendMail(MimeMessage& email);
    void Quit();
public:
    QTcpSocket *m_pSocket;
    QString name;
    SmtpParams m_struSmtpParams;
    QString m_strResponseText;
    int m_iResponseCode;
    class ResponseTimeoutException {};
    class SendMessageTimeoutException {};
    void WaitForResponse();
    void SendMessage(const QString &text);

private slots:
    void socketStateChanged(QAbstractSocket::SocketState state);
    void socketError(QAbstractSocket::SocketError error);
    void socketReadyRead();

signals:
    void smtpError(SmtpError e);
};

#endif // SMTPCLIENT_H
