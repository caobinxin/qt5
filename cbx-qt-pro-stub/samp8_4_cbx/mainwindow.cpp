#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qwgraphicsview.h"
#include <QPointF>
#include <QGraphicsItem>
#include <QRectF>
#include <QPen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labViewCord = new QLabel("View 坐标");
    labViewCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labViewCord);

    labSceneCord = new QLabel("Scene 坐标");
    labSceneCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labSceneCord);

    labItemCord = new QLabel("Item 坐标");
    labItemCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labItemCord);

    ui->graphicsView->setCursor(Qt::CrossCursor); // 设置光标为交叉光标显示
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);

    connect(ui->graphicsView, SIGNAL(mouseMovePoint(QPoint)),
            this, SLOT(on_mouseMovePoint(QPoint)));

    connect(ui->graphicsView, SIGNAL(mouseClicked(QPoint)),
            this, SLOT(on_mouseClicked(QPoint)));

    iniGraphicsSystem();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniGraphicsSystem()
{
    // 构造graphics view 的各项
    QRectF rect(-200, -100, 400, 200); // 在左上角坐标，　宽度，高度
    scene = new QGraphicsScene(rect); // scene 逻辑坐标系定义

    ui->graphicsView->setScene(scene);
    // 画一个矩形框，大小等于scene
    QGraphicsRectItem *item = new QGraphicsRectItem(rect);
    item->setFlags(QGraphicsItem::ItemIsSelectable //设置 flags
                   | QGraphicsItem::ItemIsFocusable);
    QPen pen;
    pen.setWidth(2);
    item->setPen(pen);

    scene->addItem(item);

    // 画一个位于　scene 中心的椭圆，　测试局部坐标
    QGraphicsEllipseItem *item2 = new QGraphicsEllipseItem(-100, -50, 200, 100);
    item2->setPos(0,0);
    item2->setBrush(QBrush(Qt::blue));
    item2->setFlags(QGraphicsItem::ItemIsMovable
                    | QGraphicsItem::ItemIsSelectable
                    | QGraphicsItem::ItemIsFocusable);

    scene->addItem(item2);

    // 画一个圆,中心位于scene的边缘
    QGraphicsEllipseItem *item3 = new QGraphicsEllipseItem(-50, -50, 100, 100);
    item3->setPos(rect.right(), rect.bottom());
    item3->setBrush(QBrush(Qt::red));
    item3->setFlags(QGraphicsItem::ItemIsMovable
                    | QGraphicsItem::ItemIsSelectable
                    | QGraphicsItem::ItemIsFocusable);

    scene->addItem(item3);
    scene->clearSelection();

}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    // 窗口变化大小时的事件
    ui->labViewSize->setText(QString::asprintf("Graphics view 坐标, 左上角总是(0,0), 宽度=%d, 高度=%d", ui->graphicsView->width(),
                                               ui->graphicsView->height()));
    QRectF rectF = ui->graphicsView->sceneRect(); // scene 的矩形区
    ui->labSceneRect->setText(QString::asprintf("QGraphicsView::sceneRect=(Left,Top,Width,Height)=%.0f,%.0f,%.0f,%.0f",
                                                rectF.left(), rectF.top(),
                                                rectF.width(), rectF.height()));

}

void MainWindow::on_mouseMovePoint(QPoint point)
{
    // 鼠标移动事件, point 是GraphicsView 的坐标，物理坐标
    labViewCord->setText(QString::asprintf("View 坐标: %d,%d", point.x(), point.y()));

    QPointF pointScene = ui->graphicsView->mapToScene(point); // 转换到 Scene　坐标

    labSceneCord->setText(QString::asprintf("Scene 坐标: %.0f,%.0f", pointScene.x(), pointScene.y()));
}


void MainWindow::on_mouseClicked(QPoint point)
{
    // 鼠标单击事件
    QPointF pointScene = ui->graphicsView->mapToScene(point); // 转换到 scene坐标
    QGraphicsItem *item = NULL;

    item = scene->itemAt(pointScene, ui->graphicsView->transform()); // 获取光标下的图形项
    if(item != NULL){// 有图形项
        QPointF pointItem = item->mapFromScene(pointScene); // 图形项局部坐标
        labItemCord->setText(QString::asprintf("Item 坐标: %.0f,%.0f", pointItem.x(), pointItem.y()));
    }
}
