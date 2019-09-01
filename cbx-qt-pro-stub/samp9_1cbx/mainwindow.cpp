#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QChart>
#include <QChartView>
#include <QLineSeries>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createChart()
{
    // 创建图表
    QChartView *chartView = new QChartView(this); // 创建 chartView
    QChart *chart = new QChart(); // 创建 Chart
    chart->setTitle("简单函数曲线");

    chartView->setChart(chart); // chart 添加到　chartView
    this->setCentralWidget(chartView);

    // 创建折线序列
    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();

    series0->setName("Sin 曲线 ");
    series1->setName("Cos 曲线");

    chart->addSeries(series0);
    chart->addSeries(series1);

    // 序列添加数值
    qreal t = 0, y1, y2, intv = 0.1;
    int cnt = 1000;
    for (int i = 0; i < cnt; i++){
        y1 = qSin(t); // +qrand();
        series0->append(t, y1);
        y2 = qSin(t + 20);
        series1->append(t, y2);
        t += intv;
    }

    // 创建坐标轴
    QValueAxis *axisX = new QValueAxis; // x轴
    axisX->setRange(0, 10); // 设置坐标轴范围
    axisX->setTitleText("time(secs)");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-2,2);
    axisY->setTitleText("value");

    chart->setAxisX(axisX, series0);
    chart->setAxisY(axisY, series0);

    chart->setAxisX(axisX, series1);
    chart->setAxisY(axisY, series1);
}
