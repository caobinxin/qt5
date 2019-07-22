/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQListWidget;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_2;
    QToolBox *toolBox;
    QWidget *page;
    QSplitter *splitter;
    QToolButton *tBtnListIni;
    QToolButton *tBtnListClear;
    QToolButton *tBtnListInsert;
    QToolButton *tBtnListAppend;
    QToolButton *toolButton;
    QWidget *page_2;
    QWidget *page_3;
    QFrame *line;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(713, 379);
        actionQListWidget = new QAction(MainWindow);
        actionQListWidget->setObjectName(QString::fromUtf8("actionQListWidget"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 132, 195));
        splitter = new QSplitter(page);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(0, 0, 121, 111));
        splitter->setOrientation(Qt::Vertical);
        tBtnListIni = new QToolButton(splitter);
        tBtnListIni->setObjectName(QString::fromUtf8("tBtnListIni"));
        splitter->addWidget(tBtnListIni);
        tBtnListClear = new QToolButton(splitter);
        tBtnListClear->setObjectName(QString::fromUtf8("tBtnListClear"));
        splitter->addWidget(tBtnListClear);
        tBtnListInsert = new QToolButton(splitter);
        tBtnListInsert->setObjectName(QString::fromUtf8("tBtnListInsert"));
        splitter->addWidget(tBtnListInsert);
        tBtnListAppend = new QToolButton(splitter);
        tBtnListAppend->setObjectName(QString::fromUtf8("tBtnListAppend"));
        splitter->addWidget(tBtnListAppend);
        toolButton = new QToolButton(splitter);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        splitter->addWidget(toolButton);
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 132, 195));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        toolBox->addItem(page_3, QString::fromUtf8("\351\241\265"));
        splitter_2->addWidget(toolBox);
        line = new QFrame(splitter_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        splitter_2->addWidget(line);
        tabWidget = new QTabWidget(splitter_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        splitter_2->addWidget(tabWidget);

        verticalLayout->addWidget(splitter_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 713, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQListWidget->setText(QApplication::translate("MainWindow", "QListWidget\346\223\215\344\275\234", nullptr));
#ifndef QT_NO_TOOLTIP
        actionQListWidget->setToolTip(QApplication::translate("MainWindow", "QListWidget\346\223\215\344\275\234", nullptr));
#endif // QT_NO_TOOLTIP
        tBtnListIni->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        tBtnListClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        tBtnListInsert->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        tBtnListAppend->setText(QApplication::translate("MainWindow", "\350\277\275\345\212\240", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Page 2", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("MainWindow", "\351\241\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
