/********************************************************************************
** Form generated from reading UI file 'GraphicsViewTest.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICSVIEWTEST_H
#define UI_GRAPHICSVIEWTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphicsViewTestClass
{
public:
    QGridLayout *gridLayout;
    QGraphicsView *bottomGraphicsView;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *GraphicsViewTestClass)
    {
        if (GraphicsViewTestClass->objectName().isEmpty())
            GraphicsViewTestClass->setObjectName(QStringLiteral("GraphicsViewTestClass"));
        GraphicsViewTestClass->resize(600, 400);
        gridLayout = new QGridLayout(GraphicsViewTestClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bottomGraphicsView = new QGraphicsView(GraphicsViewTestClass);
        bottomGraphicsView->setObjectName(QStringLiteral("bottomGraphicsView"));

        gridLayout->addWidget(bottomGraphicsView, 0, 0, 1, 1);

        frame = new QFrame(GraphicsViewTestClass);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 25));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(271, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 4, 1, 1);


        gridLayout->addWidget(frame, 1, 0, 1, 1);


        retranslateUi(GraphicsViewTestClass);

        QMetaObject::connectSlotsByName(GraphicsViewTestClass);
    } // setupUi

    void retranslateUi(QWidget *GraphicsViewTestClass)
    {
        GraphicsViewTestClass->setWindowTitle(QApplication::translate("GraphicsViewTestClass", "GraphicsViewTest", 0));
        pushButton->setText(QApplication::translate("GraphicsViewTestClass", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("GraphicsViewTestClass", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("GraphicsViewTestClass", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("GraphicsViewTestClass", "zoomin", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphicsViewTestClass: public Ui_GraphicsViewTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICSVIEWTEST_H
