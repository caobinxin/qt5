#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include <QPoint>
#include <QKeyEvent>

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
    static const int ItemId = 1; // 图形项自定义数据的Key
    static const int ItemDesciption = 2; // 图形项自定义数据的Key
    int seqNum = 0; // 用于图形项的编号，每个图形有一个编号
    int frontZ = 0; // 用于 设置图形项的叠放顺序，数值越大，越在前面显示
    int backZ = 0; // 用于 数值越小，越在后面显示

    QGraphicsScene *scene; // 场景
    QLabel *labViewCord;
    QLabel *labSceneCord;
    QLabel *labItemCord;
    QLabel *labItemInfo;

    template <class T> void setBrushColor(T *item);

private slots:
    void on_mouseMovePoint(QPoint point); // 鼠标移动
    void on_mouseClicked(QPoint point); // 鼠标单击
    void on_mouseDoubleClick(QPoint point);// 鼠标双击
    void on_keyPress(QKeyEvent *event);// 按键
    void on_actItem_Polygon_triggered();
    void on_actItem_Ellipse_triggered();
    void on_actItem_Rect_triggered();
    void on_actItem_Line_triggered();
    void on_actItem_Pixmap_triggered();
    void on_actItem_Text_triggered();
    void on_actItem_Circle_triggered();
    void on_actItem_Triangle_triggered();
    void on_actZoomIn_triggered();
    void on_actZoomOut_triggered();
    void on_actRotateLeft_triggered();
    void on_actRotateRight_triggered();
    void on_actRestore_triggered();
    void on_actEdit_Front_triggered();
    void on_actEdit_Back_triggered();
    void on_actGroup_triggered();
    void on_actGroupBreak_triggered();
    void on_actEdit_Delete_triggered();
};

#endif // MAINWINDOW_H
