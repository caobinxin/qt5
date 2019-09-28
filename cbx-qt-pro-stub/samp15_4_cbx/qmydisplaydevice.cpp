#include "qmydisplaydevice.h"

QmyDisplayDevice::QmyDisplayDevice(QXYSeries *series, qint64 pointsCount, QObject *parent): QIODevice (parent)
{
    // 构造函数
    m_series = series;
    range = pointsCount;
}

qint64 QmyDisplayDevice::readData(char *data, qint64 maxSize)
{
    // 流的读操作，　不处理
    Q_UNUSED(data);
    Q_UNUSED(maxSize);

    return -1;
}

qint64 QmyDisplayDevice::writeData(const char *data, qint64 maxSize)
{
    // 读取数据块的数据，　更新序列
    QVector<QPointF> oldPoints = m_series->pointsVector();
    QVector<QPointF> points; // 临时
    if(oldPoints.count() < range){
        // m_series 序列的数据未满 4000 点
        points = m_series->pointsVector();
    }else{
        // 将原来maxSize 至 4000 的数据点前移 (整体向前平移 800 个字节)
        for(int i = maxSize; i < oldPoints.count(); i++){
            points.append(QPointF(i - maxSize, oldPoints.at(i).y()));
        }
    }

    qint64 size = points.count();
    for(int k = 0; k < maxSize; k++){ // 数据块内的数据填充序列的尾部
        points.append(QPointF(k + size, (quint8)data[k]));
    }

    m_series->replace(points);
    emit updateBlockSize(maxSize);
    return maxSize;
}
