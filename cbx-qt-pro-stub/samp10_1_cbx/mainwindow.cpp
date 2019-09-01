#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniGraph3D(); // 创建三维图表
    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(ui->groupBox); // 左侧控制面板
    splitter->addWidget(graphContainer); // 右侧控制图表
    this->setCentralWidget(splitter);

    ui->hSliderZoom->setMaximum(500);
    ui->hSliderZoom->setMinimum(10);

    ui->hSliderHRotation->setMinimum(-180);
    ui->hSliderHRotation->setMaximum(180);

    ui->hSliderVRotation->setMinimum(0);
    ui->hSliderVRotation->setMaximum(90);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniGraph3D()
{
    // 创建图表
    graph3D = new Q3DBars();
    graphContainer = QWidget::createWindowContainer(graph3D);

    // 创建坐标轴
    QStringList rowLabs;
    QStringList colLabs;
    rowLabs << "row1" << "row2" << "row3";
    colLabs << "col1" << "col2" << "col3" << "col4" << "col5";
    QValue3DAxis *axisV = new QValue3DAxis; // 数值坐标轴
    axisV->setTitle("value");
    axisV->setTitleVisible(true);
    QCategory3DAxis *axisRow = new QCategory3DAxis; // 行坐标轴
    axisRow->setTitle("row axis");
    axisRow->setTitleVisible(true);
    QCategory3DAxis *axisCol = new QCategory3DAxis; // 列坐标轴
    axisCol->setTitle("column axis");
    axisCol->setTitleVisible(true);

    graph3D->setValueAxis(axisV);
    graph3D->setRowAxis(axisRow);
    graph3D->setColumnAxis(axisCol);

    // 创建序列
    series = new QBar3DSeries;
    series->setMesh(QAbstract3DSeries::MeshCylinder); // 棒状形状
    series->setItemLabelFormat("(@rowLabel @colLabel ): %.1f"); // 标签格式
    graph3D->addSeries(series);

    // 添加数据
    QBarDataArray *dataSet = new QBarDataArray; // 数据数组
    dataSet->reserve(rowLabs.count());
    QBarDataRow *dataRow = new QBarDataRow;
    *dataRow << 1 << 2 << 3 << 4 << 5; // 第一行数据，　有5列
    dataSet->append(dataRow);

    QBarDataRow *dataRow2 = new QBarDataRow;
    *dataRow2 << 5 << 5 << 5 << 5 << 5;
    dataSet->append(dataRow2);

    QBarDataRow *dataRow3 = new QBarDataRow;
    *dataRow3 << 1 << 5 << 9 << 5 << 1; // 第３行数据，有5列
    dataSet->append(dataRow3);

    series->dataProxy()->resetArray(dataSet);
}

void MainWindow::on_cBoxPreVisualAngle_currentIndexChanged(int index)
{
    // index 是从0开始变化的
    // 变换视角
    Q3DCamera::CameraPreset cameraPos = Q3DCamera::CameraPreset(index);
    graph3D->scene()->activeCamera()->setCameraPreset(cameraPos);
}

void MainWindow::on_hSliderHRotation_valueChanged(int value)
{
    Q_UNUSED(value);
    int xRot = ui->hSliderHRotation->value(); //水平
    int yRot = ui->hSliderVRotation->value(); // 垂直
    int zoom = ui->hSliderZoom->value(); // 缩放

    graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot, zoom);
}

void MainWindow::on_hSliderVRotation_valueChanged(int value)
{
    Q_UNUSED(value);
    int xRot = ui->hSliderHRotation->value(); //水平
    int yRot = ui->hSliderVRotation->value(); // 垂直
    int zoom = ui->hSliderZoom->value(); // 缩放

    graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot, zoom);
}



void MainWindow::on_hSliderZoom_valueChanged(int value)
{
    Q_UNUSED(value);
    int xRot = ui->hSliderHRotation->value(); //水平
    int yRot = ui->hSliderVRotation->value(); // 垂直
    int zoom = ui->hSliderZoom->value(); // 缩放

    graph3D->scene()->activeCamera()->setCameraPosition(xRot, yRot, zoom);
}

void MainWindow::on_cBoxTheme_currentIndexChanged(int index)
{
    // 设置主题
    Q3DTheme *currentTheme = graph3D->activeTheme();
    currentTheme->setType(Q3DTheme::Theme(index));
}

void MainWindow::on_ckBoxDisplayBackground_clicked(bool checked)
{
    // 图表的背景
    graph3D->activeTheme()->setBackgroundEnabled(checked);
}

void MainWindow::on_ckBoxDisplayBackgroudGrid_clicked(bool checked)
{
    // 图表的网格
    graph3D->activeTheme()->setGridEnabled(checked);
}

void MainWindow::on_ckBoxAxisLabBackgroundVisible_clicked(bool checked)
{
    // 轴标签背景
    graph3D->activeTheme()->setLabelBackgroundEnabled(checked);
}

void MainWindow::on_cBoxSelectMode_currentIndexChanged(int index)
{
    // 选择模式
    graph3D->setSelectionMode(QAbstract3DGraph::SelectionFlags(index));
}

void MainWindow::on_cBoxBarStyle_currentIndexChanged(int index)
{
    // 棒图的样式
    QAbstract3DSeries::Mesh aMesh;
    aMesh = QAbstract3DSeries::Mesh(index);
    series->setMesh(aMesh);
}

void MainWindow::on_ckBoxValueAxisReverse_clicked(bool checked)
{
    // 数值轴反向
    graph3D->valueAxis()->setReversed(checked);
}
