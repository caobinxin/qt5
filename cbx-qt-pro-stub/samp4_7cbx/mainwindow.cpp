#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter_2);//可以使splitter填充整个工作区

    setActionsForButton();
    createSelectionPopMenu();

    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actInitList_triggered()
{
    //初始化列表
    QListWidgetItem *aItem; //每一行是一个QListWidgetItem
    QIcon aIcon;
    aIcon.addFile(":/images/选项选中.png");

    bool chk = ui->checkBox->isChecked();// 是否处于可编辑状态

    ui->listWidget->clear();
    for(int i = 0; i < 10; i++){
        QString str = QString::asprintf("Item %d", i);
        aItem = new QListWidgetItem();
        aItem->setText(str);
        aItem->setIcon(aIcon);
        aItem->setCheckState(Qt::Checked);// 设置为选中的状态

        if(chk){
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }else{
            aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
        }

        ui->listWidget->addItem(aItem);// 添加一个项
    }
    qDebug()<< "初始化列表";
}

void MainWindow::on_actInsert_triggered()
{
    //插入一个项
    QIcon aIcon;
    aIcon.addFile(":/images/选项选中.png");
    bool chk = ui->checkBox->isChecked();

    QListWidgetItem *aItem = new QListWidgetItem("New Inserted Item");
    aItem->setIcon(aIcon);
    aItem->setCheckState(Qt::Checked);

    if(chk){
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    }else {
        aItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
    }

    ui->listWidget->insertItem(ui->listWidget->currentRow(), aItem);
}

void MainWindow::on_actDelete_triggered()
{
    // 删除当前项
    int row = ui->listWidget->currentRow();
    QListWidgetItem *aItem = ui->listWidget->takeItem(row);// takeItem()函数只是移除一个项，并不删除项对象，所以还需要用
    // delete从内存中删除他。
    // 要清空列表框的所有项，只需要调用QListWidget::clear()函数即可。
    delete aItem; // 手工删除对象
}

void MainWindow::on_actAllSelect_triggered()
{
    // 全选
    int cnt = ui->listWidget->count();//个数
    for(int i = 0; i < cnt; i++){
        QListWidgetItem *aItem = ui->listWidget->item(i);//获取一个项
        aItem->setCheckState(Qt::Checked);// 设置为选中
    }
}

void MainWindow::on_actNoAllSelect_triggered()
{
    // 全不选
    int cnt = ui->listWidget->count();//个数
    for(int i = 0; i < cnt; i++){
        QListWidgetItem *aItem = ui->listWidget->item(i);//获取一个项
        aItem->setCheckState(Qt::Unchecked);// 设置为不选中
    }
}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // listWidget 当前选中项发生变化
    QString str;

    if(current != NULL){
        if(previous == NULL){
            str = "当前项：" + current->text();
        }else{
            str = "前一项：" + previous->text() + " 当前项：" + current->text();
        }

        ui->labelCurrentChangedItem->setText(str);
    }
}

void MainWindow::setActionsForButton()
{
    //为QToolButton 按钮设置　Action
    ui->tBtnListIni->setDefaultAction(ui->actInitList);

    ui->tBtnListClear->setDefaultAction(ui->actClear);

    ui->tBtnListAppend->setDefaultAction(ui->actInsert);

    ui->tBtnListInsert->setDefaultAction(ui->actAdd);

    ui->tBtnDelete->setDefaultAction(ui->actDelete);

}

void MainWindow::createSelectionPopMenu()
{
    // 创建下拉菜单

    QMenu *menuSelection = new QMenu(this);// 创建弹出式菜单
    menuSelection->addAction(ui->actAllSelect);
    menuSelection->addAction(ui->actNoAllSelect);
    menuSelection->addAction(ui->actInSeclet);
    menuSelection->addAction(ui->actItemSeclect);

    // listWidget 上方的 tBtnSelectItem 按钮
    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
    ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tBtnSelectItem->setDefaultAction(ui->actItemSeclect); // 关联Action
    ui->tBtnSelectItem->setMenu(menuSelection);

    // 工具栏上的，下拉式菜单按钮
    QToolButton *aBtn = new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon); //按钮样式
    aBtn->setDefaultAction(ui->actItemSeclect);
    aBtn->setMenu(menuSelection); // 设置下拉菜单
    ui->mainToolBar->addWidget(aBtn);//工具栏添加按钮

    // 工具栏添加分割条；　和　退出按钮
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actExit);

}

void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug()<< "触发了右键菜单";
    Q_UNUSED(pos);
    QMenu *menuList = new QMenu(this); //创建菜单
    // 添加 actions 创建菜单项
    menuList->addAction(ui->actInsert);
    menuList->addAction(ui->actInSeclet);
    menuList->addAction(ui->actAllSelect);
    menuList->addAction(ui->actNoAllSelect);
    menuList->addAction(ui->actAdd);
    menuList->addAction(ui->actItemSeclect);

    menuList->addSeparator();
    menuList->addAction(ui->actExit);

    menuList->exec(QCursor::pos()); // 在鼠标光标位置显示右键快捷菜单
    delete menuList;
    qDebug()<< "触发了右键菜单";
}

void MainWindow::on_centralWidget_customContextMenuRequested(const QPoint &pos)
{
    qDebug()<< "触发了右键菜单";
}
