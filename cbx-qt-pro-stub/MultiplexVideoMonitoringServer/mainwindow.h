#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QUdpSocket>
#include <QLabel>
#include <QHostInfo>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    QLabel *LabSocketState; // socket 状态显示标签
    QUdpSocket *udpSocket;
    QString getLocalIp(); // 获取本机Ip地址

private slots:
    void on_socketStateChanged(QAbstractSocket::SocketState socketState);
    void on_socketReadyRead(); // 读取 socket 传入的数据
    void on_actionBind_triggered();
    void on_btnSend_clicked();
};

#endif // MAINWINDOW_H
