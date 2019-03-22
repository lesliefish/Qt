#include "StaticCallBackTest.h"
#include <thread>
#include <QDebug>


/****************************************!
* @brief  函数测试3秒回调一次数据
* @param  [in]  CALLBACK_FUNC pFuncCallBack  传入类的静态回调函数
* @param  [in]  void * data 
* @return void
****************************************/
void setCallBackFunc(CALLBACK_FUNC pFuncCallBack, void* data /*= nullptr*/)
{
    std::thread t([&pFuncCallBack]
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(3)); // 3秒回调一次
            std::string str = "callback test";
            pFuncCallBack(str.c_str(), nullptr); // 函数调用在此执行
        }
    });
    t.join();
}

//-------------------------以下为类StaticCallBackTest相关

// 静态变量初始化
StaticCallBackTest* StaticCallBackTest::s_this = nullptr;

StaticCallBackTest::StaticCallBackTest(QObject *parent)
    : QObject(parent)
{
    s_this = this; // 关键语句

    // 接收信号及数据  使用qDebug打印
    connect(this, &StaticCallBackTest::signalTest, [this](const std::string& str) 
    {
        qDebug() << QString::fromStdString(str);
    });
}

/****************************************!
 * @brief  静态回调函数
 * @param  [in]  const char * str  参数
 * @param  [in]  void * pData  
 * @return void CALLBACK  
 ****************************************/ 
void CALLBACK StaticCallBackTest::startFunc(const char *str, void *pData)
{
    // 使用静态指针发送信号
    emit s_this->signalTest(std::string(str));
}

/****************************************!
 * @brief  调用此函数传入回调
 * @return void  
 ****************************************/ 
void StaticCallBackTest::start()
{
    // 调用静态成员函数 startFunc
    setCallBackFunc(&startFunc);

    /*******
    注：
    也可以用doSomething(&startFunc, this);将this对象传递过去
    ********/
}