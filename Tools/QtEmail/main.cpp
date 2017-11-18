#include <QCoreApplication>
#include "src/publicdefine.h"
#include "src/smtpclient.h"
#include "src/mimetext.h"
#include "src/mimeattachment.h"
using namespace PublicDefine;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SmtpParams smtpParams;
    smtpParams.strHost = "smtp.csu.edu.cn";
    smtpParams.iPort = 25;
    smtpParams.enumConnectionType = TcpConnection;
    smtpParams.enumAuthMethod = AuthLogin;
    smtpParams.strUserName = "144712065";
    smtpParams.strPassword = "xxxx";
    smtpParams.iConnectionTimeout = 10000;
    smtpParams.iResponseTimeout = 10000;
    smtpParams.iSendMessageTimeout = 10000;

    SmtpClient sc(smtpParams);

    MimeMessage message;
    EmailAddress sender;
    sender.strAddr = "144712065@csu.edu.cn";
    sender.strName = "144712065";
    message.setSender(sender);

    EmailAddress to;
    to.strAddr = "44865959@qq.com";
    to.strName = "44865959";
    message.addRecipient(to);
    message.setSubject("邮件主题");

    MimeText text;
    text.setText("邮件文本信息.\n");
    message.addPart(&text);

    MimeAttachment attach(new QFile("C:/1.jpg"));
    message.addPart(&attach);

    if (!sc.ConnectToHost())
    {
        qDebug() << "连接服务器失败!" << endl;
        return -1;
    }

    if (!sc.Login())
    {
        qDebug() << "登录失败!" << endl;
        return -2;
    }

    if (!sc.SendMail(message))
    {
        qDebug() << "发送邮件失败!" << endl;
        return -3;
    }

    sc.Quit();
    qDebug() << "sent." ;
    return a.exec();
}
