#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize( this->width (),this->height ());

    // 关于 camera 测试
    QGraphicsScene *scene = new QGraphicsScene(this);
    QMyCameraBase *camera = new QMyCameraBase();
    camera->iniCamera(ui->CameraWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bind_success(QString successMsg)
{
    this->setWindowTitle(this->windowTitle() + successMsg);
    qDebug() << successMsg;
}

void MainWindow::on_receive_msg(QString msg)
{
}

void MainWindow::on_btnSend_clicked()
{
    // 截图保存
    QScreen *screen = QApplication::primaryScreen();
    QPixmap map = screen->grabWindow(ui->CameraWidget->winId()); //只截view窗口对象上的图像，也就是摄像头的数据
    //再编码成jpg图像
    QByteArray ba;
    QBuffer    bf(&ba);
    map.save(&bf, "jpg", 50);
    udptest->sendByteArray(ba);
}

void MainWindow::on_actionBind_triggered()
{
    udptest = new QMyUdpBase();
    connect(udptest, SIGNAL(signals_QMyUdpBase_bind_success(QString)),
            this, SLOT(on_bind_success(QString)));
    connect(udptest, SIGNAL(signals_QMyUdpBase_receive_msg(QString)),
            this, SLOT(on_receive_msg(QString)));
    udptest->bindPort(ui->lineEditLocalPort->text().toInt());
}
