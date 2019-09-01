#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDialog>
#include "qwdialogpen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createChart(); // 创建图表
    prepareData(); // 生成数据
    updateFromChart(); // 从图表获得属性值，刷新界面显示
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createChart()
{
    // 创建图表中的各个部件
    QChart *chart = new QChart();
    chart->setTitle("简单函数曲线");

    ui->chartView->setChart(chart);
    ui->chartView->setRenderHint(QPainter::Antialiasing);// 提示

    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();

    series0->setName("Sin 曲线");
    series1->setName("Cos 曲线");
    curSeries = series0; //　当前序列

    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setWidth(2);
    pen.setColor(Qt::red);
    series0->setPen(pen); // 折线线条的线条设置

    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::blue);
    series1->setPen(pen);

    chart->addSeries(series0);
    chart->addSeries(series1);

    QValueAxis *axisX = new QValueAxis;
    curAxis = axisX; // 当前坐标轴

    axisX->setRange(0, 10); // 设置坐标的范围
    axisX->setLabelFormat("%.1f"); // 标签格式
    axisX->setTickCount(11); // 主分隔个数
    axisX->setMinorTickCount(4);
    axisX->setTitleText("time(secs)"); // 标题

    QValueAxis *axisY = new QValueAxis;

    axisY->setRange(-2, 2);
    axisY->setTitleText("value");
    axisY->setTickCount(5);
    axisY->setLabelFormat("%.2f");
    axisY->setMinorTickCount(4);

    chart->setAxisX(axisX, series0);
    chart->setAxisY(axisY, series0);

    chart->setAxisX(axisX, series1);
    chart->setAxisY(axisY, series1);

    QStringList animationList;
    animationList << "NoAnimation" << "GridAxisAnimations" << "SeriesAnimations"<< "AllAnimations";
    ui->cBoxAnimation->clear();
    ui->cBoxAnimation->addItems(animationList);

    QStringList themeList;
    themeList << "Light" << "BlueCerulean" << "Dark" <<
                 "BrownSand" << "BlueNcs" << "HighContrast" <<
                 "BlueIcy" << "Qt";
    ui->cBoxTheme->clear();
    ui->cBoxTheme->addItems(themeList);

}

void MainWindow::prepareData()
{
    // 为序列生成数据
    QLineSeries *series0 = (QLineSeries *)ui->chartView->chart()->series().at(0);
    QLineSeries *series1 = (QLineSeries *)ui->chartView->chart()->series().at(1);

    series0->clear(); // 清除数据
    series1->clear();

    qsrand(QTime::currentTime().second()); // 随机数初始化
    qreal t = 0,y1, y2, intv = 0.1;

    qreal rd;
    int cnt = 100;
    for(int i = 0; i < cnt; i++){
        rd = (qrand() % 10) -5; // 随机数，　-5~+5
        y1 = qSin(t) + rd/50;
        series0->append(t,y1);

        rd = (qrand() % 10) -5; // 随机数，　-5~+5
        y2 = qCos(t) + rd/50;
        series1->append(t,y2);

        t += intv;
    }

}

void MainWindow::updateFromChart()
{
    // 从图表上获取数据更新界面显示
    QChart *aChart = ui->chartView->chart(); // 获取chart

    ui->editTitle->setText(aChart->title()); // 图表标题
    QMargins mg = aChart->margins(); // 边距

    //    ui->spinMarginLeft  这个留在最后在区设置
}

void MainWindow::on_btnSettingTitleName_clicked()
{
    // 设置标题的名字
    QString titleName = ui->lEditTitleName->text();
    QChart *chart = ui->chartView->chart();
    chart->setTitle(titleName);
}

void MainWindow::on_btnTitleFont_clicked()
{
    // 设置标题的文字格式
    QChart *chart = ui->chartView->chart();
    QFont curFont = chart->font();

    bool ok;
    QFont font = QFontDialog::getFont(
                &ok, curFont, this);
    if (ok) {
        chart->setTitleFont(font);
    } else {

    }
}

void MainWindow::on_rdbtnUp_clicked()
{
    // 图例显示在上方
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignTop);
}

void MainWindow::on_rdbtnDown_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
}

void MainWindow::on_rdbtnLift_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignLeft);
}

void MainWindow::on_rdbtnRight_clicked()
{
    ui->chartView->chart()->legend()->setAlignment(Qt::AlignRight);
}

void MainWindow::on_cBoxLegendVisible_stateChanged(int arg1)
{
    // 图例可显示
    if(arg1){
        ui->chartView->chart()->legend()->setVisible(true);
    }else{
        ui->chartView->chart()->legend()->setVisible(false);
    }

}

void MainWindow::on_cBoxBGVisual_stateChanged(int arg1)
{
    // 背景可显示
    if(arg1){
        ui->chartView->chart()->setBackgroundVisible(true);
    }else{
        ui->chartView->chart()->setBackgroundVisible(false);
    }
}

void MainWindow::on_btnLegendFont_clicked()
{
    // 图例的字体设置
    QFont font = ui->chartView->chart()->legend()->font();
    bool ok = false;
    font = QFontDialog::getFont(&ok, font);
    if(ok){
        ui->chartView->chart()->legend()->setFont(font);
    }
}

void MainWindow::on_btnLableColor_clicked()
{
    QColor color = ui->chartView->chart()->legend()->labelColor();
    color = QColorDialog::getColor(color,
                                   this,
                                   "选择图例的颜色",
                                   NULL);
    if(color.isValid()){
        ui->chartView->chart()->legend()->setLabelColor(color);
    }
}

void MainWindow::on_btnSettingMargin_clicked()
{
    QMargins margin;
    margin.setTop(ui->sBoxTopMargin->value());
    margin.setBottom(ui->sBoxBottomMargin->value());
    margin.setLeft(ui->sBoxLeftMargin->value());
    margin.setRight(ui->sBoxRightMargin->value());

    ui->chartView->chart()->setMargins(margin);
}

void MainWindow::on_cBoxAnimation_currentIndexChanged(int index)
{
    // 展示图表的动画
    switch (index) {
    case QChart::NoAnimation:
        ui->chartView->chart()->setAnimationOptions(QChart::NoAnimation);
        break;
    case QChart::GridAxisAnimations:
        ui->chartView->chart()->setAnimationOptions(QChart::GridAxisAnimations);
        break;
    case QChart::SeriesAnimations:
        ui->chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
        break;
    case QChart::AllAnimations:
        ui->chartView->chart()->setAnimationOptions(QChart::AllAnimations);
        break;
    default:
        break;
    }
}

void MainWindow::on_cBoxTheme_currentIndexChanged(int index)
{
    // 改变主题
    switch (index) {
    case QChart::ChartThemeLight:
        ui->chartView->chart()->setTheme(QChart::ChartThemeLight);
        break;
    case QChart::ChartThemeBlueCerulean:
        ui->chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
        break;
    case QChart::ChartThemeDark:
        ui->chartView->chart()->setTheme(QChart::ChartThemeDark);
        break;
    case QChart::ChartThemeBrownSand:
        ui->chartView->chart()->setTheme(QChart::ChartThemeBrownSand);
        break;
    case QChart::ChartThemeBlueNcs:
        ui->chartView->chart()->setTheme(QChart::ChartThemeBlueNcs);
        break;
    case QChart::ChartThemeHighContrast:
        ui->chartView->chart()->setTheme(QChart::ChartThemeHighContrast);
        break;
    case QChart::ChartThemeBlueIcy:
        ui->chartView->chart()->setTheme(QChart::ChartThemeBlueIcy);
        break;
    case QChart::ChartThemeQt:
        ui->chartView->chart()->setTheme(QChart::ChartThemeQt);
        break;
    default:
        break;
    }
}

void MainWindow::on_rBtnSin_clicked()
{
    if(ui->rBtnSin->isChecked()){
        curSeries = (QLineSeries *)ui->chartView->chart()->series().at(0);
    }else{
        curSeries = (QLineSeries *)ui->chartView->chart()->series().at(1);
    }

    // 获取序列的属性值，并显示到界面上
    ui->lEditSeqName->setText(curSeries->name());
    ui->cBoxSeqVisbile->setChecked(curSeries->isVisible());
    ui->cBoxDataPointVisbile->setChecked(curSeries->pointsVisible());
    ui->hSliderTransparency->setValue(curSeries->opacity()*10);
    ui->cBoxPointLableVisbile->setChecked(curSeries->pointLabelsVisible());

}

void MainWindow::on_rBtnCos_clicked()
{
    if(ui->rBtnCos->isChecked()){
        curSeries = (QLineSeries *)ui->chartView->chart()->series().at(1);
    }else{
        curSeries = (QLineSeries *)ui->chartView->chart()->series().at(0);
    }

    // 获取序列的属性值，并显示到界面上
    ui->lEditSeqName->setText(curSeries->name());
    ui->cBoxSeqVisbile->setChecked(curSeries->isVisible());
    ui->cBoxDataPointVisbile->setChecked(curSeries->pointsVisible());
    ui->hSliderTransparency->setValue(curSeries->opacity()*10);
    ui->cBoxPointLableVisbile->setChecked(curSeries->pointLabelsVisible());
}

void MainWindow::on_pBtnSeqName_clicked()
{
    curSeries->setName(ui->lEditSeqName->text());
}

void MainWindow::on_cBoxSeqVisbile_clicked()
{
    if(ui->cBoxSeqVisbile->isChecked()){
        curSeries->setVisible(true);
    }else{
        curSeries->setVisible(false);
    }
}

void MainWindow::on_cBoxDataPointVisbile_clicked()
{
    if(ui->cBoxDataPointVisbile->isChecked()){
        curSeries->setPointsVisible(true);
    }else{
        curSeries->setPointsVisible(false);
    }
}

void MainWindow::on_pBtnSeqColor_clicked()
{
    QColor curColor = curSeries->color();

    curColor = QColorDialog::getColor(curColor,nullptr, "选择曲线的颜色:");
    if(curColor.isValid()){
        curSeries->setColor(curColor);
    }
}

void MainWindow::on_pBtnSeqPen_clicked()
{
    QPen curPen = curSeries->pen();
    bool ok = false;
    curPen = QWDialogPen::getPen(curPen,ok);
    if(ok){
        curSeries->setPen(curPen);
    }
}
void MainWindow::on_hSliderTransparency_valueChanged(int value)
{
    qreal opacity = (qreal)value / 100;
    // 动态调整线条的透明度
    curSeries->setOpacity(opacity);
}

void MainWindow::on_cBoxPointLableVisbile_clicked()
{
    if(ui->cBoxPointLableVisbile->isChecked()){
        curSeries->setPointLabelsVisible(true);
    }else{
        curSeries->setPointLabelsVisible(false);
    }
}

void MainWindow::on_labColor_clicked()
{
    QColor color = curSeries->pointLabelsColor();

    color = QColorDialog::getColor(color,nullptr, "请选择标签颜色");

    if(color.isValid()){
        curSeries->setPointLabelsColor(color);
    }
}

void MainWindow::on_labFont_clicked()
{
    QFont font = curSeries->pointLabelsFont();
    bool ok;
    font = QFontDialog::getFont(&ok, font);
    if(ok){
        curSeries->setPointLabelsFont(font);
    }

}

void MainWindow::on_rBtnyPont_clicked()
{
    //
    curSeries->setPointLabelsFormat("@yPoint");
}

void MainWindow::on_rBtnxy_clicked()
{
    curSeries->setPointLabelsFormat("(@xPoint,@yPoint)");
}

void MainWindow::on_rBtnXAxis_clicked()
{
    // 选择x轴
    curAxis = (QValueAxis *)ui->chartView->chart()->axisX(curSeries);

    ui->sBoxMaxValueAxis->setValue(curAxis->max());
    ui->sBoxMinValueAxis->setValue(curAxis->min());

    ui->cBoxAxisVisible->setChecked(curAxis->isVisible());
    ui->lEditAxisTitleName->setText(curAxis->titleText());

    ui->cBoxAxisTitleVisible->setChecked(curAxis->isTitleVisible());
    ui->lEditAxisLabFormat->setText(curAxis->labelFormat());
    ui->cBoxAxisLabIsVisible->setChecked(curAxis->labelsVisible());
}

void MainWindow::on_rBtnYAxis_clicked()
{
    curAxis = (QValueAxis *)ui->chartView->chart()->axisY(curSeries);

    ui->sBoxMaxValueAxis->setValue(curAxis->max());
    ui->sBoxMinValueAxis->setValue(curAxis->min());

    ui->cBoxAxisVisible->setChecked(curAxis->isVisible());
    ui->lEditAxisTitleName->setText(curAxis->titleText());

    ui->cBoxAxisTitleVisible->setChecked(curAxis->isTitleVisible());
    ui->lEditAxisLabFormat->setText(curAxis->labelFormat());
    ui->cBoxAxisLabIsVisible->setChecked(curAxis->labelsVisible());
}

void MainWindow::on_cBoxAxisVisible_clicked()
{
    if(ui->cBoxAxisVisible->isChecked()){
        curAxis->setVisible(true);
    }else{
        curAxis->setVisible(false);
    }
}

void MainWindow::on_pBtnSettingAxisRange_clicked()
{
    curAxis->setMax(ui->sBoxMaxValueAxis->value());
    curAxis->setMin(ui->sBoxMinValueAxis->value());

    qreal xMax = ((QValueAxis *)ui->chartView->chart()->axisX(curSeries))->max();
    QLineSeries * series0 = ((QLineSeries*)ui->chartView->chart()->series().at(0));
    QLineSeries * series1 = ((QLineSeries*)ui->chartView->chart()->series().at(1));

    series0->clear();
    series1->clear();

    qreal t = 0, y1, y2, intv = 0.1;
    qreal rd;
    int cnt = (int)xMax * 10;
    for(int i = 0; i < cnt; i++){
        rd = (qrand() % 10) -5; // 随机数，　-5~+5
        y1 = qSin(t) + rd/50;
        series0->append(t,y1);

        rd = (qrand() % 10) -5; // 随机数，　-5~+5
        y2 = qCos(t) + rd/20;
        series1->append(t,y2);

        t += intv;
    }
}

void MainWindow::on_pBtnAxisTitleName_clicked()
{
    curAxis->setTitleText(ui->lEditAxisTitleName->text());
}

void MainWindow::on_cBoxAxisTitleVisible_clicked()
{
    if(ui->cBoxAxisTitleVisible->isChecked()){
        curAxis->setTitleVisible(true);
    }else{
        curAxis->setTitleVisible(false);
    }
}

void MainWindow::on_pBtnSettingAxisFont_clicked()
{
    QFont font = curAxis->titleFont();
    bool ok = false;
    font = QFontDialog::getFont(&ok, this);
    if(ok){
        curAxis->setTitleFont(font);
    }
}

void MainWindow::on_pBtnAxisLabFormat_clicked()
{
    curAxis->setLabelsFont(ui->lEditAxisLabFormat->text());
}

void MainWindow::on_pBtnAxisFontColor_clicked()
{
    QColor color = curAxis->labelsColor();
    color = QColorDialog::getColor(color,this, "选择轴标签颜色");
    if(color.isValid()){
        curAxis->setLabelsColor(color);
    }
}

void MainWindow::on_pBtnSettingAxisFont_2_clicked()
{
    QFont font = curAxis->labelsFont();
    bool ok = false;
    font = QFontDialog::getFont(&ok, this);
    if(ok){
        curAxis->setLabelsFont(font);
    }
}

void MainWindow::on_cBoxAxisLabIsVisible_clicked()
{
    bool check = ui->cBoxAxisLabIsVisible->isChecked();
    if(check){
        curAxis->setLabelsVisible(true);
    }else{
        curAxis->setLabelsVisible(false);
    }
}
