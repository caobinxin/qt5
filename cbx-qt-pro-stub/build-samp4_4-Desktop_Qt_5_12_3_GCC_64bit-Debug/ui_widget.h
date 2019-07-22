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
#include <QtWidgets/QDial>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *labelRed;
    QSlider *horizontalSliderRed;
    QTextEdit *textEdit;
    QLabel *labelGreen;
    QSlider *horizontalSliderGreen;
    QLabel *labelBlue;
    QSlider *horizontalSliderBlue;
    QLabel *labelAlpha;
    QSlider *horizontalSliderAlpha;
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider_5;
    QScrollBar *horizontalScrollBar;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout;
    QDial *dial;
    QLCDNumber *lcdNumber;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonDec;
    QRadioButton *radioButtonBin;
    QRadioButton *radioButtonOct;
    QRadioButton *radioButtonHex;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *verticalSlider;
    QScrollBar *verticalScrollBar;
    QProgressBar *progressBar_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(589, 371);
        horizontalLayout_4 = new QHBoxLayout(Widget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelRed = new QLabel(Widget);
        labelRed->setObjectName(QString::fromUtf8("labelRed"));

        gridLayout->addWidget(labelRed, 0, 0, 1, 1);

        horizontalSliderRed = new QSlider(Widget);
        horizontalSliderRed->setObjectName(QString::fromUtf8("horizontalSliderRed"));
        horizontalSliderRed->setMaximum(255);
        horizontalSliderRed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderRed, 0, 1, 1, 1);

        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 2, 4, 1);

        labelGreen = new QLabel(Widget);
        labelGreen->setObjectName(QString::fromUtf8("labelGreen"));

        gridLayout->addWidget(labelGreen, 1, 0, 1, 1);

        horizontalSliderGreen = new QSlider(Widget);
        horizontalSliderGreen->setObjectName(QString::fromUtf8("horizontalSliderGreen"));
        horizontalSliderGreen->setMaximum(255);
        horizontalSliderGreen->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderGreen, 1, 1, 1, 1);

        labelBlue = new QLabel(Widget);
        labelBlue->setObjectName(QString::fromUtf8("labelBlue"));

        gridLayout->addWidget(labelBlue, 2, 0, 1, 1);

        horizontalSliderBlue = new QSlider(Widget);
        horizontalSliderBlue->setObjectName(QString::fromUtf8("horizontalSliderBlue"));
        horizontalSliderBlue->setMaximum(255);
        horizontalSliderBlue->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderBlue, 2, 1, 1, 1);

        labelAlpha = new QLabel(Widget);
        labelAlpha->setObjectName(QString::fromUtf8("labelAlpha"));

        gridLayout->addWidget(labelAlpha, 3, 0, 1, 1);

        horizontalSliderAlpha = new QSlider(Widget);
        horizontalSliderAlpha->setObjectName(QString::fromUtf8("horizontalSliderAlpha"));
        horizontalSliderAlpha->setMaximum(255);
        horizontalSliderAlpha->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderAlpha, 3, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalSlider_5 = new QSlider(Widget);
        horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
        horizontalSlider_5->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_5);

        horizontalScrollBar = new QScrollBar(Widget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalScrollBar);

        progressBar = new QProgressBar(Widget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);


        verticalLayout_3->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dial = new QDial(Widget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMaximum(128);
        dial->setOrientation(Qt::Horizontal);
        dial->setInvertedAppearance(false);
        dial->setInvertedControls(false);
        dial->setWrapping(true);
        dial->setNotchTarget(100.000000000000000);
        dial->setNotchesVisible(true);

        horizontalLayout->addWidget(dial);

        lcdNumber = new QLCDNumber(Widget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtonDec = new QRadioButton(Widget);
        radioButtonDec->setObjectName(QString::fromUtf8("radioButtonDec"));

        verticalLayout_2->addWidget(radioButtonDec);

        radioButtonBin = new QRadioButton(Widget);
        radioButtonBin->setObjectName(QString::fromUtf8("radioButtonBin"));

        verticalLayout_2->addWidget(radioButtonBin);

        radioButtonOct = new QRadioButton(Widget);
        radioButtonOct->setObjectName(QString::fromUtf8("radioButtonOct"));

        verticalLayout_2->addWidget(radioButtonOct);

        radioButtonHex = new QRadioButton(Widget);
        radioButtonHex->setObjectName(QString::fromUtf8("radioButtonHex"));

        verticalLayout_2->addWidget(radioButtonHex);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalSlider = new QSlider(Widget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalSlider);

        verticalScrollBar = new QScrollBar(Widget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(verticalScrollBar);

        progressBar_2 = new QProgressBar(Widget);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setValue(24);
        progressBar_2->setOrientation(Qt::Vertical);
        progressBar_2->setInvertedAppearance(false);
        progressBar_2->setTextDirection(QProgressBar::TopToBottom);

        horizontalLayout_2->addWidget(progressBar_2);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 3, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        labelRed->setText(QApplication::translate("Widget", "Red:", nullptr));
        labelGreen->setText(QApplication::translate("Widget", "Green:", nullptr));
        labelBlue->setText(QApplication::translate("Widget", "Blue:", nullptr));
        labelAlpha->setText(QApplication::translate("Widget", "Alpha:", nullptr));
        radioButtonDec->setText(QApplication::translate("Widget", "\345\215\201\350\277\233\345\210\266", nullptr));
        radioButtonBin->setText(QApplication::translate("Widget", "\344\272\214\350\277\233\345\210\266", nullptr));
        radioButtonOct->setText(QApplication::translate("Widget", "\345\205\253\350\277\233\345\210\266", nullptr));
        radioButtonHex->setText(QApplication::translate("Widget", "\345\215\201\345\205\255\350\277\233\345\210\266", nullptr));
        pushButton->setText(QApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
