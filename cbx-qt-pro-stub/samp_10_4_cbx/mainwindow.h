#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDataVisualization>
using namespace QtDataVisualization;
#include <QColorDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbtnBarColor_clicked();

    void on_btnGrad1_clicked();

private:
    Ui::MainWindow *ui;

private:
    QWidget *graphContainer;
    Q3DSurface *graph3D; // 三维图表
    QSurface3DSeries *series; // 序列
    QSurfaceDataProxy *proxy; // 数据代理
    void iniGraph3D();
};

#endif // MAINWINDOW_H