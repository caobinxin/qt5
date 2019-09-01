#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
using namespace QtCharts;

#include <QLabel>
#include <QPoint>
#include "qwchartview.h"
#include <QLineSeries>

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
    QLabel *labXYValue; // 状态栏显示文字标签
    void createChart(); // 创建图表
    void prepareData(); // 准备数据

private slots:
    void on_LegendMarkerClicked(); // 图例单击槽函数，自定义槽函数
    void on_mouseMovePoint(QPoint point);


    void on_actZoomReset_triggered(); // 工具栏按钮，原始大小
    void on_actZoomIn_triggered(); // 工具栏按钮，放大
    void on_actZoomOut_triggered(); // 工具栏按钮，缩小
};

#endif // MAINWINDOW_H
