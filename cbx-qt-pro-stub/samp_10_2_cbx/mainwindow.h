#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDataVisualization>
using namespace QtDataVisualization;

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
    QWidget *graphContainer; // 图表的容器
    Q3DScatter *graph3D; // 散点图
    QScatter3DSeries *series; // 散点序列
    void iniGraph3D(); // 初始化绘图


};

#endif // MAINWINDOW_H
