#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setPalette(QPalette(Qt::white)); // 设置窗口为白色背景
    setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
//    fillRect();
//    fillRectPicture();
//    fillGradualChange();
    fillLinearChange();
//    fillConicalChange();

}

void MainWindow::fillRect()
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 矩形齿
    painter.setRenderHint(QPainter::TextAntialiasing); // 文本矩形齿

    int W = this->width();
    int H = this->height();

    QRect rect(W/4, H/4, W/2, H/2); // 制定绘制矩形的坐标(左上角，右下角)  绘制出来之后：中间区域矩形框

    // 设置画笔
    QPen pen;
    pen.setWidth(3); // 线宽
    pen.setColor(Qt::red); // 划线颜色
    pen.setStyle(Qt::SolidLine); // 线的样式，实线、虚线等
    pen.setCapStyle(Qt::FlatCap); // 线端点的样式
    pen.setJoinStyle(Qt::BevelJoin); // 线的连接点样式
    painter.setPen(pen);

    // 设置画刷
    QBrush brush;
    brush.setColor(Qt::yellow); // 画刷颜色
    brush.setStyle(Qt::SolidPattern); // 画刷填充样式
    painter.setBrush(brush);

    // 绘图
    painter.drawRect(rect);
}

void MainWindow::fillRectPicture()
{
    QPainter painter(this);
    int W = this->width(); //
    int H = this->height(); //

    QRect rect(W/4, H/4, W, H);

    // 设置画笔
    QPen pen;
    pen.setWidth(3);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine); // 线的类型，实线、虚线等

    painter.setPen(pen);

    // 设置画刷
    QPixmap texturePixmap(":/img/矩形图填充.jpg");
    QBrush brush;
    brush.setStyle(Qt::TexturePattern); // 画刷填充样式
    brush.setTexture(texturePixmap); // 设置材质图片
    painter.setBrush(brush);

    // 绘图
    painter.drawRect(rect);
}

void MainWindow::fillGradualChange()// 辐射渐变
{
    // 渐变应用案例
    QPainter painter(this);

    int W = this->width();
    int H = this->height();

    // 经向渐变
    QRadialGradient radialGrad(W/2, H/2, qMax(W/8, H/8), W/2, H/2);
    radialGrad.setColorAt(0, Qt::green);
    radialGrad.setColorAt(1, Qt::red);
//    radialGrad.setSpread(QGradient::ReflectSpread);// 反射式重复使用渐变方式填充
//    radialGrad.setSpread(QGradient::PadSpread); // 用结束点的颜色填充外部区域
    radialGrad.setSpread(QGradient::RepeatSpread); // 重复使用渐变方式填充

    painter.setBrush(radialGrad);
    painter.drawRect(this->rect());
}

void MainWindow::fillLinearChange()
{
    // 线性渐变的例子
    QPainter painter(this);

    int W = this->width();
    int H = this->height();

//    QLinearGradient LinearGrad(rect().left(), rect().top(), rect().right(), rect().bottom());
    QLinearGradient LinearGrad(rect().left(), rect().top(), rect().right(), rect().top());
    LinearGrad.setColorAt(0, Qt::green); // 起点颜色
    LinearGrad.setColorAt(0.5, Qt::yellow); // 中间点颜色
    LinearGrad.setColorAt(1, Qt::red); // 终点颜色
    LinearGrad.setSpread(QGradient::ReflectSpread);// 反射式重复使用渐变方式填充
//    LinearGrad.setSpread(QGradient::PadSpread); // 用结束点的颜色填充外部区域
//    LinearGrad.setSpread(QGradient::RepeatSpread); // 重复使用渐变方式填充

    painter.setBrush(LinearGrad);
    painter.drawRect(this->rect());
}

void MainWindow::fillConicalChange()
{
    // 锥型渐变的例子
    QPainter painter(this);

    int W = this->width();
    int H = this->height();


    QConicalGradient conicalGrad(W/2, H/2, H);// 最后一个是角度，　这里之所以会动，是应为这个角度为H,只要拖动窗口，就会动
    conicalGrad.setColorAt(0, Qt::green);
    conicalGrad.setColorAt(1, Qt::red);
//    conicalGrad.setSpread(QGradient::ReflectSpread);// 反射式重复使用渐变方式填充
//    conicalGrad.setSpread(QGradient::PadSpread); // 用结束点的颜色填充外部区域
    conicalGrad.setSpread(QGradient::RepeatSpread); // 重复使用渐变方式填充

    painter.setBrush(conicalGrad);
    painter.drawRect(this->rect());
}


