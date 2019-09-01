#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QGraphicsRectItem> // 创建矩形
#include <QGraphicsEllipseItem> // 创建椭圆和圆
#include <QGraphicsPolygonItem> // 创建三角形和梯形
#include <QGraphicsLineItem> // 创建直线
#include <QGraphicsTextItem> // 创建文字
#include <QGraphicsPixmapItem>

#include <QGraphicsItem>
#include <QPixmap>

#include <QGraphicsItemGroup>
#include <QColor>
#include <QColorDialog>
#include <QBrush>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labViewCord = new QLabel("View 坐标:"); // 创建状态栏标签
    labViewCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labViewCord);

    labSceneCord = new QLabel("Scene 坐标:");
    labSceneCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labSceneCord);

    labItemCord = new QLabel("Item 坐标:");
    labItemCord->setMinimumWidth(150);
    ui->statusBar->addWidget(labItemCord);

    labItemInfo = new QLabel("ItemInfo:");
    labItemInfo->setMinimumWidth(200);
    ui->statusBar->addWidget(labItemInfo);

    scene = new QGraphicsScene(-300,-200, 600, 200); // 创建QGraphicsScene
    ui->graphicsView->setScene(scene); // 和 view 关联
    ui->graphicsView->setCursor(Qt::CrossCursor); // 设置鼠标的形状
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    this->setCentralWidget(ui->graphicsView);

    connect(ui->graphicsView, SIGNAL(mouseMovePoint(QPoint)),
            this, SLOT(on_mouseMovePoint(QPoint)));

    connect(ui->graphicsView, SIGNAL(mouseClicked(QPoint)),
            this, SLOT(on_mouseClicked(QPoint)));

    connect(ui->graphicsView, SIGNAL(mouseDoubleClick(QPoint)),
            this, SLOT(on_mouseDoubleClick(QPoint)));

    connect(ui->graphicsView, SIGNAL(keyPress(QKeyEvent *)),
            this, SLOT(on_keyPress(QKeyEvent *)));

    qsrand(QTime::currentTime().second()); // 随机数　初始化　这里用当前的时间作为　随机数种子
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mouseMovePoint(QPoint point)
{
    // 鼠标移动事件 point 是GraphicsView 的坐标，物理坐标，不是场景中的坐标
    labViewCord->setText(QString::asprintf("View 坐标: %d,%d", point.x(), point.y()));
    QPointF pointScene = ui->graphicsView->mapToScene(point); // 转换到scene坐标
    labSceneCord->setText(QString::asprintf("Scene 坐标: %.0f,%.0f",pointScene.x(), pointScene.y()));
}

void MainWindow::on_mouseClicked(QPoint point)
{
    // 鼠标单击事件
    QPointF pointScene = ui->graphicsView->mapToScene(point); // 转换为Scene 坐标
    QGraphicsItem *item = NULL;
    item = scene->itemAt(pointScene, ui->graphicsView->transform()); // 光标下的图形项
    if(item != NULL){
        QPointF pointF = item->mapFromScene(pointScene); // 图形项下的局部坐标
        labItemCord->setText(QString::asprintf("Item 坐标: %.0f,%.0f", pointF.x(), pointF.y()));
        labItemInfo->setText(item->data(ItemDesciption).toString() + ", ItemId=" + item->data(ItemId).toString());
    }
}

void MainWindow::on_mouseDoubleClick(QPoint point)
{
    // 鼠标双击，调用相应的对话框，设置填充颜色，线条颜色或者字体
    QPointF pointScene = ui->graphicsView->mapToScene(point); // 转换到　scene　坐标
    QGraphicsItem *item = NULL;
    item = scene->itemAt(pointScene, ui->graphicsView->transform()); // 光标下的图形项
    if(item == NULL){
        return;
    }

    switch (item->type()) {
    case QGraphicsRectItem::Type: // 矩形
    {
        QGraphicsRectItem *theItem;
        theItem = qgraphicsitem_cast<QGraphicsRectItem*>(item);
        setBrushColor(theItem);
        break;
    }

    case QGraphicsEllipseItem::Type:
    {
        QGraphicsEllipseItem *theItem;
        theItem = qgraphicsitem_cast<QGraphicsEllipseItem*>(item);
        setBrushColor(theItem);
        break;
    }

    case QGraphicsPolygonItem::Type:
    {
        QGraphicsPolygonItem *theItem;
        theItem = qgraphicsitem_cast<QGraphicsPolygonItem*>(item);
        setBrushColor(theItem);
        break;
    }

    case QGraphicsLineItem::Type:
    {
        QGraphicsLineItem *theItem;
        theItem = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        QPen pen = theItem->pen();
        QColor color = theItem->pen().color();
        color = QColorDialog::getColor(color, this, "选择线条颜色");
        if(color.isValid()){
            pen.setColor(color);
            theItem->setPen(pen);
        }
        break;
    }

    case QGraphicsTextItem::Type:
    {
        QGraphicsTextItem *theItem;
        theItem = qgraphicsitem_cast<QGraphicsTextItem*>(item);
        QFont font = theItem->font();
        bool ok = false;
        font = QFontDialog::getFont(&ok, font, this, "设置字体");
        if(ok){
            theItem->setFont(font);
        }

        break;
    }
    }
}

void MainWindow::on_keyPress(QKeyEvent *event)
{
    // 按键事件
    if(scene->selectedItems().count() != 1)
        return; // 没有选中的图形项，或选中的多于1个
    QGraphicsItem *item = scene->selectedItems().at(0);

    if(event->key() == Qt::Key_Delete){
        scene->removeItem(item);
    }else if (event->key() == Qt::Key_Space){
        // 顺时钟旋转90
        item->setRotation(90 + item->rotation());
    }else if (event->key() == Qt::Key_PageUp){
        // 放大
        item->setScale(-0.1 + item->scale());
    }else if (event->key() == Qt::Key_PageDown){
        item->setScale(0.1 + item->scale());
    }else if(event->key() == Qt::Key_Left){
        // 左移动
        item->setX( -1 + item->x());
    }else if(event->key() == Qt::Key_Right){
        item->setX(1 + item->x());
    }else if (event->key() == Qt::Key_Up){
        item->setY(-1 + item->y());
    }else if( event->key() == Qt::Key_Down){
        item->setY(1 + item->y());
    }
}

void MainWindow::on_actItem_Polygon_triggered()
{
    // 添加一个梯形
    QGraphicsPolygonItem *item = new QGraphicsPolygonItem();

    QPolygonF   points;
    points.append(QPointF(-40,-40));
    points.append(QPointF(40,-40));
    points.append(QPointF(100,40));
    points.append(QPointF(-100,40));
    item->setPolygon(points);


    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);

    item->setBrush(QBrush(Qt::yellow)); // 填充颜色
    item->setZValue(++frontZ); //　用于叠放顺序

    item->setPos(-50 + (qrand() % 100), -50+(qrand() %100)); // 设置一个随机的初始位置
    item->setData(ItemId, ++seqNum); //自定义数据，　ItemId　键
    item->setData(ItemDesciption, "梯形"); //自定义数据, ItemDesciption键

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);

}

void MainWindow::on_actItem_Ellipse_triggered()
{
    // 添加一个椭圆
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(-50, -30, 100, 60); // 中心点的坐标　长轴，宽轴

    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);

    item->setBrush(QBrush(Qt::blue)); // 填充颜色
    item->setZValue(++frontZ); //　用于叠放顺序
    item->setPos(-50 + (qrand() % 100), -50+(qrand() %100)); // 设置一个随机的初始位置
    item->setData(ItemId, ++seqNum); //自定义数据，　ItemId　键
    item->setData(ItemDesciption, "椭圆"); //自定义数据, ItemDesciption键

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

void MainWindow::on_actItem_Rect_triggered()
{
    // 添加一个椭圆
    QGraphicsRectItem *item = new QGraphicsRectItem(-150, -30, 300, 60); // 中心点的坐标　长轴，宽轴

    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);

    item->setBrush(QBrush(Qt::red)); // 填充颜色
    item->setZValue(++frontZ); //　用于叠放顺序
    item->setPos(-50 + (qrand() % 100), -50+(qrand() %100)); // 设置一个随机的初始位置
    item->setData(ItemId, ++seqNum); //自定义数据，　ItemId　键
    item->setData(ItemDesciption, "矩形"); //自定义数据, ItemDesciption键

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

void MainWindow::on_actItem_Line_triggered()
{
    // 添加一个椭圆
    QGraphicsLineItem *item = new QGraphicsLineItem(-100, 0, 100, 0); // 中心点的坐标　长轴，宽轴

    QPen pen;
    pen.setColor(Qt::green);
    pen.setWidth(5);
    pen.setStyle(Qt::DashLine);
    item->setPen(pen);


    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);

    //    item->setBrush(QBrush(Qt::red)); // 填充颜色
    item->setZValue(++frontZ); //　用于叠放顺序
    item->setPos(-50 + (qrand() % 100), -50+(qrand() %100)); // 设置一个随机的初始位置
    item->setData(ItemId, ++seqNum); //自定义数据，　ItemId　键
    item->setData(ItemDesciption, "直线"); //自定义数据, ItemDesciption键

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

void MainWindow::on_actItem_Pixmap_triggered()
{
    // 添加一个椭圆
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(); // 中心点的坐标　长轴，宽轴
    QPixmap pixmap(":/icon/imag/018.JPG");
    item->setPixmap(pixmap);
    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);


    item->setZValue(++frontZ); //　用于叠放顺序
    item->setPos(-50 + (qrand() % 100), -50+(qrand() %100)); // 设置一个随机的初始位置
    item->setData(ItemId, ++seqNum); //自定义数据，　ItemId　键
    item->setData(ItemDesciption, "图片"); //自定义数据, ItemDesciption键

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

void MainWindow::on_actItem_Text_triggered()
{
    // 添加一个椭圆
    QGraphicsTextItem *item = new QGraphicsTextItem(); // 中心点的坐标　长轴，宽轴
    QFont font;
    font.setBold(true);

    item->setFont(font);
    item->setPlainText("曹斌鑫，你好");

    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);


    item->setZValue(++frontZ); //　用于叠放顺序
    item->setPos(-50 + (qrand() % 100), -50+(qrand() %100)); // 设置一个随机的初始位置
    item->setData(ItemId, ++seqNum); //自定义数据，　ItemId　键
    item->setData(ItemDesciption, "文字"); //自定义数据, ItemDesciption键

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

void MainWindow::on_actItem_Circle_triggered()
{
    // 添加一个椭圆
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(-50, -30, 200, 200); // 中心点的坐标　长轴，宽轴

    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);

    item->setBrush(QBrush(Qt::gray)); // 填充颜色
    item->setZValue(++frontZ); //　用于叠放顺序
    item->setPos(-50 + (qrand() % 100), -50+(qrand() %100)); // 设置一个随机的初始位置
    item->setData(ItemId, ++seqNum); //自定义数据，　ItemId　键
    item->setData(ItemDesciption, "圆"); //自定义数据, ItemDesciption键

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

void MainWindow::on_actItem_Triangle_triggered()
{
    // 添加一个梯形
    QGraphicsPolygonItem *item = new QGraphicsPolygonItem();

    QPolygonF   points;
    points.append(QPointF(-40,-40));
    points.append(QPointF(-40,-40));
    points.append(QPointF(100,40));
    points.append(QPointF(-100,40));
    item->setPolygon(points);


    item->setFlags(QGraphicsItem::ItemIsMovable
                   | QGraphicsItem::ItemIsSelectable
                   | QGraphicsItem::ItemIsFocusable);

    item->setBrush(QBrush(Qt::yellow)); // 填充颜色
    item->setZValue(++frontZ); //　用于叠放顺序

    item->setPos(-50 + (qrand() % 100), -50+(qrand() %100)); // 设置一个随机的初始位置
    item->setData(ItemId, ++seqNum); //自定义数据，　ItemId　键
    item->setData(ItemDesciption, "三角形"); //自定义数据, ItemDesciption键

    scene->addItem(item);
    scene->clearSelection();
    item->setSelected(true);
}

void MainWindow::on_actZoomIn_triggered()
{
    // 放大
    int cnt = scene->selectedItems().count();
    if(1 == cnt){ // 当选中一个item时，只放大该item
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setScale(0.1 + item->scale());
    }else { // 如果没有选中任何一个item时，放大所有
        ui->graphicsView->scale(1.1, 1.1);
    }
}

void MainWindow::on_actZoomOut_triggered()
{
    // 缩小
    int cnt = scene->selectedItems().count();
    if(1 == cnt){
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setScale(-0.1 + item->scale());
    }else {
        ui->graphicsView->scale(0.9, 0.9);
    }
}

void MainWindow::on_actRotateLeft_triggered()
{
    // 左旋转 = 逆时针旋转
    int cnt = scene->selectedItems().count();
    if( 1 == cnt){
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setRotation(-15 + item->rotation());
    }else{
        ui->graphicsView->rotate(-15);
    }
}

void MainWindow::on_actRotateRight_triggered()
{
    int cnt = scene->selectedItems().count();
    if( 1 == cnt){
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setRotation(15 + item->rotation());
    }else{
        ui->graphicsView->rotate(15);
    }
}
#include <QtDebug>
void MainWindow::on_actRestore_triggered()
{
    // 缩放　旋转本质都是　坐标变换，这里是恢复之前的坐标
    int cnt = scene->selectedItems().count();
    if(1 == cnt){
        QGraphicsItem *item = scene->selectedItems().at(0);
        //        item->resetTransform();// 新版本这个函数不起作用了
        item->setRotation(0);
        item->setScale(1.0);
    }else{
        ui->graphicsView->resetTransform();
    }
}

void MainWindow::on_actEdit_Front_triggered()
{
    // bring to front, 前置
    int cnt = scene->selectedItems().count();
    if(cnt > 0){
        // 只处理选中的第1个图形项
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setZValue(++frontZ);
    }
}

void MainWindow::on_actEdit_Back_triggered()
{
    // bring to back, 后置
    int cnt = scene->selectedItems().count();
    if(cnt > 0){
        // 只处理选中的第1个图形项
        QGraphicsItem *item = scene->selectedItems().at(0);
        item->setZValue(--backZ);
    }
}

void MainWindow::on_actGroup_triggered()
{
    // 组合
    int cnt = scene->selectedItems().count();
    if(cnt > 1){
        QGraphicsItemGroup *group = new QGraphicsItemGroup; // 创建组合
        scene->addItem(group); // 组合添加到场景中
        for(int i = 0; i < cnt; i++){
            QGraphicsItem *item = scene->selectedItems().at(0);
            item->setSelected(false); // 清除选择虚线框
            item->clearFocus();
            group->addToGroup(item); // 添加到组合
        }

        group->setFlags(QGraphicsItem::ItemIsMovable |
                        QGraphicsItem::ItemIsSelectable |
                        QGraphicsItem::ItemIsFocusable);
        group->setZValue(++frontZ);
        scene->clearSelection();
        group->setSelected(true);
    }
}

void MainWindow::on_actGroupBreak_triggered()
{
    // break group, 打散组合
    int cnt = scene->selectedItems().count();
    if(cnt == 1){
        QGraphicsItemGroup *group;
        group = (QGraphicsItemGroup *)scene->selectedItems().at(0);
        scene->destroyItemGroup(group);
    }
}

void MainWindow::on_actEdit_Delete_triggered()
{
    // 删除所有选中的图形项
    int cnt = scene->selectedItems().count();
    if(cnt > 0){
        for(int i = 0; i < cnt; i++){
            QGraphicsItem *item = scene->selectedItems().at(0);
            scene->removeItem(item); // 删除图形项
        }
    }
}

template<class T>
void MainWindow::setBrushColor(T *item)
{
    // 函数模板
    QColor color = item->brush().color();
    color = QColorDialog::getColor(color, NULL, "选择填充颜色");
    if(color.isValid()){
        item->setBrush(QBrush(color));
    }
}
