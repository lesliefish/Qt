#include "printtask.h"
#include <QThread>
#include <iostream>
using std::cout;
using std::endl;

PrintTask::PrintTask()
{
}

PrintTask::~PrintTask()
{

}


void PrintTask::run()
{
    cout << "PrintTask run 被调用，调用线程ID为：" << QThread::currentThread() << endl;
}
