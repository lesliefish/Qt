#include "WebTest.h"
#include <QFile>
#include <QCoreApplication>

WebTest::WebTest(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    initUi();
    initConncetion();
}

/** @fn     WebTest::initUi
 *  @brief  界面初始化
 *  @return void 
 */
void WebTest::initUi()
{
    m_pWebView = ui.webEngineView;
    m_pWebChannel = new QWebChannel(this);
    loadHtml();

    // 注册一个qtui对象  html端通过此名称向qt发送消息
    m_pWebChannel->registerObject(QString("qtui"), this);
    m_pWebView->page()->setWebChannel(m_pWebChannel);
}

/** @fn     WebTest::initConncetion
 *  @brief  初始化信号槽函数
 *  @return void 
 */
void WebTest::initConncetion()
{
    // 调用js
    connect(ui.callJSBtn, &QPushButton::clicked, [&]() 
    {
        QString jsStr = QString("addCircle()");
        m_pWebView->page()->runJavaScript(jsStr);
    });

    // 获取js返回值
    connect(ui.getJsRetBtn, &QPushButton::clicked, [&]() 
    {
        auto str = getJsRetString();
        ui.label->setText(str);
    });
}

/** @fn     WebTest::loadHtml
 *  @brief  加载地图
 *  @return void 
 */
void WebTest::loadHtml()
{
    QString htmlPath = QCoreApplication::applicationDirPath() + "/BMap.html";

    QFile file(htmlPath);
    if (!file.exists())
    {
        return;
    }

    m_pWebView->load(QUrl("file:///" + htmlPath));
}

/** @fn     WebTest::getJsRetString
 *  @brief  获取web端返回值
 *  @return QString 
 */
QString WebTest::getJsRetString()
{
    QEventLoop loop;
    QString jsStr = "getInfo();";

    QString retStr{}; // 返回值
    // 通过loop循环等到回调上来数据再继续
    m_pWebView->page()->runJavaScript(jsStr, [&](const QVariant &v)
    {
        retStr = v.toString();
        loop.quit();
    });
    loop.exec();

    return retStr;
}

/** @fn     WebTest::recieveJsMessage
 *  @brief  接收来自webhtml的消息
 *  @param  const QString & jsMsg web端通知的消息
 *  @return void 
 */
void WebTest::recieveJsMessage(const QString& jsMsg)
{
    ui.label->setText(jsMsg);
}
