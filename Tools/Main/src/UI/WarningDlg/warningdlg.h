/** @file    aboutdlg.h
* @note
* @brief   退出提示窗口
*
* @author  lesliefish
* @date    2017年10月19日
*
* @note    detailed functional description of this document and comments
* @note    History
*
* @warning warning message related to this document
*/

#ifndef WARNINGDLG_H
#define WARNINGDLG_H

#include <QDialog>
#include <QMouseEvent>

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
protected:
    //实现鼠标对无边框窗口拖动
    QPoint m_pointMove;
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
signals:
    void SigExit();
};

#endif // WARNINGDLG_H
