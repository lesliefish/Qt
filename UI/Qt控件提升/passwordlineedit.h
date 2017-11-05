#ifndef PASSWORDLINEEDIT_H
#define PASSWORDLINEEDIT_H
#include <QLineEdit>

class PasswordLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    PasswordLineEdit(QWidget* parent = 0);
};

#endif // PASSWORDLINEEDIT_H
