#include "ThreadTest.h"
#include <thread>

ThreadTest::ThreadTest(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    // 绑定信号  点击按钮后执行test函数
    connect(ui.pushButton, &QPushButton::clicked, [&]
    {
        test(); 
    });
}

/** @fn     ThreadTest::test
 *  @brief  测试函数  点击界面按钮后执行
 *  @return void 
 */
void ThreadTest::test()
{
    // 假设需要知道线程的执行结果runResult
    bool runResult{ false };

    // 定义一个loop对象
    QEventLoop loop;
    // 绑定信号  在loop收到界面的signalRunOver信号后，退出循环
    connect(this, &ThreadTest::signalRunOver, &loop, &QEventLoop::quit);
    
    // 声明一个线程处理任务  传入匿名函数  在声明后直接开启一个线程执行匿名函数体
    std::thread testThread([&]
    {
        // runResult = 连接网络 、拷贝文件、等等耗时操作  实际执行的任务放在这个位置执行

        runResult = true;
        // 执行完成后 发出信号  告知线程执行结束
        emit signalRunOver();
    });
    // 分离线程  让其自生自灭(销毁线程)
    testThread.detach();

    // 在此处执行循环  等待线程的执行结果
    loop.exec();

    // 以上线程执行完成后执行以下代码
    if (!runResult)
    {
        // 处理结果  整个过程界面不会卡死
    }
}
