#include <QCoreApplication>
#include <QThreadPool>
#include "printtask.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThreadPool pool;
    pool.setMaxThreadCount(3);

    for(int i = 0; i < 20; i++)
    {
        pool.start(new PrintTask());
    }

    return a.exec();
}
/*
PrintTask run 被调用，调用线程ID为：00533678
PrintTask run 被调用，调用线程ID为：00533678
PrintTask run 被调用，调用线程ID为：004F3868
PrintTask run 被调用，调用线程ID为：004F3848
PrintTask run 被调用，调用线程ID为：00533678
PrintTask run 被调用，调用线程ID为：00533678
PrintTask run 被调用，调用线程ID为：004F3848
PrintTask run 被调用，调用线程ID为：004F3868
PrintTask run 被调用，调用线程ID为：00533678
PrintTask run 被调用，调用线程ID为：00533678
PrintTask run 被调用，调用线程ID为：004F3848
PrintTask run 被调用，调用线程ID为：00533678
PrintTask run 被调用，调用线程ID为：004F3868
PrintTask run 被调用，调用线程ID为：004F3848
PrintTask run 被调用，调用线程ID为：00533678
PrintTask run 被调用，调用线程ID为：004F3868
PrintTask run 被调用，调用线程ID为：004F3848
PrintTask run 被调用，调用线程ID为：004F3868
...
*/
