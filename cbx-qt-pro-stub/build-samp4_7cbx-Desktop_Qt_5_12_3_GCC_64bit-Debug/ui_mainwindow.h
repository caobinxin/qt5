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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QAction *actInitList;
    QAction *actClear;
    QAction *actInsert;
    QAction *actAdd;
    QAction *actDelete;
    QAction *actAllSelect;
    QAction *actNoAllSelect;
    QAction *actInSeclet;
    QAction *actExit;
    QAction *actItemSeclect;
    QWidget *centralWidget;
    QSplitter *splitter_2;
    QToolBox *toolBox;
    QWidget *page;
    QSplitter *splitter;
    QToolButton *tBtnListIni;
    QToolButton *tBtnListClear;
    QToolButton *tBtnListInsert;
    QToolButton *tBtnListAppend;
    QToolButton *tBtnDelete;
    QWidget *page_2;
    QWidget *page_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelCurrentChangedItem;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tBtnSelectItem;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QListWidget *listWidget;
    QWidget *tab_2;
    QWidget *tab_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1032, 693);
        actionQListWidget = new QAction(MainWindow);
        actionQListWidget->setObjectName(QString::fromUtf8("actionQListWidget"));
        actInitList = new QAction(MainWindow);
        actInitList->setObjectName(QString::fromUtf8("actInitList"));
        actClear = new QAction(MainWindow);
        actClear->setObjectName(QString::fromUtf8("actClear"));
        actInsert = new QAction(MainWindow);
        actInsert->setObjectName(QString::fromUtf8("actInsert"));
        actAdd = new QAction(MainWindow);
        actAdd->setObjectName(QString::fromUtf8("actAdd"));
        actDelete = new QAction(MainWindow);
        actDelete->setObjectName(QString::fromUtf8("actDelete"));
        actAllSelect = new QAction(MainWindow);
        actAllSelect->setObjectName(QString::fromUtf8("actAllSelect"));
        actNoAllSelect = new QAction(MainWindow);
        actNoAllSelect->setObjectName(QString::fromUtf8("actNoAllSelect"));
        actInSeclet = new QAction(MainWindow);
        actInSeclet->setObjectName(QString::fromUtf8("actInSeclet"));
        actExit = new QAction(MainWindow);
        actExit->setObjectName(QString::fromUtf8("actExit"));
        actItemSeclect = new QAction(MainWindow);
        actItemSeclect->setObjectName(QString::fromUtf8("actItemSeclect"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(10, 10, 911, 521));
        splitter_2->setOrientation(Qt::Horizontal);
        toolBox = new QToolBox(splitter_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(130, 0));
        toolBox->setMaximumSize(QSize(130, 16777215));
        toolBox->setFrameShape(QFrame::StyledPanel);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 128, 420));
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
        tBtnDelete = new QToolButton(splitter);
        tBtnDelete->setObjectName(QString::fromUtf8("tBtnDelete"));
        splitter->addWidget(tBtnDelete);
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 128, 420));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setGeometry(QRect(0, 0, 128, 420));
        toolBox->addItem(page_3, QString::fromUtf8("\351\241\265"));
        splitter_2->addWidget(toolBox);
        tabWidget = new QTabWidget(splitter_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelCurrentChangedItem = new QLabel(tab);
        labelCurrentChangedItem->setObjectName(QString::fromUtf8("labelCurrentChangedItem"));

        horizontalLayout->addWidget(labelCurrentChangedItem);

        horizontalSpacer = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout->addWidget(checkBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tBtnSelectItem = new QToolButton(tab);
        tBtnSelectItem->setObjectName(QString::fromUtf8("tBtnSelectItem"));
        tBtnSelectItem->setMinimumSize(QSize(46, 0));

        horizontalLayout_2->addWidget(tBtnSelectItem);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(tab);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout_3->addLayout(verticalLayout);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        splitter_2->addWidget(tabWidget);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1032, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tBtnDelete, pushButton_2);
        QWidget::setTabOrder(pushButton_2, tBtnListIni);
        QWidget::setTabOrder(tBtnListIni, tBtnListAppend);
        QWidget::setTabOrder(tBtnListAppend, tabWidget);
        QWidget::setTabOrder(tabWidget, listWidget);
        QWidget::setTabOrder(listWidget, checkBox);
        QWidget::setTabOrder(checkBox, tBtnListClear);
        QWidget::setTabOrder(tBtnListClear, tBtnListInsert);
        QWidget::setTabOrder(tBtnListInsert, pushButton_3);

        mainToolBar->addAction(actInitList);
        mainToolBar->addAction(actClear);
        mainToolBar->addAction(actInsert);
        mainToolBar->addAction(actAdd);
        mainToolBar->addAction(actDelete);
        mainToolBar->addAction(actExit);
        mainToolBar->addAction(actItemSeclect);
        mainToolBar->addAction(actAllSelect);
        mainToolBar->addAction(actNoAllSelect);

        retranslateUi(MainWindow);
        QObject::connect(actItemSeclect, SIGNAL(triggered()), actInSeclet, SLOT(toggle()));
        QObject::connect(actExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        toolBox->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQListWidget->setText(QApplication::translate("MainWindow", "QListWidget\346\223\215\344\275\234", nullptr));
#ifndef QT_NO_TOOLTIP
        actionQListWidget->setToolTip(QApplication::translate("MainWindow", "QListWidget\346\223\215\344\275\234", nullptr));
#endif // QT_NO_TOOLTIP
        actInitList->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\345\210\227\350\241\250", nullptr));
        actClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
        actInsert->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        actAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        actDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
        actAllSelect->setText(QApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        actNoAllSelect->setText(QApplication::translate("MainWindow", "\345\205\250\344\270\215\351\200\211", nullptr));
        actInSeclet->setText(QApplication::translate("MainWindow", "\345\217\215\351\200\211", nullptr));
        actExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        actItemSeclect->setText(QApplication::translate("MainWindow", "\351\241\271\351\200\211\346\213\251", nullptr));
        tBtnListIni->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", nullptr));
        tBtnListClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        tBtnListInsert->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        tBtnListAppend->setText(QApplication::translate("MainWindow", "\350\277\275\345\212\240", nullptr));
        tBtnDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("MainWindow", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("MainWindow", "Page 2", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("MainWindow", "\351\241\265", nullptr));
        labelCurrentChangedItem->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\351\241\271\347\232\204\345\217\230\345\214\226", nullptr));
        checkBox->setText(QApplication::translate("MainWindow", "\345\217\257\347\274\226\350\276\221", nullptr));
        tBtnSelectItem->setText(QApplication::translate("MainWindow", "\351\241\271\351\200\211\345\210\231", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "2", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "3", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "4", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "5", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
