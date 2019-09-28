#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);

    connect(udpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(on_socketStateChanged(QAbstractSocket::SocketState)));

    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(on_socketReadyRead()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getLocalIp()
{
    // 获取本机的Ipv4 地址
    QString hostName = QHostInfo::localHostName(); // 本地主机名
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    QString localIp = "";
    QList<QHostAddress> addList = hostInfo.addresses();

    if(!addList.isEmpty()){
        for (int i = 0; i < addList.count(); i++) {
            QHostAddress aHost = addList.at(i);
            if(QAbstractSocket::IPv4Protocol == aHost.protocol()){
                localIp = aHost.toString(); break;
            }
        }
    }
    return  localIp;
}

void MainWindow::on_socketStateChanged(QAbstractSocket::SocketState socketState)
{

}

void MainWindow::on_socketReadyRead()
{
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    QHostAddress peerAddr;
    quint16 peerPort;
    udpSocket->readDatagram(datagram.data(), datagram.size(), &peerAddr, &peerPort);
//    QString str = datagram.data();
    QString peer = "[From " + peerAddr.toString() + ":" + QString::number(peerPort)+"]";
    ui->plainTextEdit->appendPlainText(peer);

    QPixmap p;
    p.loadFromData(datagram);
    ui->label->setPixmap(p);


}

void MainWindow::on_actionBind_triggered()
{


    // 绑定端口
    quint16 port = 3333; // 本机Udp 端口
    if(udpSocket->bind(port)){
        // 端口绑定成功
        ui->plainTextEdit->appendPlainText(QString::asprintf(
                                               "------端口:%d 完成绑定------",
                                               udpSocket->localPort()));
        this->setWindowTitle(this->windowTitle() + "　IP:" + getLocalIp() + ":" + QString::number(udpSocket->localPort()));


    }
}

void MainWindow::on_btnSend_clicked()
{
    // 发送消息
    QHostAddress targetAddr("127.0.0.1");
    quint16 targetPort = 4444; // 客户端的端口号
    QString msg = ui->lineEditMessage->text();
    QByteArray str = msg.toUtf8();

    udpSocket->writeDatagram(str, targetAddr, targetPort); // 发送数据
    ui->plainTextEdit->appendPlainText("[out] " + msg);
    ui->lineEditMessage->clear();
    ui->lineEditMessage->setFocus();
}
