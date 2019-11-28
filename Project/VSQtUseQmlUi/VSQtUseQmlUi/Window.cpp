#include "Window.h"
#include <QQuickItem>
#include <QPushButton>

namespace
{
    QObject* pSwipeView = nullptr;
    QObject* pRedPage = nullptr;
    QObject* pGreenPage = nullptr;
}

Window::Window(QWidget *parent)
    : QQuickWidget(parent)
{
    setWindowTitle(QStringLiteral("Qt程序使用Qml界面"));
    // 设置qml界面源
    setSource(QUrl("qrc:/App/SwipeViewQml.qml"));
    // qml界面大小跟随父界面大小变化
    setResizeMode(QQuickWidget::SizeRootObjectToView);
    // 接受触摸事件 不设置的话win7触摸屏触摸无效
    setAttribute(Qt::WA_AcceptTouchEvents);

    // 获取Qml界面redPage对象/ / 根据对象名objectName查找对象
    pSwipeView = rootObject()->findChild<QObject*>("swipeView");
    pRedPage = rootObject()->findChild<QObject*>("redPage");
    pGreenPage = rootObject()->findChild<QObject*>("greenPage");

    Q_ASSERT(pSwipeView != nullptr && pRedPage != nullptr && pGreenPage != nullptr);

    // 绑定qml界面上的信号
    connect(pSwipeView, SIGNAL(signalPageChanged(int)), this, SLOT(onPageChanged(int))); // 页面切换事件
    connect(pRedPage, SIGNAL(signalClicked(const QString&)), this, SLOT(onQmlClicked(const QString&)));//点击事件
    connect(pGreenPage, SIGNAL(signalClicked(const QString&)), this, SLOT(onQmlClicked(const QString&)));//点击事件

    // 改变qml项对象属性值测试：// 添加一个按钮改变redPage颜色
    m_pChangeColorBtn = new QPushButton(this); 
    m_pChangeColorBtn->setFixedSize(200, 60);
    m_pChangeColorBtn->setStyleSheet("border:1px solid #888888;");
    m_pChangeColorBtn->setText(QStringLiteral("改变成浅蓝色"));

    connect(m_pChangeColorBtn, &QPushButton::clicked, [&] 
    {
        pRedPage->setProperty("color", "lightblue"); // 直接设置属性值
    });

    // 调用qml项对象方法
    m_pQmlMethodBtn = new QPushButton(this); // 调用qml对象方法
    m_pQmlMethodBtn->setFixedSize(200, 60);
    m_pQmlMethodBtn->move(230, 0);
    m_pQmlMethodBtn->setStyleSheet("border:1px solid #888888;");
    m_pQmlMethodBtn->setText(QStringLiteral("调用qml项内部方法改成黄色"));

    connect(m_pQmlMethodBtn, &QPushButton::clicked, [&]
    {
        QMetaObject::invokeMethod(pRedPage, "setTheColor", Q_ARG(QVariant, "yellow"));
    });
}

/*
 * @func   Window::onQmlClicked 
 * @brief  收到点击事件后更改窗口标题
 * @param  [in]  const QString & strObjectName  qml信号参数传递的是对象名称
 * @return void  
 */ 
void Window::onQmlClicked(const QString& strObjectName)
{
    if (strObjectName == "redPage")
    {
        setWindowTitle(QStringLiteral("收到redPage的点击事件"));
    }
    else if (strObjectName == "greenPage")
    {
        setWindowTitle(QStringLiteral("收到greenPage的点击事件"));
    }
}

/*
 * @func   Window::onPageChanged 
 * @brief  页面切换
 * @param  [in]  int index  swipeView页面index
 * @return void  
 */ 
void Window::onPageChanged(int index)
{
    // 到第二页就隐藏QPushButton控件
    m_pChangeColorBtn->setVisible(0 == index);
    m_pQmlMethodBtn->setVisible(0 == index);
}
