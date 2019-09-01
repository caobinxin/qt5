#ifndef QWCHARTVIEW_H
#define QWCHARTVIEW_H
#include <QtCharts>
using namespace QtCharts;

#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>

class QWChartView : public QChartView
{

    Q_OBJECT
public:
    QWChartView(QWidget *parent = 0);

private:
    QPoint beginPoint; // 选择矩形区的起点
    QPoint endPoint; // 选择矩形区的终点

protected:
    void mousePressEvent(QMouseEvent *event); // 鼠标左键按下
    void mouseMoveEvent(QMouseEvent *event); // 鼠标移动
    void mouseReleaseEvent(QMouseEvent *event); // 鼠标释放左键
    void keyPressEvent(QKeyEvent *event); // 按键事件

signals:
    void mouseMovePoint(QPoint point); // 鼠标移动信号
};

#endif // QWCHARTVIEW_H
