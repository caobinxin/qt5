#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QWidget>
#include <QTime>
#include <QtCharts>
using namespace QtCharts;

#include <QLineSeries>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>


#define fixedColumnCount 5 // 数据模型的列数
#define iniDataRowCount 10 // 学生的个数
#define colNoName 0 // 姓名的列编号
#define colNoMath 1 // 数学的列编号
#define colNoChinese 2 // 语文的列编号
#define colNoEnglish 3 // 英语的列编号
#define colNoAverage 4 // 平均分的列编号

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
    QStandardItemModel *theModel; // 数据模型
    void iniData(); // 初始化数据
    void surveyData(); // 统计数据

    void iniBarChart(); // 柱状图初始化
    void buildBarChart(); // 创建柱状图

    void iniPiewChart(); // 饼图
    void buildPiewChart(); //

    void iniStackedBar(); // 堆叠图
    void buildStackedBar();

    void iniPercentBar(); // 百分比柱状图
    void buildPercentBar();

    void iniScatterChart(); // 散点图
    void buildScatterChart();

private slots:
    // 三个分散列的数据发生变化，重新计算平均分
    void on_itemChanged(QStandardItem *item);

    void on_pBtnBar_clicked();

    void on_PieSliceHighlight(bool show);
};

#endif // MAINWINDOW_H
