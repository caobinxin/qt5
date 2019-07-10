/********************************************************************************
** Form generated from reading UI file 'qwdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWDIALOG_H
#define UI_QWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QWDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rBtnBlack;
    QRadioButton *rBtnRed;
    QRadioButton *rBtnBlue;
    QPlainTextEdit *txtEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnClose;

    void setupUi(QDialog *QWDialog)
    {
        if (QWDialog->objectName().isEmpty())
            QWDialog->setObjectName(QString::fromUtf8("QWDialog"));
        QWDialog->resize(436, 384);
        verticalLayout_2 = new QVBoxLayout(QWDialog);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(QWDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chkBoxUnder = new QCheckBox(groupBox);
        chkBoxUnder->setObjectName(QString::fromUtf8("chkBoxUnder"));

        horizontalLayout->addWidget(chkBoxUnder);

        chkBoxItalic = new QCheckBox(groupBox);
        chkBoxItalic->setObjectName(QString::fromUtf8("chkBoxItalic"));

        horizontalLayout->addWidget(chkBoxItalic);

        chkBoxBold = new QCheckBox(groupBox);
        chkBoxBold->setObjectName(QString::fromUtf8("chkBoxBold"));

        horizontalLayout->addWidget(chkBoxBold);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(QWDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rBtnBlack = new QRadioButton(groupBox_2);
        rBtnBlack->setObjectName(QString::fromUtf8("rBtnBlack"));

        horizontalLayout_2->addWidget(rBtnBlack);

        rBtnRed = new QRadioButton(groupBox_2);
        rBtnRed->setObjectName(QString::fromUtf8("rBtnRed"));

        horizontalLayout_2->addWidget(rBtnRed);

        rBtnBlue = new QRadioButton(groupBox_2);
        rBtnBlue->setObjectName(QString::fromUtf8("rBtnBlue"));

        horizontalLayout_2->addWidget(rBtnBlue);


        verticalLayout->addWidget(groupBox_2);

        txtEdit = new QPlainTextEdit(QWDialog);
        txtEdit->setObjectName(QString::fromUtf8("txtEdit"));

        verticalLayout->addWidget(txtEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnOk = new QPushButton(QWDialog);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        horizontalLayout_3->addWidget(btnOk);

        btnCancel = new QPushButton(QWDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_3->addWidget(btnCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnClose = new QPushButton(QWDialog);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout_3->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(QWDialog);

        QMetaObject::connectSlotsByName(QWDialog);
    } // setupUi

    void retranslateUi(QDialog *QWDialog)
    {
        QWDialog->setWindowTitle(QApplication::translate("QWDialog", "Dialog by Designer", nullptr));
        groupBox->setTitle(QApplication::translate("QWDialog", "GroupBox", nullptr));
        chkBoxUnder->setText(QApplication::translate("QWDialog", "Underline", nullptr));
        chkBoxItalic->setText(QApplication::translate("QWDialog", "Italic", nullptr));
        chkBoxBold->setText(QApplication::translate("QWDialog", "Bold", nullptr));
        groupBox_2->setTitle(QApplication::translate("QWDialog", "GroupBox", nullptr));
        rBtnBlack->setText(QApplication::translate("QWDialog", "Black", nullptr));
        rBtnRed->setText(QApplication::translate("QWDialog", "Red", nullptr));
        rBtnBlue->setText(QApplication::translate("QWDialog", "Blue", nullptr));
        txtEdit->setPlainText(QApplication::translate("QWDialog", "hello,world\n"
"It is my demo.", nullptr));
        btnOk->setText(QApplication::translate("QWDialog", "ok", nullptr));
        btnCancel->setText(QApplication::translate("QWDialog", "Cancel", nullptr));
        btnClose->setText(QApplication::translate("QWDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWDialog: public Ui_QWDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWDIALOG_H
