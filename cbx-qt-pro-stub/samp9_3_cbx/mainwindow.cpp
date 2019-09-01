#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QBarSet>
#include    <QTime>
#include    <QBarSet>
#include    <QInputDialog>
#include <QPieSlice>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    theModel = new QStandardItemModel(iniDataRowCount, fixedColumnCount, this);
    iniData(); // 初始化数据
    surveyData(); // 数据统计

    // 数据模块的　itemChanged信号和自定义的槽函数关联，用于自动计算平均分
    connect(theModel, SIGNAL(itemChanged(QStandardItem *)), this, SLOT(on_itemChanged(QStandardItem *)));

    ui->tableView->setModel(theModel); // 设置数据模型

    iniBarChart(); // 初始化柱状图
    iniPiewChart();
    iniStackedBar();
    iniPercentBar();
    iniScatterChart();

    buildBarChart();
    buildPiewChart();
    buildPercentBar();
    buildStackedBar();
    buildScatterChart();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniData()
{
    // 数据初始化
    QStringList headerList;
    headerList << "姓名" << "数学" << "语文" << "英语" << "平均分";
    theModel->setHorizontalHeaderLabels(headerList); // 设置表头文字
    qsrand(QTime::currentTime().second()); // 随机数种子

    for(int i = 0; i < theModel->rowCount(); i++){
        QString studName = QString::asprintf("学生%2d", i+1);
        QStandardItem *aItem = new QStandardItem(studName); // 创建 item
        aItem->setTextAlignment(Qt::AlignHCenter);

        theModel->setItem(i, colNoName, aItem); // 学生列，　设置item
        qreal avgScore = 0;

        for(int j = colNoMath; j <= colNoEnglish; j++){
            // 不包含最后一列
            qreal score = 50.0 + (qrand() % 50); // 随机数
            avgScore += score;
            aItem = new QStandardItem(QString::asprintf("%.0f", score));
            aItem->setTextAlignment(Qt::AlignHCenter);
            theModel->setItem(i, j, aItem); // 设置Item
        }

        aItem = new QStandardItem(QString::asprintf("%.1f", avgScore / 3)); // 平均分
        aItem->setTextAlignment(Qt::AlignHCenter);
        aItem->setFlags(aItem->flags() & (!Qt::ItemIsEditable)); // 不允许编辑
        theModel->setItem(i, colNoAverage, aItem);
    }

}
#include <QtDebug>
void MainWindow::surveyData()
{//数据统计
    int cnt50,cnt60,cnt70,cnt80,cnt90;

    qreal   sumV,minV,maxV;
    qreal   val;
    QTreeWidgetItem *item; //节点

    int i,j;
    for(i=colNoMath;i<=colNoAverage;i++)
    {
        sumV=0;
        cnt50=0;
        cnt60=0;
        cnt70=0;
        cnt80=0;
        cnt90=0;

        for(j=0;j<theModel->rowCount();j++)
        {
            val=theModel->item(j,i)->text().toDouble();
            ////////////////////////////
            if (j==0)
            {
                minV=val;
                maxV=val;
            }
            if (val<minV)
                minV=val;
            if (val>maxV)
                maxV=val;
            //////////////////////////
            sumV+=val;

            if (val<60)
                cnt50++;
            else if ((val>=60) && (val<70))
                cnt60++;
            else if ((val>=70) && (val<80))
                cnt70++;
            else if ((val>=80) && (val<90))
                cnt80++;
            else
                cnt90++;
        }
        //////////
        item=ui->treeWidget->topLevelItem(0); //<60
        item->setText(i,QString::number(cnt50));
        item->setTextAlignment(i,Qt::AlignHCenter);


        item=ui->treeWidget->topLevelItem(1); //60
        item->setText(i,QString::number(cnt60));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(2); //70
        item->setText(i,QString::number(cnt70));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(3); //80
        item->setText(i,QString::number(cnt80));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(4); //90
        item->setText(i,QString::number(cnt90));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(5); //average
        item->setText(i,QString::number(sumV/theModel->rowCount()));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(6); //max
        item->setText(i,QString::number(maxV));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(7); //min
        item->setText(i,QString::number(minV));
        item->setTextAlignment(i,Qt::AlignHCenter);
    }

}

void MainWindow::iniBarChart()
{
    // 柱状图初始化
    QChart *chart = new QChart();
    chart->setTitle("柱状图演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    ui->chartViewBar->setChart(chart);
    ui->chartViewBar->setRenderHint(QPainter::Antialiasing);

}

void MainWindow::buildBarChart()
{
    // 构造柱状图
    QChart *chart = ui->chartViewBar->chart(); // 获取　chartView 关联的 chart
    chart->removeAllSeries(); // 删除所有的序列
    chart->removeAxis(chart->axisX()); // 删除所有的坐标轴
    chart->removeAxis(chart->axisY());

    //创建三个　QBarSet 数据集，从数据模型的表头获取name

    QBarSet *setMath = new QBarSet(theModel->horizontalHeaderItem(colNoMath)->text());
    QBarSet *setChinese = new QBarSet(theModel->horizontalHeaderItem(colNoChinese)->text());
    QBarSet *setEnglish = new QBarSet(theModel->horizontalHeaderItem(colNoEnglish)->text());

    QLineSeries *Line = new QLineSeries(); // 用于显示平均分
    Line->setName(theModel->horizontalHeaderItem(colNoAverage)->text());

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    Line->setPen(pen);


    for(int i = 0; i < theModel->rowCount(); i++){
        // 从数据模型获取数据
        setMath->append(theModel->item(i, colNoMath)->text().toInt());
        setChinese->append(theModel->item(i, colNoChinese)->text().toInt());
        setEnglish->append(theModel->item(i, colNoEnglish)->text().toInt());

        Line->append(QPointF(i, theModel->item(i, colNoAverage)->text().toFloat()));
    }

    // 创建一个柱状图序列　QBarSeries, 并添加三个数据集
    QBarSeries *series = new QBarSeries();
    series->append(setMath);
    series->append(setChinese);
    series->append(setEnglish);

    chart->addSeries(series); // 添加柱状图序列
    chart->addSeries(Line); // 添加折线图序列

    // 用于横坐标的字符串列表，即学生姓名
    QStringList categories;
    for(int i = 0; i < theModel->rowCount(); i++){
        categories << theModel->item(i, colNoName)->text();

        // 用于柱状图的横坐标轴
        QBarCategoryAxis *axisX = new QBarCategoryAxis();
        axisX->append(categories); // 添加横坐标文字列表
        chart->setAxisX(axisX, series); // 设置横坐标
        chart->setAxisX(axisX, Line);

        axisX->setRange(categories.at(0), categories.at(categories.count() -1));

        // 数值型坐标作为纵坐标

        QValueAxis *axisY = new QValueAxis;
        axisY->setRange(0, 100);
        axisY->setTitleText("分数");
        axisY->setTickCount(6);

        axisY->setLabelFormat("%.0f"); // 标签格式
        chart->setAxisY(axisY, series);
        chart->setAxisY(axisY, Line);

        chart->legend()->setVisible(true); // 显示图例
        chart->legend()->setAlignment(Qt::AlignBottom); // 图例显示在下方
    }
}

void MainWindow::iniPiewChart()
{
//    // 饼状图初始化
//    QChart *chart = new QChart();
//    chart->setTitle("饼状图演示");
//    chart->setAnimationOptions(QChart::SeriesAnimations);

//    ui->chartViewPiew->setChart(chart);
//    ui->chartViewPiew->setRenderHint(QPainter::Antialiasing);

    QChart *chart = new QChart();
    chart->setTitle(" Piechart演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    ui->chartViewPiew->setChart(chart);
    ui->chartViewPiew->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::buildPiewChart()
{
//    // 绘制饼图
//    QChart *chart = ui->chartViewPiew->chart();

//    chart->removeAllSeries();

//    int colNo = 1 + ui->cBoxSubject->currentIndex(); // 获取分析对象
//    qDebug()<<"分析的科目为:" << colNo;

//    QPieSeries *series = new QPieSeries(); // 创建饼图的序列
//    series->setHoleSize(ui->dSpinBoxHoleSize->value()); // 饼图中间空心的大小
//    for(int i = 0; i <= 4; i++){
//        QTreeWidgetItem *item = ui->treeWidget->topLevelItem(i);// 拿对应的区间段
//        series->append(item->text(0), item->text(colNo).toFloat());// 拿区间段的数据 人数
//    }

//    QPieSlice *slice; // 饼图分块
//    for(int i = 0; i <= 4; i++){
//        // 设置每个分块的标签文字
//        slice = series->slices().at(i); // 获取分块
//        slice->setLabel(slice->label() + QString::asprintf("%.0f 人, %.1f%%", slice->value(), slice->percentage() * 100));
//        connect(slice, SIGNAL(hovered(bool)), this, SLOT(on_PieSliceHighlight(bool)));
//    }

//    slice->setExploded(true); // 最后一个设置为　exploded
//    series->setLabelsVisible(true); // 必须添加完 slice 之后再设置
//    chart->addSeries(series); // 添加饼图的序列
//    chart->setTitle("Piechart ---" + ui->cBoxSubject->currentText());
//    chart->legend()->setVisible(true); // 图例
//    chart->legend()->setAlignment(Qt::AlignRight);


    //绘制饼图
        QChart *chart =ui->chartViewPiew->chart(); //获取chart对象
        chart->removeAllSeries(); //删除所有序列

        int colNo=1+ui->cBoxSubject->currentIndex(); //获取分析对象，数学、英语、语文或平均分

        QPieSeries *series = new QPieSeries(); //创建饼图序列
        series->setHoleSize(ui->dSpinBoxHoleSize->value()); //饼图中间空心的大小

        for (int i=0;i<=4;i++) //添加分块数据
        {
            QTreeWidgetItem*  item=ui->treeWidget->topLevelItem(i); //获得QTreeWidgetItem的item
            series->append(item->text(0),item->text(colNo).toFloat()); //添加一个饼图分块数据,标签，数值
        }

        QPieSlice *slice; //饼图分块
        for(int i=0;i<=4;i++) //设置每个分块的标签文字
        {
            slice =series->slices().at(i);  //获取分块
            slice->setLabel(slice->label()+QString::asprintf(": %.0f人, %.1f%%",    //设置分块的标签
                            slice->value(),slice->percentage()*100));
    //信号与槽函数关联，鼠标落在某个分块上时，此分块弹出
            connect(slice, SIGNAL(hovered(bool)),
                    this, SLOT(on_PieSliceHighlight(bool)));
        }
        slice->setExploded(true); //最后一个设置为exploded
        series->setLabelsVisible(true); //只影响当前的slices，必须添加完slice之后再设置
        chart->addSeries(series); //添加饼图序列
        chart->setTitle("Piechart----"+ui->cBoxSubject->currentText());

        chart->legend()->setVisible(true); //图例
        chart->legend()->setAlignment(Qt::AlignRight);//Qt::AlignRight
}

void MainWindow::iniStackedBar()
{
    // 饼状图初始化
    QChart *chart = new QChart();
    chart->setTitle("堆叠图演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    ui->chartViewStacked->setChart(chart);
    ui->chartViewStacked->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::buildStackedBar()
{
    // 绘制　叠加柱状图
    QChart *chart = ui->chartViewStacked->chart();
    chart->removeAllSeries();
    chart->removeAxis(chart->axisX());
    chart->removeAxis(chart->axisY());

    // 创建三门课程的数据集
    QBarSet *setMath = new QBarSet(theModel->horizontalHeaderItem(colNoMath)->text());
    QBarSet *setChinese = new QBarSet(theModel->horizontalHeaderItem(colNoChinese)->text());
    QBarSet *setEnglish = new QBarSet(theModel->horizontalHeaderItem(colNoEnglish)->text());

    for(int i = 0; i < theModel->rowCount(); i++){
        // 添加分数数据到数据集
        setMath->append(theModel->item(i, colNoMath)->text().toInt());
        setChinese->append(theModel->item(i, colNoChinese)->text().toInt());
        setEnglish->append(theModel->item(i, colNoEnglish)->text().toInt());

    }

    // 创建　QStackBarSeries 对象并添加数据集
    QStackedBarSeries *series = new QStackedBarSeries();
    series->append(setMath);
    series->append(setChinese);
    series->append(setEnglish);

    series->setLabelsVisible(true); // 显示每段的标签
    chart->addSeries(series);

    // 创建横轴
    QStringList categories;
    for(int i = 0; i < theModel->rowCount(); i++){
        categories << theModel->item(i, colNoName)->text();
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis(); // 类别坐标系作为横轴

    axisX->append(categories);
    chart->setAxisX(axisX, series);
    axisX->setRange(categories.at(0), categories.at(categories.count() - 1));

    QValueAxis *axisY = new QValueAxis; // 数值坐标轴，　作为纵轴
    axisY->setRange(0, 300);
    axisY->setTitleText("总分");
    axisY->setTickCount(6);
    axisY->setLabelFormat("%.0f"); // 标签格式
    chart->setAxisY(axisY, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
}

void MainWindow::iniPercentBar()
{
    // 饼状图初始化
    QChart *chart = new QChart();
    chart->setTitle("百分比图演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    ui->chartViewPercent->setChart(chart);
    ui->chartViewPercent->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::buildPercentBar()
{
    // 绘制百分比柱状图

    QChart *chart = ui->chartViewPercent->chart();
    chart->removeAxis(chart->axisX());
    chart->removeAxis(chart->axisY());
    chart->removeAllSeries();

    // 创建数据集
    QBarSet *setMath = new QBarSet(theModel->horizontalHeaderItem(colNoMath)->text());
    QBarSet *setChinese = new QBarSet(theModel->horizontalHeaderItem(colNoChinese)->text());
    QBarSet *setEnglish = new QBarSet(theModel->horizontalHeaderItem(colNoEnglish)->text());

    QStringList categories;
    QTreeWidgetItem *item;
    for(int i = 0; i <= 4; i++){
        item = ui->treeWidget->topLevelItem(i);
        categories<< item->text(0);

        setMath->append(item->text(colNoMath).toFloat());
        setChinese->append(item->text(colNoChinese).toFloat());
        setEnglish->append(item->text(colNoEnglish).toFloat());
    }

    QPercentBarSeries *series = new QPercentBarSeries(); // 序列
    series->append(setMath);
    series->append(setChinese);
    series->append(setEnglish);

    series->setLabelsVisible(true); // 显示百分比
    chart->addSeries(series);

    QBarCategoryAxis *axisX = new QBarCategoryAxis(); // 横坐标
    axisX->append(categories);
    chart->setAxisX(axisX, series);
    axisX->setRange(categories.at(0), categories.at(categories.count() - 1));

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 100);
    axisY->setTitleText("百分比");
    axisY->setTickCount(10);
    axisY->setLabelFormat("%.1f");
    chart->setAxisY(axisY, series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
}

void MainWindow::iniScatterChart()
{
    // 散点图初始化
    QChart *chart = new QChart();
    chart->setTitle("散点图演示");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    ui->chartViewScatter->setChart(chart);
    ui->chartViewScatter->setRenderHint(QPainter::Antialiasing);
}


void MainWindow::buildScatterChart()
{
    qDebug() << __func__ << __LINE__;
    // 绘制　QScatterSeries 和 QSplineSeries 图
    QChart *chart = ui->chartViewScatter->chart();
    chart->removeAllSeries();
    chart->removeAxis(chart->axisX());
    chart->removeAxis(chart->axisY());
qDebug() << __func__ << __LINE__;
    QSplineSeries *seriesLine = new QSplineSeries(); // 光滑曲线序列
    seriesLine->setName("spline");

    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    seriesLine->setPen(pen);
qDebug() << __func__ << __LINE__;
    QScatterSeries *series0 = new QScatterSeries; // 散点序列
    series0->setName("散点");
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setBorderColor(Qt::black);
    series0->setBrush(QBrush(Qt::red));

    series0->setMarkerSize(12);
qDebug() << __func__ << __LINE__;
    qsrand(QTime::currentTime().second()); // 随机数种子
    for(int i = 0; i < 10; i++){
        int x = (qrand() %20); // 0 到　20 之间的随机数
        int y = (qrand() %20);

        series0->append(x, y); // 散点序列
        seriesLine->append(x, y); // 光滑曲线序列
    }
qDebug() << __func__ << __LINE__;
    chart->createDefaultAxes(); // 创建缺省的坐标轴
qDebug() << __func__ << __LINE__;
    chart->axisX()->setTitleText("x 轴");
qDebug() << __func__ << __LINE__;
    chart->axisX()->setRange(-2, 22);
qDebug() << __func__ << __LINE__;
    chart->axisY()->setTitleText("y 轴");
    chart->axisY()->setRange(-2, 22);
qDebug() << __func__ << __LINE__;
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
}

void MainWindow::on_itemChanged(QStandardItem *item)
{
    // 自动计算平均分
    if(item->column() < colNoMath || item->column() > colNoEnglish){
        return; // 如果被修改的item不是　数学、语文、英语，就退出
    }

    int rowNo = item->row(); // 获取数据的行编号
    qreal avg = 0;
    QStandardItem *aItem;

    for(int i = colNoMath; i <= colNoEnglish; i++){
        // 获取三个分数的和
        aItem = theModel->item(rowNo, i);
        avg += aItem->text().toDouble();
    }

    avg = avg / 3; // 计算平均分
    aItem = theModel->item(rowNo, colNoAverage); // 获取平均分数据的item
    aItem->setText(QString::asprintf("%.1f", avg));



    buildBarChart();
    buildPiewChart();
}

void MainWindow::on_pBtnBar_clicked()
{
    buildBarChart();
}

void MainWindow::on_PieSliceHighlight(bool show)
{
//    qDebug() << __func__ << __LINE__;
//    // 鼠标移入，　移出　时　发射hovered()信号, 动态设置 exploded效果
//    QPieSlice *slice = (QPieSlice *)sender();
//    slice->setExploded(show);

    QPieSlice *slice;
    slice=(QPieSlice *)sender();
//    slice->setLabelVisible(show);
    slice->setExploded(show);
}
