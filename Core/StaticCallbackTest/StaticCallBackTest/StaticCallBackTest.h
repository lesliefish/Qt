/** @file   StaticCallBackTest.h
 *  @brief  静态回调函数访问类成员变量测试demo
 *  @note
 *  @author lesliefish
 *  @date   2019/03/22
 */
#pragma once

#include <QObject>

#if defined _WIN32 || defined _WIN64
#define CALLBACK __stdcall
#elif defined __linux__ || defined __APPLE__
#define CALLBACK  
#endif

// 定义回调函数类型
typedef void (CALLBACK *CALLBACK_FUNC)(const char* str, void *pUserData);

// 回调传入接口
void setCallBackFunc(CALLBACK_FUNC pFuncCallBack, void* data = nullptr);

class StaticCallBackTest : public QObject
{
    Q_OBJECT

public:
    StaticCallBackTest(QObject *parent = Q_NULLPTR);

public:
    // 静态类指针
    static StaticCallBackTest* s_this;
    // 静态函数 供doSomething()调用
    static void CALLBACK startFunc(const char *str, void *pData);

public:
    // 启动 
    void start();

signals:
    // 对象信号
    void signalTest(const std::string& str);
};
