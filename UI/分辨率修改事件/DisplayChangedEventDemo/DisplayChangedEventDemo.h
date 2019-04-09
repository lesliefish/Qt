/** @file   DisplayChangedEventDemo.h
 *
 *  @brief  分辨率修改事件demo
 *  @note
 *  @author lesliefish
 *  @date   2019/04/09
 */
#pragma once

#include <QtWidgets/QWidget>
#include "ui_DisplayChangedEventDemo.h"

class DisplayChangedEventDemo : public QWidget
{
    Q_OBJECT

public:
    DisplayChangedEventDemo(QWidget *parent = Q_NULLPTR);

protected:
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);

private:
    Ui::DisplayChangedEventDemoClass ui;
};
