#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    theModel = new QStandardItemModel(2, 10); // 数据模型
    theSelection = new QItemSelectionModel(theModel); // 选择模型

    ui->tableView->setModel(theModel); // 设置数据模型
    ui->tableView->setSelectionModel(theSelection);// 设置选择模型
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActLocalEnable(bool flag)
{
    ui->actLocate->setEnabled(flag);
}

void MainWindow::on_actSetSize_triggered()
{
    //　模态对话框，动态创建，用过后删除
    QWDialogSize *dlgTableSize = new QWDialogSize(this);
    Qt::WindowFlags flags = dlgTableSize->windowFlags();
    dlgTableSize->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);// 将对话框设置为固定大小
    dlgTableSize->setRowColumn(theModel->rowCount(), theModel->columnCount());

    int ret = dlgTableSize->exec(); // 以模态方式显示对话框
    if(ret == QDialog::Accepted){
        // ok 按钮被按下，获取对话框上的输入，设置行数和列数
        int cols = dlgTableSize->columnCount();
        theModel->setColumnCount(cols);

        int rows = dlgTableSize->rowCount();
        theModel->setRowCount(rows);
    }

    delete dlgTableSize;
}

void MainWindow::on_actSetHeader_triggered()
{
    // 一次创建多次调用，对话框关闭时只是隐藏
    if(dlgSetHeaders == NULL){
        dlgSetHeaders = new QWDialogHeaders(this);//　传递主窗口的指针作为对话框的父对象，　当主窗口退出时，会自动释放　QWDialogHeaders
    }

    if(dlgSetHeaders->headerList().count() != theModel->columnCount()){
        // 如果表头列变换，重新设置dialog中的表头信息
        QStringList strList;
        for(int i = 0; i < theModel->columnCount(); i++){
            strList.append(theModel->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
            dlgSetHeaders->setHeaderList(strList); // 对话框表头信息的初始化
        }
    }

    int ret = dlgSetHeaders->exec(); // 以模态方式显示对话框
    if( ret == QDialog::Accepted){
        QStringList strList = dlgSetHeaders->headerList();
        theModel->setHorizontalHeaderLabels(strList); // 设置模型的表头标题
    }
}

void MainWindow::on_actLocate_triggered()
{
    QWDialogLocate *dlgLocate = new QWDialogLocate(this);
    dlgLocate->setAttribute(Qt::WA_DeleteOnClose);

    Qt::WindowFlags flags = dlgLocate->windowFlags();
    dlgLocate->setWindowFlags(flags | Qt::WindowStaysOnTopHint);
    dlgLocate->setSpinRange(theModel->rowCount(), theModel->columnCount());
    QModelIndex curIndex = theSelection->currentIndex();
    if(curIndex.isValid()){
        dlgLocate->setSpinValue(curIndex.row(), curIndex.column());
    }

    // 对话框发射信号，设置单元格文字
    connect(dlgLocate, SIGNAL(changeCellText(int, int, QString&)), this, SLOT(setACellText(int, int, QString&)));

    // 对话框发射信号，设置actTab_Locate的属性
    connect(dlgLocate, SIGNAL(changeActionEnable(bool)), this, SLOT(setActLocalEnable(bool)));

    // 主窗口发射信号，　修改对话框上的spinBox的值
    connect(this, SIGNAL(cellIndexChanged(int, int)), dlgLocate, SLOT(setSpinValue(int,int)));
    dlgLocate->show();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    // 单击单元格时，将单元格的行号、列号设置到对话框上
    emit cellIndexChanged(index.row(), index.column());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // 窗口关闭时，询问是否退出
    QMessageBox::StandardButton result = QMessageBox::question(this,
                                            "确认", "确认要退出本程序?",
                                            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                            QMessageBox::No);
    if (result == QMessageBox::Yes){
        event->accept();
    }else{
        event->ignore();
    }
}

void MainWindow::setACellText(int row, int column, QString &text)
{
        qDebug()<< __func__;
        // 定位到单元格，　并设置字符串
        QModelIndex index = theModel->index(row, column); // 获取模型的索引
        theSelection->clearSelection();
        theSelection->setCurrentIndex(index, QItemSelectionModel::Select);
        theModel->setData(index, text, Qt::DisplayRole); // 设置单元格字符串
}
