#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->scrollArea);//这里将scrollArea设置为主窗口工作区的中心组件后，　DockWidget和ScrollArea之间自动出现分隔条，可以分割两个组件的大小
    iniTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniTree()
{
    QString dataStr = "我是根"; //　Item 的　Data 存储的　string
    ui->treeWidget->clear();
    QIcon icon;
    icon.addFile(":/icon/节点-根节点-展开.png");

    QTreeWidgetItem *item = new QTreeWidgetItem(MainWindow::itTopItem); // 这里传入了我们自己定义的enum:表示顶层节点
    item->setIcon(MainWindow::colItem, icon); // 第一列的图标
    item->setText(MainWindow::colItem, "图片文件"); // 第一列的文字
    item->setText(MainWindow::colItemType, "type=itTopItem"); // 第二列
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem, Qt::Checked);

    item->setData(MainWindow::colItem, Qt::UserRole, QVariant(dataStr));
    ui->treeWidget->addTopLevelItem(item);//
}

void MainWindow::addFolderItem(QTreeWidgetItem *parItem, QString dirName)
{
    // 添加一个组节点
    QIcon icon(":/icon/节点-根节点-展开-背景1.png");
    QString nodeText = getFinalFolderName(dirName);// 获得最后的文件夹的名字

    QTreeWidgetItem *item;
    item = new QTreeWidgetItem(MainWindow::itGroupItem); // 节点类型 itGroupItem
    item->setIcon(colItem, icon);
    item->setText(colItem, nodeText);
    item->setText(colItemType, "type=itGroupItem");
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);
    item->setCheckState(colItem, Qt::Checked);
    item->setData(colItem, Qt::UserRole, QVariant(dirName));
    parItem->addChild(item); // 在父节点下面添加子节点
}

QString MainWindow::getFinalFolderName(const QString &fullPathName)
{
    // 从一个完整目录名称中，　获得最后的文件夹名称
    int cnt = fullPathName.length();
    int i = fullPathName.lastIndexOf('/');
    QString str = fullPathName.right(cnt - i -1);// 从右边开始取
    return str;
}

void MainWindow::addImageItem(QTreeWidgetItem *parItem, QString imgName)
{
    // 添加一个图片　文件节点
    QIcon icon(":/icon/节点.png");
    QString nodeText = getFinalFolderName(imgName);// 获得最后的文件名称
    QTreeWidgetItem *item;
    item = new QTreeWidgetItem(MainWindow::itImageItem); // 节点类型　itImageItem
    item->setIcon(colItem, icon);
    item->setText(colItem, nodeText);

    item->setText(colItemType, "type=itImageItem");
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsAutoTristate);

    item->setCheckState(colItem,Qt::Checked);
    item->setData(colItem, Qt::UserRole, QVariant(imgName)); // 完整文件名称
    parItem->addChild(item);
}

void MainWindow::on_actAddFolder_triggered()
{
    // 添加组节点
    QString dir = QFileDialog::getExistingDirectory(); // 选择目录
    if(!dir.isEmpty()){
        QTreeWidgetItem *tempItem = ui->treeWidget->currentItem(); // 当前的节点
        QTreeWidgetItem *parItem;
        if(tempItem->type() == itImageItem){
            parItem = tempItem->parent();
        }else {
            parItem = tempItem;
        }

        // 在父节点下面添加一个组节点
        addFolderItem(parItem, dir);
    }
}

void MainWindow::on_actAddFiles_triggered()
{
    // 添加图片文件节点
    QStringList files = QFileDialog::getOpenFileNames(this,"选择一个或者多个文件", "", "Images(*.png)" );
    if(files.isEmpty()){
        return;
    }

    QTreeWidgetItem *parItem, *item;
    item = ui->treeWidget->currentItem();
    if(item->type() == itImageItem){
        // 当前节点是图片节点
        parItem = item->parent();
    }else{
        parItem = item;
    }

    foreach(QString tempName, files){
        //添加一个图片节点
         addImageItem(parItem, tempName);
    }
}
