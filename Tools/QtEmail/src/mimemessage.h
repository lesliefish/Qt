/*******************************************************************
 *  文件名称:   smtpclient.cpp
 *  简要描述:   smtp客户端类，负责邮件信息初始化、连接、认证、发送等主要功能
 *
 *  创建日期:  2017年10月14日
 *  作者:        lesliefish
 *  说明:
 ******************************************************************/

#ifndef MIMEMESSAGE_H
#define MIMEMESSAGE_H

#include "mimepart.h"
#include "mimemultipart.h"
#include "publicdefine.h"
#include <QList>
using namespace PublicDefine;

class MimeMessage : public QObject
{
public:
    MimeMessage(bool createAutoMimeConent = true);
    ~MimeMessage();

    typedef struct STRURECIPIENT
    {
        EmailAddress struRecipient;
        RecipientType enumType;
    }RecipientInfo;


    QList<RecipientInfo> m_listRecipients;

    void setSender(EmailAddress& e);
    void addRecipient(EmailAddress& rcpt, RecipientType type = To);
    void setSubject(const QString & subject);
    void addPart(MimePart* part);

    void setInReplyTo(const QString& inReplyTo);

    void setHeaderEncoding(MimePart::Encoding);

    const EmailAddress & getSender() const;
 //   const QList<EmailAddress> & getRecipients(RecipientType type = To) const;
 //   const QString & getSubject() const;
    const QList<MimePart*> & getParts() const;

    MimePart& getContent();
    void setContent(MimePart *content);

    virtual QString toString();

public:
    QList<EmailAddress> m_listTos, m_listCcs, m_listBccs;
    EmailAddress m_struSender;
    RecipientInfo m_struRecipient;
    QString m_strSubject;
    QString mInReplyTo;
    MimePart *content;
    bool autoMimeContentCreated;
    
    MimePart::Encoding hEncoding;
};

#endif // MIMEMESSAGE_H
