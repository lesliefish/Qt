#include "DisplayChangedEventDemo.h"
#include "windows.h"
#include <QDebug>

DisplayChangedEventDemo::DisplayChangedEventDemo(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

bool DisplayChangedEventDemo::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = reinterpret_cast<MSG*>(message);
    int msgType = msg->message;
    switch (msgType)
    {
    case WM_DISPLAYCHANGE:
    {
        // 分辨率修改事件 获取到最新的分辨率配置
        int width = GetSystemMetrics(SM_CXSCREEN);
        int height = GetSystemMetrics(SM_CYSCREEN);

        qDebug() << "current system size: " << width << " " << height;
    }
    break;
    default:
        break;
    }

    return QWidget::nativeEvent(eventType, message, result);
}

/*
分辨率切换时的输出：
current system size:  1600   900
current system size:  1280   720
current system size:  1920   1080
*/