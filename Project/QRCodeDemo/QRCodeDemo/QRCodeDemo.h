#pragma once

#include <QtWidgets/QWidget>
#include "ui_QRCodeDemo.h"

class QRCodeDemo : public QWidget
{
    Q_OBJECT

public:
    QRCodeDemo(QWidget *parent = Q_NULLPTR);

public:
    void setCodeString(const QString& strCodeString);

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::QRCodeDemoClass ui;

    QString m_strCodeString;
};
