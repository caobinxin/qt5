#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->scrollArea);//这里将scrollArea设置为主窗口工作区的中心组件后，　DockWidget和ScrollArea之间自动出现分隔条，可以分割两个组件的大小

    LabFileName = new QLabel("");
    ui->statusBar->addWidget(LabFileName);
    this->setCentralWidget(ui->scrollArea);

    iniTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniTree()
{
    qDebug() << __func__ ;
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
    qDebug() << __func__ ;
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
    qDebug() << __func__ ;
    // 从一个完整目录名称中，　获得最后的文件夹名称
    int cnt = fullPathName.length();
    int i = fullPathName.lastIndexOf('/');
    QString str = fullPathName.right(cnt - i -1);// 从右边开始取
    return str;
}

void MainWindow::addImageItem(QTreeWidgetItem *parItem, QString imgName)
{
    qDebug() << __func__ ;
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

void MainWindow::displayImage(QTreeWidgetItem *curItem)
{
    qDebug() << __func__ ;
    // 显示图片，节点　item存储了图片的文件名
    QString fileName = curItem->data(colItem, Qt::UserRole).toString(); // 文件的全名
    LabFileName->setText(fileName);
    curPixMap.load(fileName);

    on_actZoomFitH_triggered(); // 自动适应高度显示
}

void MainWindow::changeItemCaption(QTreeWidgetItem *curItem)
{
    qDebug() << __func__;
    // 改变节点的标题文字
    QString str = "*" + curItem->text(colItem);
    curItem->setText(colItem, str);
    if(curItem->childCount() > 0){
        for(int i = 0; i < curItem->childCount(); i++){
            // 遍历子节点
            changeItemCaption(curItem->child(i)); // 调用自己，可重入的函数　递归调用
        }
    }
}

void MainWindow::on_actAddFolder_triggered()
{
    qDebug() << __func__ ;
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
    qDebug() << __func__ << __LINE__;
    // 添加图片文件节点
    QStringList files = QFileDialog::getOpenFileNames(this,"选择一个或者多个文件", "", "Images(*.png)" );
    if(files.isEmpty()){
        return;
    }
    QTreeWidgetItem *parItem, *item;
    item = ui->treeWidget->currentItem();
    if(NULL == item) return;
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

void MainWindow::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    qDebug() << __func__ ;
    // 当前节点变化时的处理
    Q_UNUSED(previous);

    if(NULL == current){
        return;
    }

    int var = current->type(); // 节点类型
    switch (var) {
        case itTopItem:
            ui->actAddFolder->setEnabled(true);
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(false); // 顶点节点不能删除
            break;

         case itGroupItem:
            ui->actAddFolder->setEnabled(true);
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(true);
            break;

         case itImageItem:
            ui->actAddFolder->setEnabled(false);// 图片节点下不能添加目录节点
            ui->actAddFiles->setEnabled(true);
            ui->actDeleteItem->setEnabled(true);
            displayImage(current); //显示图片
            break;
    }
}

void MainWindow::on_actDeleteItem_triggered()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem(); // 当前节点
    QTreeWidgetItem *parItem = item->parent();// 父节点
    parItem->removeChild(item); // 移除一个子节点，并不会删除
    delete item;
}

void MainWindow::on_actScanItems_triggered()
{
    // 遍历整个目录树下面的节点
    for(int i = 0; i < ui->treeWidget->topLevelItemCount(); i++){
        QTreeWidgetItem *item = ui->treeWidget->topLevelItem(i); // 顶层节点
        changeItemCaption(item);// 更改节点标题
    }
}

void MainWindow::on_actZoomFitH_triggered()
{
    qDebug() << __func__ ;
    int H = ui->scrollArea->height();
    int realH = curPixMap.height();
    pixRatio = float(H)/realH; // 当前显示比例，必须转为浮点树
    QPixmap pix = curPixMap.scaledToHeight(H-30); //　图片缩放到制定高度
    ui->label->setPixmap(pix);
}

void MainWindow::on_actQuit_triggered()
{
    qDebug() << __func__;
    close();
}

void MainWindow::on_actZoomIn_triggered()
{
    qDebug() << __func__;
    // 放大显示
    pixRatio = pixRatio * 1.2;
    int w = pixRatio * curPixMap.width();
    int h = pixRatio * curPixMap.height();
    QPixmap pix = curPixMap.scaled(w, h);
    ui->label->setPixmap(pix);
}

void MainWindow::on_actZoomRealSize_triggered()
{
    // 实际大小
    pixRatio = 1;
    ui->label->setPixmap(curPixMap);
}

void MainWindow::on_actDockVisible_triggered(bool checked)
{
    // 停靠区　的　可见性
    ui->dockWidget->setVisible(checked);
}

void MainWindow::on_actDockFloat_triggered(bool checked)
{
    // 停靠区　的　浮动性
    ui->dockWidget->setFloating(checked);
}

void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    // 当　点击　dockWidget 的 关闭按钮，会触发这个
    ui->actDockVisible->setChecked(visible);
}

void MainWindow::on_dockWidget_topLevelChanged(bool topLevel)
{
    // 停靠区 浮动性变化
    ui->actDockFloat->setChecked(topLevel);
}
