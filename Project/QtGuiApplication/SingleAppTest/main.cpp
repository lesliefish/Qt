#include "SingleAppTest.h"
#include <QtWidgets/QApplication>
#include <QDir>
#include <QLockFile>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 本测试程序id取名为SingleAppTest
    QString path = QDir::temp().absoluteFilePath("SingleAppTest.lock");
    // path = C:/Users/yu/AppData/Local/Temp/SingleAppTest.lock  
    QLockFile lockFile(path);

    bool isLock = lockFile.isLocked();
    // bool QLockFile::tryLock(int timeout = 0)
    // tryLock尝试创建锁定文件。此函数如果获得锁，则返回true; 否则返回false。
    // 如果另一个进程（或另一个线程）已经创建了锁文件，则此函数将最多等待timeout毫秒
    if (!lockFile.tryLock(100)) 
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("The application is already running.\n"
            "Allowed to run only one instance of the application.");
        msgBox.exec();
        return 1;
    }

    SingleAppTest w;
    w.setFixedSize(250, 150);
    w.show();
    return a.exec();
}
