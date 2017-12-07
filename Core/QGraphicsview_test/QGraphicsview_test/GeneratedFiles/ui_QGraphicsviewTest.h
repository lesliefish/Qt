/********************************************************************************
** Form generated from reading UI file 'QGraphicsviewTest.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGRAPHICSVIEWTEST_H
#define UI_QGRAPHICSVIEWTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGraphicsviewTestClass
{
public:

    void setupUi(QWidget *QGraphicsviewTestClass)
    {
        if (QGraphicsviewTestClass->objectName().isEmpty())
            QGraphicsviewTestClass->setObjectName(QStringLiteral("QGraphicsviewTestClass"));
        QGraphicsviewTestClass->resize(600, 400);

        retranslateUi(QGraphicsviewTestClass);

        QMetaObject::connectSlotsByName(QGraphicsviewTestClass);
    } // setupUi

    void retranslateUi(QWidget *QGraphicsviewTestClass)
    {
        QGraphicsviewTestClass->setWindowTitle(QApplication::translate("QGraphicsviewTestClass", "QGraphicsviewTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QGraphicsviewTestClass: public Ui_QGraphicsviewTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGRAPHICSVIEWTEST_H
