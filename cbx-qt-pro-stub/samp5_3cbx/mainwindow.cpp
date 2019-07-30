#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);// 这个是平分布局

    theModel = new QStandardItemModel(2, FixedColumnCount, this);// 数据模型
    theSelection = new QItemSelectionModel(theModel); // 选择模型
    connect(theSelection, SIGNAL(currentChanged(QModelIndex, QModelIndex)), this, SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    ui->tableView->setModel(theModel); // 设置数据模型
    ui->tableView->setSelectionModel(theSelection); // 设置选择模型
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

    labCurFile = new QLabel();
    labCellPos = new QLabel();
    labCellText = new QLabel();

    labCurFile->setText("当前文件是：");
    labCellPos->setText("当前单元格的位置：");
    labCellText->setText("单元格内容：");

    ui->statusBar->addWidget(labCellPos);
    ui->statusBar->addWidget(labCurFile);
    ui->statusBar->addWidget(labCellText);

    ui->tableView->setItemDelegateForColumn(0, &intSpinDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    // 选择单元格变化时的响应
    if(current.isValid()){
        labCellPos->setText(QString::asprintf("当前单元格： %d行， %d列", current.row(), current.column()));
        QStandardItem * aItem = theModel->itemFromIndex(current);
        this->labCellText->setText("单元格内容:" + aItem->text());
        QFont font = aItem->font();
        ui->actFontBold->setChecked(font.bold());
    }

}

void MainWindow::iniModelFromStringList(QStringList &aFileContent)
{
    // 从一个 StringList 获取数据，初始化数据模型
    int rowCnt = aFileContent.count(); // 文本行数， 第一行是标题
    theModel->setRowCount(rowCnt -1);

    // 设置表头， 一个或者多个空格， tab等分隔开的字符串， 分解一个StringList
    QString header = aFileContent.at(0); // 第1行是表头
    QStringList headerList =
            header.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    theModel->setHorizontalHeaderLabels(headerList); // 设置表头文字
    // 设置表格数据
    QStandardItem *aItem;
    QStringList tmpList;
    int j;

    for(int i = 1; i < rowCnt; i++){
        QString aLineText = aFileContent.at(i);
        tmpList = aLineText.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        for(j = 0; j < FixedColumnCount -1; j++){
            // 不包含最后一列
            aItem = new QStandardItem(tmpList.at(j));
            theModel->setItem(i-1, j, aItem); // 为模型的某个行列位置设置 Item
        }
        aItem = new QStandardItem(headerList.at(j)); // 最后一列
        aItem->setCheckable(true);
        if(tmpList.at(j) == "0")
            aItem->setCheckState(Qt::Unchecked);
        else {
            aItem->setCheckState(Qt::Checked);
        }
        theModel->setItem(i-1, j, aItem);
    }
}

void MainWindow::on_actOpen_triggered()
{
    // 打开文件
    QString curPath = QCoreApplication::applicationDirPath();
    QString aFileName = QFileDialog::getOpenFileName(this, "打开一个文件", curPath, "水井数据(*.txt);;所有文件(*.*)");
    if(aFileName.isEmpty()) return;

    QStringList fFileContent;
    QFile aFile(aFileName);
    if(aFile.open(QIODevice::ReadOnly | QIODevice::Text))//打开文件
    {
        QTextStream aStream(&aFile); // 用文本流读取文件
        ui->plainTextEdit->clear();
        while (!aStream.atEnd()) {
            QString str = aStream.readLine();
            ui->plainTextEdit->appendPlainText(str);
            fFileContent.append(str);
        }
        aFile.close();
        this->labCurFile->setText("当前文件：" + aFileName); // 状态栏显示
        iniModelFromStringList(fFileContent); // 初始化数据模型
    }
}
