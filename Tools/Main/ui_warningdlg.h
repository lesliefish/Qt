/********************************************************************************
** Form generated from reading UI file 'warningdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNINGDLG_H
#define UI_WARNINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarningDlg
{
public:
    QGridLayout *gridLayout_3;
    QWidget *m_warningTitle;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *m_titleTextBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_closeBtn;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *m_OKBtn;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *m_cancleBtn;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *WarningDlg)
    {
        if (WarningDlg->objectName().isEmpty())
            WarningDlg->setObjectName(QStringLiteral("WarningDlg"));
        WarningDlg->resize(320, 160);
        WarningDlg->setMinimumSize(QSize(320, 160));
        WarningDlg->setMaximumSize(QSize(320, 160));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        WarningDlg->setFont(font);
        WarningDlg->setStyleSheet(QLatin1String("QWidget#WarningDlg\n"
"{\n"
"background:#EEEEEE;\n"
"border: 1px solid #999999;\n"
"border-radius: 1px;\n"
"}"));
        gridLayout_3 = new QGridLayout(WarningDlg);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        m_warningTitle = new QWidget(WarningDlg);
        m_warningTitle->setObjectName(QStringLiteral("m_warningTitle"));
        m_warningTitle->setMinimumSize(QSize(30, 28));
        m_warningTitle->setMaximumSize(QSize(500, 28));
        m_warningTitle->setStyleSheet(QLatin1String("QWidget#m_warningTitle\n"
"{\n"
"background:transparent;\n"
"border:1px solid rgb(120, 120, 120);\n"
"border-radius: 1px;\n"
"}"));
        gridLayout = new QGridLayout(m_warningTitle);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(35, 28, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        m_titleTextBtn = new QPushButton(m_warningTitle);
        m_titleTextBtn->setObjectName(QStringLiteral("m_titleTextBtn"));
        m_titleTextBtn->setMinimumSize(QSize(40, 28));
        m_titleTextBtn->setMaximumSize(QSize(16777215, 28));
        m_titleTextBtn->setStyleSheet(QLatin1String("QPushButton#m_titleTextBtn\n"
"{\n"
"color: #111111;\n"
"border-radius:1px;\n"
"background-repeat:no-repeat;\n"
"background-position:center;\n"
"}\n"
"QPushButton#m_titleTextBtn:hover\n"
"{\n"
"\n"
"}"));

        horizontalLayout->addWidget(m_titleTextBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_closeBtn = new QPushButton(m_warningTitle);
        m_closeBtn->setObjectName(QStringLiteral("m_closeBtn"));
        m_closeBtn->setMinimumSize(QSize(35, 28));
        m_closeBtn->setMaximumSize(QSize(35, 28));
        m_closeBtn->setStyleSheet(QLatin1String("QPushButton#m_closeBtn\n"
"{\n"
"color: #999999;\n"
"border-radius:1px;\n"
"font: bold 14px;\n"
"padding: 6px;\n"
"background-image:url(:/Title/Button/images/close.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center;\n"
"}\n"
"QPushButton#m_closeBtn:hover\n"
"{\n"
"color:white;\n"
"background:red;\n"
"background-image:url(:/Title/Button/images/close.png);\n"
"background-repeat:no-repeat;\n"
"background-position:center;\n"
"}"));

        horizontalLayout->addWidget(m_closeBtn);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(m_warningTitle, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label = new QLabel(WarningDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout_3->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 12, -1, -1);
        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 3, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_OKBtn = new QPushButton(WarningDlg);
        m_OKBtn->setObjectName(QStringLiteral("m_OKBtn"));
        m_OKBtn->setMinimumSize(QSize(75, 25));
        m_OKBtn->setMaximumSize(QSize(75, 25));
        m_OKBtn->setStyleSheet(QLatin1String("QPushButton#m_OKBtn\n"
"{\n"
"background: red;\n"
"color:white;\n"
"border-radius:1px;\n"
"font: 12px;\n"
"padding: 6px;\n"
"background-repeat:no-repeat;\n"
"background-position:center;\n"
"}\n"
"QPushButton#m_OKBtn:hover\n"
"{\n"
"\n"
"}"));

        horizontalLayout_2->addWidget(m_OKBtn);

        horizontalSpacer_8 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        m_cancleBtn = new QPushButton(WarningDlg);
        m_cancleBtn->setObjectName(QStringLiteral("m_cancleBtn"));
        m_cancleBtn->setMinimumSize(QSize(75, 25));
        m_cancleBtn->setMaximumSize(QSize(75, 25));
        m_cancleBtn->setStyleSheet(QLatin1String("QPushButton#m_cancleBtn\n"
"{\n"
"background: #999999;\n"
"color:white;\n"
"border-radius:1px;\n"
"font: 12px;\n"
"padding: 6px;\n"
"background-repeat:no-repeat;\n"
"background-position:center;\n"
"}\n"
"QPushButton#m_cancleBtn:hover\n"
"{\n"
"\n"
"}"));

        horizontalLayout_2->addWidget(m_cancleBtn);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 2, 2);

        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 32, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(WarningDlg);

        QMetaObject::connectSlotsByName(WarningDlg);
    } // setupUi

    void retranslateUi(QDialog *WarningDlg)
    {
        WarningDlg->setWindowTitle(QApplication::translate("WarningDlg", "Dialog", Q_NULLPTR));
        m_titleTextBtn->setText(QApplication::translate("WarningDlg", "Warning", Q_NULLPTR));
        m_closeBtn->setText(QApplication::translate("WarningDlg", "\303\227", Q_NULLPTR));
        label->setText(QApplication::translate("WarningDlg", "Are you sure to quit?", Q_NULLPTR));
        m_OKBtn->setText(QApplication::translate("WarningDlg", "OK", Q_NULLPTR));
        m_cancleBtn->setText(QApplication::translate("WarningDlg", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WarningDlg: public Ui_WarningDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNINGDLG_H
