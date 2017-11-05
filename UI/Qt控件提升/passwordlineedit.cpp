#include "passwordlineedit.h"

PasswordLineEdit::PasswordLineEdit(QWidget* parent):
    QLineEdit(parent)
{
    this->setMaxLength(8);
    this->setEchoMode(QLineEdit::Password);//设置为密码类型
}
