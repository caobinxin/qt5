/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QPushButton *pushBtnReadCurrentDataAndTime;
    QLabel *label_4;
    QLabel *labelTime;
    QTimeEdit *timeEdit;
    QPushButton *pushBtnSettingTime;
    QLabel *labelDate;
    QDateEdit *dateEdit;
    QPushButton *pushBtnSettingDate;
    QLabel *labelDateTime;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pushBtnSettingDateTime;
    QLineEdit *lineEditTime;
    QLineEdit *lineEditDate;
    QLineEdit *lineEditDateTime;
    QGridLayout *gridLayout_2;
    QLabel *labelSelectDate;
    QCalendarWidget *calendarWidget;
    QPushButton *pushBtnClose;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QPushButton *pushBtnTimerStart;
    QPushButton *pushBtnTimerStop;
    QLabel *labelOutTime;
    QLabel *label_11;
    QSpinBox *spinBoxTimerCycle;
    QPushButton *pushBtnSettingCycle;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *lcdNumMinute;
    QLCDNumber *lcdNumSecond;
    QLCDNumber *lcdNumMillisecond;
    QProgressBar *progressBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1000, 382);
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushBtnReadCurrentDataAndTime = new QPushButton(Widget);
        pushBtnReadCurrentDataAndTime->setObjectName(QString::fromUtf8("pushBtnReadCurrentDataAndTime"));
        pushBtnReadCurrentDataAndTime->setAutoDefault(true);

        gridLayout->addWidget(pushBtnReadCurrentDataAndTime, 0, 0, 1, 2);

        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        labelTime = new QLabel(Widget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));

        gridLayout->addWidget(labelTime, 1, 0, 1, 1);

        timeEdit = new QTimeEdit(Widget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        gridLayout->addWidget(timeEdit, 1, 1, 1, 1);

        pushBtnSettingTime = new QPushButton(Widget);
        pushBtnSettingTime->setObjectName(QString::fromUtf8("pushBtnSettingTime"));

        gridLayout->addWidget(pushBtnSettingTime, 1, 3, 1, 1);

        labelDate = new QLabel(Widget);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));

        gridLayout->addWidget(labelDate, 2, 0, 1, 1);

        dateEdit = new QDateEdit(Widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout->addWidget(dateEdit, 2, 1, 1, 1);

        pushBtnSettingDate = new QPushButton(Widget);
        pushBtnSettingDate->setObjectName(QString::fromUtf8("pushBtnSettingDate"));

        gridLayout->addWidget(pushBtnSettingDate, 2, 3, 1, 1);

        labelDateTime = new QLabel(Widget);
        labelDateTime->setObjectName(QString::fromUtf8("labelDateTime"));

        gridLayout->addWidget(labelDateTime, 3, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(Widget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));

        gridLayout->addWidget(dateTimeEdit, 3, 1, 1, 1);

        pushBtnSettingDateTime = new QPushButton(Widget);
        pushBtnSettingDateTime->setObjectName(QString::fromUtf8("pushBtnSettingDateTime"));

        gridLayout->addWidget(pushBtnSettingDateTime, 3, 3, 1, 1);

        lineEditTime = new QLineEdit(Widget);
        lineEditTime->setObjectName(QString::fromUtf8("lineEditTime"));

        gridLayout->addWidget(lineEditTime, 1, 2, 1, 1);

        lineEditDate = new QLineEdit(Widget);
        lineEditDate->setObjectName(QString::fromUtf8("lineEditDate"));

        gridLayout->addWidget(lineEditDate, 2, 2, 1, 1);

        lineEditDateTime = new QLineEdit(Widget);
        lineEditDateTime->setObjectName(QString::fromUtf8("lineEditDateTime"));

        gridLayout->addWidget(lineEditDateTime, 3, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelSelectDate = new QLabel(Widget);
        labelSelectDate->setObjectName(QString::fromUtf8("labelSelectDate"));

        gridLayout_2->addWidget(labelSelectDate, 0, 0, 1, 1);

        calendarWidget = new QCalendarWidget(Widget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout_2->addWidget(calendarWidget, 1, 0, 1, 1);

        pushBtnClose = new QPushButton(Widget);
        pushBtnClose->setObjectName(QString::fromUtf8("pushBtnClose"));

        gridLayout_2->addWidget(pushBtnClose, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 1, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        pushBtnTimerStart = new QPushButton(Widget);
        pushBtnTimerStart->setObjectName(QString::fromUtf8("pushBtnTimerStart"));

        gridLayout_3->addWidget(pushBtnTimerStart, 1, 0, 1, 1);

        pushBtnTimerStop = new QPushButton(Widget);
        pushBtnTimerStop->setObjectName(QString::fromUtf8("pushBtnTimerStop"));

        gridLayout_3->addWidget(pushBtnTimerStop, 1, 1, 1, 1);

        labelOutTime = new QLabel(Widget);
        labelOutTime->setObjectName(QString::fromUtf8("labelOutTime"));

        gridLayout_3->addWidget(labelOutTime, 1, 2, 1, 1);

        label_11 = new QLabel(Widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 2, 0, 1, 1);

        spinBoxTimerCycle = new QSpinBox(Widget);
        spinBoxTimerCycle->setObjectName(QString::fromUtf8("spinBoxTimerCycle"));
        spinBoxTimerCycle->setMinimum(500);
        spinBoxTimerCycle->setMaximum(10000);
        spinBoxTimerCycle->setSingleStep(500);
        spinBoxTimerCycle->setStepType(QAbstractSpinBox::DefaultStepType);

        gridLayout_3->addWidget(spinBoxTimerCycle, 2, 1, 1, 1);

        pushBtnSettingCycle = new QPushButton(Widget);
        pushBtnSettingCycle->setObjectName(QString::fromUtf8("pushBtnSettingCycle"));

        gridLayout_3->addWidget(pushBtnSettingCycle, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lcdNumMinute = new QLCDNumber(Widget);
        lcdNumMinute->setObjectName(QString::fromUtf8("lcdNumMinute"));

        horizontalLayout->addWidget(lcdNumMinute);

        lcdNumSecond = new QLCDNumber(Widget);
        lcdNumSecond->setObjectName(QString::fromUtf8("lcdNumSecond"));

        horizontalLayout->addWidget(lcdNumSecond);

        lcdNumMillisecond = new QLCDNumber(Widget);
        lcdNumMillisecond->setObjectName(QString::fromUtf8("lcdNumMillisecond"));

        horizontalLayout->addWidget(lcdNumMillisecond);


        verticalLayout->addLayout(horizontalLayout);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        gridLayout_4->addLayout(verticalLayout, 1, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        pushBtnReadCurrentDataAndTime->setText(QApplication::translate("Widget", "\350\257\273\345\217\226\345\275\223\345\211\215\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        label_4->setText(QApplication::translate("Widget", "\345\255\227\347\254\246\344\270\262\346\230\276\347\244\272", nullptr));
        labelTime->setText(QApplication::translate("Widget", "\346\227\266\351\227\264", nullptr));
        pushBtnSettingTime->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\346\227\266\351\227\264", nullptr));
        labelDate->setText(QApplication::translate("Widget", "\346\227\245\346\234\237", nullptr));
        pushBtnSettingDate->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\346\227\245\346\234\237", nullptr));
        labelDateTime->setText(QApplication::translate("Widget", "\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        pushBtnSettingDateTime->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\346\227\245\346\234\237\346\227\266\351\227\264", nullptr));
        labelSelectDate->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\347\232\204\346\227\245\346\234\237", nullptr));
        pushBtnClose->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", nullptr));
        label_9->setText(QApplication::translate("Widget", "\345\256\232\346\227\266\345\231\250", nullptr));
        pushBtnTimerStart->setText(QApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        pushBtnTimerStop->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        labelOutTime->setText(QApplication::translate("Widget", "\346\265\201\345\244\261\346\227\266\351\227\264\357\274\232", nullptr));
        label_11->setText(QApplication::translate("Widget", "\345\256\232\346\227\266\345\221\250\346\234\237", nullptr));
        spinBoxTimerCycle->setSuffix(QApplication::translate("Widget", " ms", nullptr));
        spinBoxTimerCycle->setPrefix(QApplication::translate("Widget", "0", nullptr));
        pushBtnSettingCycle->setText(QApplication::translate("Widget", "\350\256\276\347\275\256\345\221\250\346\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
