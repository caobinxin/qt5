#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QChart>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->chartView);
    labXYValue = new QLabel("X= , Y= " ); // 状态栏显示鼠标点的坐标
    labXYValue->setMinimumWidth(200);
    ui->statusBar->addWidget(labXYValue);

    createChart(); // 创建图表
    prepareData(); // 生成图表

    connect(ui->chartView, SIGNAL(mouseMovePoint(QPoint)),
            this, SLOT(on_mouseMovePoint(QPoint))); // 鼠标移动事件
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createChart()
{
    // 创建图表
    QChart *chart = new QChart();
    chart->setTitle("简单曲线");
    ui->chartView->setChart(chart);

}

void MainWindow::prepareData()
{
    QChart *chart = ui->chartView->chart();
    // 创建折线序列
    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();

    series0->setName("Sin 曲线");
    series1->setName("Cos 曲线");

    chart->addSeries(series0);
    chart->addSeries(series1);

    // 序列添加数值
    qreal t = 0, y1, y2, intv = 0.1;
    int cnt = 100;
    for(int i = 0; i < cnt; i++){
        y1 = qSin(t); // +qrand()
        series0->append(t, y1);

        y2 = qSin(t + 20);
        series1->append(t, y2);
        t += intv;
    }

    //　创建坐标轴
    QValueAxis *axisX = new QValueAxis; // x　轴
    axisX->setRange(0, 10); // 设置坐标轴　范围
    axisX->setTitleText("time(secs)"); // 标准

    QValueAxis *axisY = new QValueAxis; // y 轴
    axisY->setRange(-2, 2);
    axisY->setTitleText("value");

    chart->setAxisX(axisX, series0); // 为序列设置　坐标轴
    chart->setAxisY(axisY, series0);

    chart->setAxisX(axisX, series1); // 为序列设置坐标轴
    chart->setAxisY(axisY, series1);

    foreach(QLegendMarker *marker, chart->legend()->markers()){
        connect(marker, SIGNAL(clicked()), this, SLOT(on_LegendMarkerClicked()));
    }
}

void MainWindow::on_LegendMarkerClicked()
{
    // 单击图例的 marker 的响应
    QLegendMarker *marker = qobject_cast<QLegendMarker *>(sender());
    switch (marker->type()) { // marker 的类型
        case QLegendMarker::LegendMarkerTypeXY: // QLineSeries 序列
    {
        marker->series()->setVisible(!marker->series()->isVisible());
        marker->setVisible(true);
    }

    }
}

void MainWindow::on_mouseMovePoint(QPoint point)
{
    // 鼠标移动响应
    QPointF pt = ui->chartView->chart()->mapToValue(point); // 转换为图表的数值
    labXYValue->setText(QString::asprintf("X=%.1f, Y=%.2f", pt.x(), pt.y()));

}

void MainWindow::on_actZoomReset_triggered()
{
    ui->chartView->chart()->zoomReset(); // 恢复原始大小
}

void MainWindow::on_actZoomIn_triggered()
{
    ui->chartView->chart()->zoom(1.2); // 放大
}

void MainWindow::on_actZoomOut_triggered()
{
    ui->chartView->chart()->zoom(0.8); // 缩小
}
