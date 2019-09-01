#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int W = width();
    int H = height();

    int side = qMin(W, H); // 取长和宽的较小值
//    QRect rect((W-side)/2, (H-side)/2, side, side); // viewPort矩形区　视口
    QRect rect(0, 0, 400, 400);
    painter.drawRect(rect); // viewPort的矩形区域
    painter.setViewport(rect); // 设置视口
    painter.setWindow(-200, -200, 400, 400); // 设置窗口大小，逻辑坐标
    painter.setRenderHint(QPainter::Antialiasing);

    // 设置画笔
    QPen pen;
    pen.setWidth(1); // 线宽
    pen.setColor(Qt::red); // 划线的颜色
    pen.setStyle(Qt::SolidLine); //线的类型
    painter.setPen(pen);

    for(int i = 0;  i < 360; i++){
        painter.drawEllipse(QPoint(100,0), 100, 100); // 画完一个圆
        painter.rotate(10);// 旋转10度
    }

//    addGradient();// 用渐变去画圆
}

void Widget::addGradient()
{
    QPainter painter(this);
    int W = width();
    int H = height();

    int side = qMin(W, H);// 取长和宽的较小值
    QRect rect((W-side)/2, (H-side)/2, side, side); // viewPort 矩形区域
    painter.drawRect(rect); // viewport 大小
    painter.setViewport(rect); // 设置viewport大小
    painter.setWindow(-100, -100, 200, 200); // 设置窗口大小,逻辑坐标
    painter.setRenderHint(QPainter::Antialiasing);

    // 设置画笔
    QPen pen;
    pen.setWidth(1); // 线宽
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine); // 线的类型
    painter.setPen(pen);

    // 线性渐变
    QLinearGradient linearGrad(0,0,100,0); // 从左到右，
    linearGrad.setColorAt(0, Qt::yellow); // 起到颜色
//    linearGrad.setColorAt(0.5, Qt::red); // 中间点的颜色
    linearGrad.setColorAt(1, Qt::green); // 终点颜色

    linearGrad.setSpread(QGradient::PadSpread); // 展布模式
    painter.setBrush(linearGrad);

    // 设置复合模式
//    painter.setCompositionMode(QPainter::RasterOp_NotSourceXorDestination);
//    painter.setCompositionMode(QPainter::CompositionMode_Difference);
    painter.setCompositionMode(QPainter::CompositionMode_Exclusion);


    for(int i = 0; i < 10; i++){
        painter.drawEllipse(QPoint(50, 0), 100, 50);// 画椭圆的
        painter.rotate(10);
    }
}
