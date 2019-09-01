#include "qwgraphicsview.h"
#include <QMouseEvent>
#include <QGraphicsView>

void QWGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标移动事件
    QPoint point = event->pos(); // QGraphicsView 的坐标 , 这里获取的是视图中的坐标
    emit mouseMovePoint(point); // 发射信号
    QGraphicsView::mouseMoveEvent(event);

}

void QWGraphicsView::mousePressEvent(QMouseEvent *event)
{
    // 鼠标左键被按下事件
    if(event->button() == Qt::LeftButton){
        QPoint point = event->pos(); // QGraphicsView 的坐标
        emit mouseClicked(point); // 发射信号
    }

    QGraphicsView::mousePressEvent(event);
}

QWGraphicsView::QWGraphicsView(QWidget *parent)
{

}
