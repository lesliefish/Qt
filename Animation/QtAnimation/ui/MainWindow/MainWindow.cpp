#include "MainWindow.h"
#include <qpushbutton.h>
#include <qpropertyanimation.h>

namespace animation
{
    MainWindow::MainWindow(QWidget *parent)
        : QWidget(parent)
    {
        ui.setupUi(this);

        initUi();
        initConnection();
    }

    void MainWindow::initUi()
    {
        setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    }

    void MainWindow::initConnection()
    { 
        connect(ui.pushButton, &QPushButton::clicked, [&] 
        {
            static int resizeValue{100};
            resizeValue = -resizeValue;
            QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
            animation->setDuration(500);
            animation->setStartValue(QRect(pos().x(), pos().y(), width(), height()));
            //animation->setEndValue(QRect(pos().x() + resizeValue, pos().y() + resizeValue, width(), height()));
            animation->setEndValue(QRect(pos().x() + width(), pos().y(), 0, height()));
            animation->setEasingCurve(QEasingCurve::Linear);
            animation->start(QAbstractAnimation::DeleteWhenStopped);
        });

    }
}

