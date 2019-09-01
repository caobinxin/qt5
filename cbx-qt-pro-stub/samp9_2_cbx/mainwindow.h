#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
using namespace QtCharts;


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
    void on_btnSettingTitleName_clicked();

    void on_btnTitleFont_clicked();

    void on_rdbtnUp_clicked();

    void on_rdbtnDown_clicked();

    void on_rdbtnLift_clicked();

    void on_rdbtnRight_clicked();

    void on_cBoxLegendVisible_stateChanged(int arg1);

    void on_cBoxBGVisual_stateChanged(int arg1);

    void on_btnLegendFont_clicked();

    void on_btnLableColor_clicked();

    void on_btnSettingMargin_clicked();

    void on_cBoxAnimation_currentIndexChanged(int index);

    void on_cBoxTheme_currentIndexChanged(int index);

    void on_rBtnSin_clicked();

    void on_rBtnCos_clicked();

    void on_pBtnSeqName_clicked();

    void on_cBoxSeqVisbile_clicked();

    void on_cBoxDataPointVisbile_clicked();

    void on_pBtnSeqColor_clicked();

    void on_pBtnSeqPen_clicked();

    void on_hSliderTransparency_valueChanged(int value);

    void on_cBoxPointLableVisbile_clicked();

    void on_labColor_clicked();

    void on_labFont_clicked();

    void on_rBtnyPont_clicked();

    void on_rBtnxy_clicked();

    void on_rBtnXAxis_clicked();

    void on_rBtnYAxis_clicked();

    void on_cBoxAxisVisible_clicked();

    void on_pBtnSettingAxisRange_clicked();

    void on_pBtnAxisTitleName_clicked();

    void on_cBoxAxisTitleVisible_clicked();

    void on_pBtnSettingAxisFont_clicked();

    void on_pBtnAxisLabFormat_clicked();

    void on_pBtnAxisFontColor_clicked();

    void on_pBtnSettingAxisFont_2_clicked();

    void on_cBoxAxisLabIsVisible_clicked();

private:
    Ui::MainWindow *ui;
    QLineSeries *curSeries; // 当前序列
    QValueAxis *curAxis; // 当前坐标轴
    void createChart(); // 创建图表
    void prepareData(); // 更新数据
    void updateFromChart(); // 从图表更新到界面


};

#endif // MAINWINDOW_H
