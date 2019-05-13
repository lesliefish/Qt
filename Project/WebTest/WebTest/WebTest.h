/** @file   WebTest.h
  * @note   
  * 
  * @brief  Qt 使用web引擎开发Demo
  * @author lesliefish
  * @date   2018/11/30
  */
#pragma once

#include <QtWidgets/QWidget>
#include <QWebEngineView>
#include <QWebChannel>
#include "ui_WebTest.h"

class WebTest : public QWidget
{
    Q_OBJECT

public:
    WebTest(QWidget *parent = Q_NULLPTR);

private:
    void initUi();
    void initConncetion();
    // 加载html文件
    void loadHtml();
    // 获取js函数返回值
    QString getJsRetString();

public slots:
    void recieveJsMessage(const QString& jsMsg);

private:
    Ui::WebTestClass ui;

    QWebEngineView *m_pWebView{ nullptr };
    QWebChannel* m_pWebChannel{ nullptr };
};
