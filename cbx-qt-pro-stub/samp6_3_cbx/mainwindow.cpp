#include "mainwindow.h"
#include "ui_mainwindow.h"

#include    <QPainter>
#include    <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setVisible(false); // 不可见
    ui->tabWidget->clear(); // 清除所有页面
    ui->tabWidget->setTabsClosable(true);// Page 有关闭按钮，可被关闭
//    ui->tabWidget->tabsClosable();

    this->setCentralWidget(ui->tabWidget);
    this->setWindowState(Qt::WindowMaximized);// 窗口最大化显示

    this->autoFillBackground();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    // 绘制窗口背景图片
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(0, ui->mainToolBar->height(), this->width(),
                       this->height()-ui->mainToolBar->height()-ui->statusBar->height(),
                       QPixmap(":/back/车.jpg"));
}

void MainWindow::on_actWidgetInsite_triggered()
{
    // 创建　QFormDoc 窗体，　并在tabWidget中显示
    QFormDoc *formDoc = new QFormDoc(this);
    formDoc->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动删除
    int cur = ui->tabWidget->addTab(formDoc, QString::asprintf("Doc %d", ui->tabWidget->count()));
    ui->tabWidget->setCurrentIndex(cur);
    ui->tabWidget->setVisible(true);
}

void MainWindow::on_actWidget_triggered()
{
    QFormDoc *formDoc = new QFormDoc();
    formDoc->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动删除

    formDoc->setWindowTitle("基于QWidget的窗体, 无父窗口，关闭时删除");
    formDoc->setWindowFlag(Qt::Window, true);

    formDoc->setWindowFlag(Qt::CustomizeWindowHint, true);
    formDoc->setWindowFlag(Qt::WindowMinMaxButtonsHint, false);
    formDoc->setWindowFlag(Qt::WindowCloseButtonHint, true);
    formDoc->setWindowFlag(Qt::WindowStaysOnTopHint, true);

    formDoc->setWindowOpacity(0.7); // 透明度
    formDoc->show(); // 在单独的窗口中显示
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    // 关闭Tab 点击书签中的关闭按钮
    if(index < 0){
        return;
    }

    QWidget *aForm = ui->tabWidget->widget(index);// 返回　TabWidget组件中某个页面的窗体组件
    aForm->close();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    bool en = ui->tabWidget->count() > 0; // 再无分页
    ui->tabWidget->setVisible(en); // 当在标签页的时候，tabWidget不显示，这样背景就会显示出来
}
