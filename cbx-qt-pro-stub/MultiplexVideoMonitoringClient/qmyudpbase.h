#ifndef QMYUDPBASE_H
#define QMYUDPBASE_H
#include <QUdpSocket>
#include <QHostInfo>

class QMyUdpBase : public QObject
{
    Q_OBJECT
public:
    QMyUdpBase();

public:
    QUdpSocket *udpSocket;

    QString getLocalIp(); // 获取本机Ip地址

    void bindPort(quint16 port);
    void sendStringMsg(QString targAddrIp,quint16 targetPort, QString msg);
    void handleStringMsg();
    void sendByteArray(QByteArray &array);

private slots:
    void on_socketStateChanged(QAbstractSocket::SocketState socketState);
    void on_socketReadyRead(); // 读取 socket 传入的数据

signals:
    void signals_QMyUdpBase_receive_msg(QString handledMsg);
    void signals_QMyUdpBase_bind_success(QString successMsg);

};

#endif // QMYUDPBASE_H
