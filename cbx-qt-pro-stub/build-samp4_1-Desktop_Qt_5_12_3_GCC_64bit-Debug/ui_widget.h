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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labNumber;
    QLineEdit *lineEditNumber;
    QLabel *labUPrice;
    QLineEdit *lineEditUPrice;
    QSpacerItem *horizontalSpacer;
    QPushButton *pButtonCount;
    QLabel *labTPrice;
    QLineEdit *lineEditTPrice;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QLabel *labTen;
    QLineEdit *lineEditTen;
    QLabel *labelHex;
    QLineEdit *lineEditHex;
    QPushButton *pushButtonTransformation;
    QLabel *labTwo;
    QLineEdit *lineEditTwo;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(300, 179);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labNumber = new QLabel(Widget);
        labNumber->setObjectName(QString::fromUtf8("labNumber"));

        gridLayout->addWidget(labNumber, 0, 0, 1, 1);

        lineEditNumber = new QLineEdit(Widget);
        lineEditNumber->setObjectName(QString::fromUtf8("lineEditNumber"));

        gridLayout->addWidget(lineEditNumber, 0, 1, 1, 1);

        labUPrice = new QLabel(Widget);
        labUPrice->setObjectName(QString::fromUtf8("labUPrice"));

        gridLayout->addWidget(labUPrice, 0, 2, 1, 1);

        lineEditUPrice = new QLineEdit(Widget);
        lineEditUPrice->setObjectName(QString::fromUtf8("lineEditUPrice"));

        gridLayout->addWidget(lineEditUPrice, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        pButtonCount = new QPushButton(Widget);
        pButtonCount->setObjectName(QString::fromUtf8("pButtonCount"));

        gridLayout->addWidget(pButtonCount, 1, 1, 1, 1);

        labTPrice = new QLabel(Widget);
        labTPrice->setObjectName(QString::fromUtf8("labTPrice"));

        gridLayout->addWidget(labTPrice, 1, 2, 1, 1);

        lineEditTPrice = new QLineEdit(Widget);
        lineEditTPrice->setObjectName(QString::fromUtf8("lineEditTPrice"));

        gridLayout->addWidget(lineEditTPrice, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labTen = new QLabel(Widget);
        labTen->setObjectName(QString::fromUtf8("labTen"));

        gridLayout_2->addWidget(labTen, 0, 0, 1, 1);

        lineEditTen = new QLineEdit(Widget);
        lineEditTen->setObjectName(QString::fromUtf8("lineEditTen"));

        gridLayout_2->addWidget(lineEditTen, 0, 1, 1, 1);

        labelHex = new QLabel(Widget);
        labelHex->setObjectName(QString::fromUtf8("labelHex"));

        gridLayout_2->addWidget(labelHex, 1, 0, 1, 1);

        lineEditHex = new QLineEdit(Widget);
        lineEditHex->setObjectName(QString::fromUtf8("lineEditHex"));

        gridLayout_2->addWidget(lineEditHex, 1, 1, 1, 1);

        pushButtonTransformation = new QPushButton(Widget);
        pushButtonTransformation->setObjectName(QString::fromUtf8("pushButtonTransformation"));

        gridLayout_2->addWidget(pushButtonTransformation, 1, 2, 1, 1);

        labTwo = new QLabel(Widget);
        labTwo->setObjectName(QString::fromUtf8("labTwo"));

        gridLayout_2->addWidget(labTwo, 2, 0, 1, 1);

        lineEditTwo = new QLineEdit(Widget);
        lineEditTwo->setObjectName(QString::fromUtf8("lineEditTwo"));

        gridLayout_2->addWidget(lineEditTwo, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        labNumber->setText(QApplication::translate("Widget", "Number", nullptr));
        labUPrice->setText(QApplication::translate("Widget", "UnitPrice", nullptr));
        pButtonCount->setText(QApplication::translate("Widget", "Count", nullptr));
        labTPrice->setText(QApplication::translate("Widget", "TotalPrice", nullptr));
        labTen->setText(QApplication::translate("Widget", "10:", nullptr));
        labelHex->setText(QApplication::translate("Widget", "16:", nullptr));
        pushButtonTransformation->setText(QApplication::translate("Widget", "Transformation", nullptr));
        labTwo->setText(QApplication::translate("Widget", "2:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
