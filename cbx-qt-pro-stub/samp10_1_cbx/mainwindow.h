#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDataVisualization>
using namespace QtDataVisualization;

#include <QSplitter>
#include <Q3DBars>
#include <QtDebug>
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
    void on_cBoxPreVisualAngle_currentIndexChanged(int index);

    void on_hSliderHRotation_valueChanged(int value);

    void on_hSliderVRotation_valueChanged(int value);

    void on_hSliderZoom_valueChanged(int value);

    void on_cBoxTheme_currentIndexChanged(int index);

    void on_ckBoxDisplayBackground_clicked(bool checked);

    void on_ckBoxDisplayBackgroudGrid_clicked(bool checked);

    void on_ckBoxAxisLabBackgroundVisible_clicked(bool checked);

    void on_cBoxSelectMode_currentIndexChanged(int index);

    void on_cBoxBarStyle_currentIndexChanged(int index);

    void on_ckBoxValueAxisReverse_clicked(bool checked);

private:
    Ui::MainWindow *ui;

private:
    QWidget *graphContainer; // 图表的容器
    Q3DBars *graph3D; // 图表
    QBar3DSeries *series; // 图表的序列
    void iniGraph3D(); // 创建图表
    void iniGHTGraph3D(); // 创建高程图

};

#endif // MAINWINDOW_H
