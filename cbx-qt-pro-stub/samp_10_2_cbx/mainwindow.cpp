#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    iniGraph3D();

    this->setCentralWidget(graphContainer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniGraph3D()
{
    graph3D = new Q3DScatter();
    graphContainer = QWidget::createWindowContainer(graph3D);
    QScatterDataProxy *proxy = new QScatterDataProxy(); // 数据代理
    series = new QScatter3DSeries(proxy); // 创建序列
    series->setItemLabelFormat("(@xLabel @yLabel @zLabel)");
    series->setMeshSmooth(true);
    graph3D->addSeries(series);

    // 创建坐标轴
    graph3D->axisX()->setTitle("axis X");
    graph3D->axisX()->setTitleVisible(true);

    graph3D->axisY()->setTitle("axis Y");
    graph3D->axisY()->setTitleVisible(true);

    graph3D->axisZ()->setTitle("axis Z");
    graph3D->axisZ()->setTitleVisible(true);

    graph3D->activeTheme()->setLabelBackgroundEnabled(false);
    series->setMesh(QAbstract3DSeries::MeshSphere); // 数据点为圆球
    series->setItemSize(0.02); // 取值范围 0 ~ 1

    int N = 100;
    int itemCount = N*N;// 有 N*N 个点
    QScatterDataArray *dataArray = new QScatterDataArray();
    dataArray->resize(itemCount);
    QScatterDataItem *ptrToDataArray = &dataArray->first();

    // 墨西哥草帽, -10:0.5:10. N=41
    float x,y,z;
    int i, j;
    x = -10;
    for(i = 1; i <= N; i++){
        y = -10;
        for(j = 1; j <= N; j++){
            z = qSqrt(x*x + y*y);
            if(z != 0){
                z = 10 *qSin(z) / z;
            }else{
                z = 10;
            }
            ptrToDataArray->setPosition(QVector3D(x,z,y));
            ptrToDataArray++;
            y+=0.5;
        }
        x+=0.5;
    }
    series->dataProxy()->resetArray(dataArray);
}
