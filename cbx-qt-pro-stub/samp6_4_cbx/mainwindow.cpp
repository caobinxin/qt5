#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>
#include <QMdiArea>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setCentralWidget(ui->mdiArea);
    this->setWindowState(Qt::WindowMaximized);
    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->actViewMode->setCheckable(true); // 加上这个设置之后，按钮就可以被点选了

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actNew_triggered()
{
    // 新建文档
    QFormDoc *formDoc = new QFormDoc(this);
    ui->mdiArea->addSubWindow(formDoc); // 文档窗口添加到MDI中
    formDoc->show();
}

void MainWindow::on_actOpen_triggered()
{
    // 打开文件
    bool needNew = false; // 是否要新建子窗口
    QFormDoc *formDoc;

    if(ui->mdiArea->subWindowList().count() > 0){
        // 获取活动窗口
        formDoc = (QFormDoc *)ui->mdiArea->activeSubWindow()->widget();
        needNew = formDoc->isFileOpeneds(); //文件已经打开，需要新建窗口
    }else{
        needNew  = true;
    }

    QString curPath = QDir::currentPath();
    QString aFileName = QFileDialog::getOpenFileName(this, "打开一个文件", curPath, "C程序文件(*.h *.cpp);;所有文件(*.*)");

    if(aFileName.isEmpty())
        return;

    if (needNew){
        formDoc = new QFormDoc(this);
        ui->mdiArea->addSubWindow(formDoc);
    }

    formDoc->loadFromFiles(aFileName); // 打开文件
    formDoc->show();

    ui->actCut->setEnabled(true);
    ui->actCopy->setEnabled(true);
    ui->actPaste->setEnabled(true);
    ui->actFont->setEnabled(true);

}

void MainWindow::on_actCascade_triggered()
{
    // 窗口级联
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actTile_triggered()
{
    // 窗口平铺展开
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actCloseAll_triggered()
{
    // 关闭全部子窗口
    ui->mdiArea->closeAllSubWindows();
}

#include <QtDebug>
void MainWindow::on_actViewMode_triggered(bool checked)
{
    // MDI 显示模式
    if(checked){
        qDebug() << __FUNCTION__ << __LINE__;
        ui->mdiArea->setViewMode(QMdiArea::TabbedView); // tab 多页显示模式
        ui->mdiArea->setTabsClosable(true); // 页面关闭
        ui->actCascade->setEnabled(false);
        ui->actTile->setEnabled(false);
    }else {
        // 子窗口模式
        qDebug() << __FUNCTION__ << __LINE__;
        ui->mdiArea->setViewMode(QMdiArea::SubWindowView); // 子窗口模式
        ui->actCascade->setEnabled(true);
        ui->actTile->setEnabled(true);
    }
}

#include <QtDebug>
void MainWindow::on_mdiArea_subWindowActivated(QMdiSubWindow *arg1)
{
    qDebug() << __func__ << __LINE__;
    qDebug() << ui->mdiArea->subWindowList().count();
    // 当前活动子窗口切换时
    if((ui->mdiArea->subWindowList().count() == 0)){
        // 若子窗口个数为零
        qDebug() << __func__ << __LINE__;
        ui->actCut->setEnabled(false);
        ui->actCopy->setEnabled(false);
        ui->actPaste->setEnabled(false);
        ui->actFont->setEnabled(false);
        ui->statusBar->clearMessage();
    }else{
        qDebug() << __func__ << __LINE__;
        QFormDoc *formDoc = (QFormDoc*)ui->mdiArea->activeSubWindow()->widget();
        ui->statusBar->showMessage(formDoc->currentFileNames());

        ui->actCut->setEnabled(true);
        ui->actCopy->setEnabled(true);
        ui->actPaste->setEnabled(true);
        ui->actFont->setEnabled(true);
    }
}

void MainWindow::on_actCut_triggered()
{
    // cut操作
    QFormDoc* formDoc = (QFormDoc*)ui->mdiArea->activeSubWindow()->widget();
    formDoc->textCuts();
}

void MainWindow::on_actFont_triggered()
{
    QFormDoc* formDoc = (QFormDoc*)ui->mdiArea->activeSubWindow()->widget();
    formDoc->setEditFonts();
}
