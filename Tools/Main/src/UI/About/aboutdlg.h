/** @file    aboutdlg.h
* @note
* @brief   关于窗口
*
* @author  lesliefish
* @date    2017年10月21日
*
* @note    detailed functional description of this document and comments
* @note    History
*
* @warning warning message related to this document
*/

#ifndef ABOUTDLG_H
#define ABOUTDLG_H

#include <QDialog>

namespace Ui {
class AboutDlg;
}

class AboutDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDlg(QWidget *parent = 0);
    ~AboutDlg();

private:
    Ui::AboutDlg *ui;
protected:
    //实现鼠标对无边框窗口拖动
    QPoint m_pointMove;
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // ABOUTDLG_H
