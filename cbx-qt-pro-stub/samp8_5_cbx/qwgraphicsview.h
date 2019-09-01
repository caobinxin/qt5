#ifndef QWGRAPHICSVIEW_H
#define QWGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPoint>

class QWGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    QWGraphicsView(QWidget *parent=0);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void mouseMovePoint(QPoint point);// 鼠标移动
    void mouseClicked(QPoint point); // 鼠标单击
    void mouseDoubleClick(QPoint point); // 双击事件
    void keyPress(QKeyEvent *event); // 按键事件
};

#endif // QWGRAPHICSVIEW_H
