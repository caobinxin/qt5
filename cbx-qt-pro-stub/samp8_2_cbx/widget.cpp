#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setPalette(QPalette(Qt::white)); // 设置窗口背景景色
    setAutoFillBackground(true);
    resize(600, 300); // 固定初始化窗口大小
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿
    painter.setRenderHint(QPainter::TextAntialiasing);

    // 生成五角星的５个顶点坐标，假设原点在五角星的中心
    qreal R = 100; // 半径
    const qreal Pi = 3.14159;
    qreal deg = Pi* 72/180; // 360/5 = 72

    QPoint points[5]={   //针对Qt 5.12.1 编译错误修改，使用<Qtmath>中的函数 qSin(), qCos()
        QPoint(R,0),
        QPoint(R*qCos(deg),     -R*qSin(deg)),
        QPoint(R*qCos(2*deg),   -R*qSin(2*deg)),
        QPoint(R*qCos(3*deg),   -R*qSin(3*deg)),
        QPoint(R*qCos(4*deg),   -R*qSin(4*deg))
    };

    // 设置字体
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    painter.setFont(font);

    // 设置画笔
    QPen penLine;
    penLine.setWidth(2); // 线宽
    penLine.setColor(Qt::blue); // 划线颜色
    penLine.setStyle(Qt::SolidLine); // 线的类型
    penLine.setCapStyle(Qt::FlatCap); // 线端点样式
    penLine.setJoinStyle(Qt::BevelJoin); // 线的连接点样式
    painter.setPen(penLine);

    // 设置画刷
    QBrush brush;
    brush.setColor(Qt::yellow); // 画刷颜色
    brush.setStyle(Qt::SolidPattern); // 画刷的填充样式
    painter.setBrush(brush);

    // 设计绘制五角星的PainterPath, 以便重复使用
    QPainterPath starPath;
    starPath.moveTo(points[0]);
    starPath.lineTo(points[2]);
    starPath.lineTo(points[4]);
    starPath.lineTo(points[1]);
    starPath.lineTo(points[3]);

    starPath.closeSubpath(); // 闭合路径，　最后一个点和第一个点相连
    starPath.addText(points[0], font, "0"); // 显示端点编号
    starPath.addText(points[3], font, "3");

    // 绘图
    painter.save(); // 保存坐标状态
    painter.translate(100, 120); // 平移
    painter.drawPath(starPath); //画星星
    painter.drawText(0,0, "s1");

    painter.restore(); // 恢复坐标状态

    painter.translate(300, 120); // 平移
    painter.scale(0.3,0.3); // 缩放
    painter.rotate(45); // 顺时针旋转45
    painter.drawPath(starPath);
    painter.drawText(0,0, "s2");

    painter.resetTransform(); // 恢复所有的坐标变换坐标状态

    painter.translate(300, 120); // 平移
    painter.scale(1.3,1.3); // 缩放
    painter.rotate(45); // 顺时针旋转45
    painter.drawPath(starPath);
    painter.drawText(0,0, "s2");

}
