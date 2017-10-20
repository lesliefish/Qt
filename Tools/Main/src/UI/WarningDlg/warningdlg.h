#ifndef WARNINGDLG_H
#define WARNINGDLG_H

#include <QDialog>

namespace Ui {
class WarningDlg;
}

class WarningDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WarningDlg(QWidget *parent = 0);
    ~WarningDlg();

private:
    Ui::WarningDlg *ui;
    void Exit();

signals:
    void SigExit();
};

#endif // WARNINGDLG_H
