#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "WarningDlg/warningdlg.h"
#include "FramelessWidget/framelesswidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public FramelessWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    void InitUI();
    void InitConnect();
    WarningDlg m_warningDlg;

};

#endif // MAINWINDOW_H
