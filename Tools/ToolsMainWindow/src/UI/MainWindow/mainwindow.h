#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "WarningDlg/warningdlg.h"
#include "FramelessWidget/framelesswidget.h"
#include "About/aboutdlg.h"

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
    WarningDlg m_exitDlg;
    AboutDlg m_aboutDlg;

};

#endif // MAINWINDOW_H
