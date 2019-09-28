
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Slider_valueChanged(double value)
{
    // 拖动　slider 改变　battery　的电量值
    ui->qwBattery->setPowerLevel((int)value);


}

void MainWindow::on_qwBattery_powerLevelChanged(int arg1)
{
    // 电量值改变的时候，在标签中显示
    QString str = QStringLiteral("当前电量:") + QString::asprintf(
                "%d%%", arg1);
    ui->TextLabel->setText(str);
}
