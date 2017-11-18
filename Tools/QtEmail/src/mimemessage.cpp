/*******************************************************************
 *  文件名称:   mimemessage.cpp
 *  简要描述:   smtp 信息体
 *
 *  创建日期:  2017年10月14日
 *  作者:        lesliefish
 *  说明:       邮件内容的主体部分
 ******************************************************************/

#include "mimemessage.h"
#include <QDateTime>
#include "quotedprintable.h"
#include <typeinfo>

MimeMessage::MimeMessage(bool createAutoMimeContent) :
    hEncoding(MimePart::_8Bit)
{
    if (createAutoMimeContent)
        this->content = new MimeMultiPart();
    
    autoMimeContentCreated = createAutoMimeContent;
}

MimeMessage::~MimeMessage()
{
    if (this->autoMimeContentCreated)
    {
        this->autoMimeContentCreated = false;
        delete (this->content);
    }
}


MimePart& MimeMessage::getContent()
{
    return *content;
}

void MimeMessage::setContent(MimePart *content)
{
    if (this->autoMimeContentCreated)
    {
        this->autoMimeContentCreated = false;
            delete (this->content);
    }
}

void MimeMessage::setSender(EmailAddress& emailAddress)
{
    m_struSender = emailAddress;
}

void MimeMessage::addRecipient(EmailAddress& rcpt, RecipientType type)
{
    m_struRecipient.struRecipient = rcpt;
    m_struRecipient.enumType = type;
    m_listRecipients << m_struRecipient;
    switch (type)
    {
    case To:
        m_listTos << rcpt;
        break;
    case Cc:
        m_listCcs << rcpt;
        break;
    case Bcc:
        m_listBccs << rcpt;
        break;
    }
}

void MimeMessage::setSubject(const QString & subject)
{
    this->m_strSubject = subject;
}

void MimeMessage::addPart(MimePart *part)
{
    if (typeid(*content) == typeid(MimeMultiPart)) {
        ((MimeMultiPart*) content)->addPart(part);
    };
}

void MimeMessage::setInReplyTo(const QString& inReplyTo)
{
    mInReplyTo = inReplyTo;
}

void MimeMessage::setHeaderEncoding(MimePart::Encoding hEnc)
{
    this->hEncoding = hEnc;
}

const EmailAddress & MimeMessage::getSender() const
{
    return m_struSender;
}

const QList<MimePart*> & MimeMessage::getParts() const
{
    if (typeid(*content) == typeid(MimeMultiPart))
    {
        return ((MimeMultiPart*) content)->getParts();
    }
    else
    {
        QList<MimePart*> *res = new QList<MimePart*>();
        res->append(content);
        return *res;
    }
}



QString MimeMessage::toString()
{
    QString mime;

    /* =========== MIME 信息头 ============ */

    /* ---------- 发件人 From ----------- */
    mime = "From:";
    if (m_struSender.strName != "")
    {
        switch (hEncoding)
        {
        case MimePart::Base64:
            mime += " =?utf-8?B?" + QByteArray().append(m_struSender.strName).toBase64() + "?=";
            break;
        case MimePart::QuotedPrintable:
            mime += " =?utf-8?Q?" + QuotedPrintable::encode(QByteArray().append(m_struSender.strName)).replace(' ', "_").replace(':',"=3A") + "?=";
            break;
        default:
            mime += " " + m_struSender.strName;
        }
    }
    mime += " <" + m_struSender.strAddr + ">\r\n";


    /* -------  收件人 / To ---------- */
    mime += "To:";
    QList<EmailAddress>::iterator it;
    int i;
    for (i = 0, it = m_listTos.begin(); it != m_listTos.end(); ++it, ++i)
    {
        if (i != 0) { mime += ","; }

        if ((*it).strName != "")
        {
            switch (hEncoding)
            {
            case MimePart::Base64:
                mime += " =?utf-8?B?" + QByteArray().append((*it).strName).toBase64() + "?=";
                break;
            case MimePart::QuotedPrintable:
                mime += " =?utf-8?Q?" + QuotedPrintable::encode(QByteArray().append((*it).strName)).replace(' ', "_").replace(':',"=3A") + "?=";
                break;
            default:
                mime += " " + (*it).strName;
            }
        }
        mime += " <" + (*it).strAddr + ">";
    }
    mime += "\r\n";


    /* ------- 收件人 / Cc ---------- */
    if (m_listCcs.size() != 0)
    {
        mime += "Cc:";
    }
    for (i = 0, it = m_listCcs.begin(); it != m_listCcs.end(); ++it, ++i)
    {
        if (i != 0) { mime += ","; }

        if ((*it).strName != "")
        {
            switch (hEncoding)
            {
            case MimePart::Base64:
                mime += " =?utf-8?B?" + QByteArray().append((*it).strName).toBase64() + "?=";
                break;
            case MimePart::QuotedPrintable:
                mime += " =?utf-8?Q?" + QuotedPrintable::encode(QByteArray().append((*it).strName)).replace(' ', "_").replace(':',"=3A") + "?=";
                break;
            default:
                mime += " " + (*it).strName;
            }
        }
        mime += " <" + (*it).strAddr + ">";
    }
    if (m_listCcs.size() != 0)
    {
        mime += "\r\n";
    }

    /* ------------ 主题 ------------- */
    mime += "Subject: ";

    switch (hEncoding)
    {
    case MimePart::Base64:
        mime += "=?utf-8?B?" + QByteArray().append(m_strSubject).toBase64() + "?=";
        break;
    case MimePart::QuotedPrintable:
        mime += "=?utf-8?Q?" + QuotedPrintable::encode(QByteArray().append(m_strSubject)).replace(' ', "_").replace(':',"=3A") + "?=";
        break;
    default:
        mime += m_strSubject;
    }

    mime += "\r\n";
    mime += "MIME-Version: 1.0\r\n";
    //答复
    if (!mInReplyTo.isEmpty())
    {
        mime += "In-Reply-To: <" + mInReplyTo + ">\r\n";
        mime += "References: <" + mInReplyTo + ">\r\n";
    }
    mime += QString("Date: %1\r\n").arg(QDateTime::currentDateTime().toString(Qt::RFC2822Date));

    mime += content->toString();
    return mime;
}
