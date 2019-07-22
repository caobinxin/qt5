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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *btnInitList;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPushButton *btnCityAreaCode;
    QComboBox *comboBox_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QSplitter *splitter_2;
    QPushButton *btnTextToComboBox;
    QPushButton *pushButton_5;
    QCheckBox *checkBox_2;
    QFrame *line;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(837, 424);
        verticalLayout_5 = new QVBoxLayout(Widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter = new QSplitter(Widget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(22);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 0, 1, 3);

        btnInitList = new QPushButton(widget);
        btnInitList->setObjectName(QString::fromUtf8("btnInitList"));

        gridLayout->addWidget(btnInitList, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        btnCityAreaCode = new QPushButton(widget1);
        btnCityAreaCode->setObjectName(QString::fromUtf8("btnCityAreaCode"));

        verticalLayout_2->addWidget(btnCityAreaCode);

        comboBox_2 = new QComboBox(widget1);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout_2->addWidget(comboBox_2);

        splitter->addWidget(widget1);

        verticalLayout_4->addWidget(splitter);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        splitter_2 = new QSplitter(Widget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(21);
        btnTextToComboBox = new QPushButton(splitter_2);
        btnTextToComboBox->setObjectName(QString::fromUtf8("btnTextToComboBox"));
        splitter_2->addWidget(btnTextToComboBox);
        pushButton_5 = new QPushButton(splitter_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        splitter_2->addWidget(pushButton_5);
        checkBox_2 = new QCheckBox(splitter_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        splitter_2->addWidget(checkBox_2);

        verticalLayout_3->addWidget(splitter_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        line = new QFrame(Widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout_4->addWidget(plainTextEdit);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "\347\256\200\345\215\225comboBox", nullptr));
        checkBox->setText(QApplication::translate("Widget", "\345\217\257\347\274\226\350\276\221", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
        comboBox->setItemText(0, QApplication::translate("Widget", "\344\270\212\346\265\267", nullptr));
        comboBox->setItemText(1, QApplication::translate("Widget", "\345\214\227\344\272\254", nullptr));
        comboBox->setItemText(2, QApplication::translate("Widget", "\345\244\251\346\264\245", nullptr));
        comboBox->setItemText(3, QApplication::translate("Widget", "\345\205\260\345\267\236", nullptr));
        comboBox->setItemText(4, QApplication::translate("Widget", "\346\265\216\345\215\227", nullptr));
        comboBox->setItemText(5, QApplication::translate("Widget", "\351\235\222\345\262\233", nullptr));

        btnInitList->setText(QApplication::translate("Widget", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", nullptr));
        label_2->setText(QApplication::translate("Widget", "\346\234\211\347\224\250\346\210\267\346\225\260\346\215\256\347\232\204ComboBox", nullptr));
        btnCityAreaCode->setText(QApplication::translate("Widget", "\345\210\235\345\247\213\345\214\226\345\237\216\345\270\202+\345\214\272\345\217\267", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("Widget", "\344\270\212\346\265\267", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("Widget", "\345\214\227\344\272\254", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("Widget", "\345\244\251\346\264\245", nullptr));
        comboBox_2->setItemText(3, QApplication::translate("Widget", "\345\205\260\345\267\236", nullptr));
        comboBox_2->setItemText(4, QApplication::translate("Widget", "\346\265\216\345\215\227", nullptr));
        comboBox_2->setItemText(5, QApplication::translate("Widget", "\351\235\222\345\262\233", nullptr));

        label_3->setText(QApplication::translate("Widget", "QPlainTextEdit(\345\205\267\346\234\211\346\240\207\345\207\206\345\277\253\346\215\267\350\217\234\345\215\225)", nullptr));
        btnTextToComboBox->setText(QApplication::translate("Widget", "\346\226\207\346\234\254\346\241\206\345\206\205\345\256\271\346\267\273\345\212\240\345\210\260ComboBox", nullptr));
        pushButton_5->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\346\226\207\346\234\254\345\206\205\345\256\271", nullptr));
        checkBox_2->setText(QApplication::translate("Widget", "\345\217\252\350\257\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
