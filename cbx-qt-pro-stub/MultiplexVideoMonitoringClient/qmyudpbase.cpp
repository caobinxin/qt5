#include "qmyudpbase.h"

QMyUdpBase::QMyUdpBase()
{
    udpSocket = new QUdpSocket();

    QObject::connect(udpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(on_socketStateChanged(QAbstractSocket::SocketState)));
    QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(on_socketReadyRead()));
}

QString QMyUdpBase::getLocalIp()
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

void QMyUdpBase::bindPort(quint16 port)
{
    if(udpSocket->bind(port)){
        // 端口绑定成功
        QString success = "　IP:" + getLocalIp() + ":" + QString::number(udpSocket->localPort());
        emit signals_QMyUdpBase_bind_success(success);
    }
}

void QMyUdpBase::sendStringMsg(QString targAddrIp,quint16 targetPort, QString msg)
{
    // 发送消息
    QHostAddress targetAddr(targAddrIp);
    QByteArray str = msg.toUtf8();
    udpSocket->writeDatagram(str, targetAddr, targetPort); // 发送数据
}

void QMyUdpBase::handleStringMsg()
{
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    QHostAddress peerAddr;
    quint16 peerPort;
    udpSocket->readDatagram(datagram.data(), datagram.size(), &peerAddr, &peerPort);
    QString str = datagram.data();
    QString peer = "[From " + peerAddr.toString() + ":" + QString::number(peerPort)+"]";
    emit signals_QMyUdpBase_receive_msg(peer + str);
}

void QMyUdpBase::sendByteArray(QByteArray &array)
{
    // 发送字节数据
    QHostAddress targetAddr("127.0.1.1");
    udpSocket->writeDatagram(array, targetAddr, 3333); // 发送数据
}

void QMyUdpBase::on_socketStateChanged(QAbstractSocket::SocketState socketState)
{

}

void QMyUdpBase::on_socketReadyRead()
{
    handleStringMsg();
}
