#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->horizontalSliderGreen, SIGNAL(valueChanged(int)), this,SLOT(on_horizontalSliderRed_valueChanged(int)));
    connect(ui->horizontalSliderBlue, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderRed_valueChanged(int)));
    connect(ui->horizontalSliderAlpha, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderRed_valueChanged(int)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_horizontalSliderRed_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;
    int R = ui->horizontalSliderRed->value();
    int G = ui->horizontalSliderGreen->value();
    int B = ui->horizontalSliderBlue->value();
    int alpha = ui->horizontalSliderAlpha->value();
    color.setRgb(R,G,B,alpha);
    QPalette pal = ui->textEdit->palette();
    pal.setColor(QPalette::Base, color);
    ui->textEdit->setPalette(pal);
}

void Widget::on_dial_valueChanged(int value)
{
    // 设置LCD的显示值等于Dial的值
    ui->lcdNumber->display(value);
}

void Widget::on_radioButtonDec_clicked()
{
    // 设置LCD显示十进制
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setDecMode();
}

void Widget::on_radioButtonBin_clicked()
{
    ui->lcdNumber->setDigitCount(8);
    ui->lcdNumber->setBinMode();
}

void Widget::on_radioButtonOct_clicked()
{
    ui->lcdNumber->setDigitCount(4);
    ui->lcdNumber->setOctMode();
}

void Widget::on_radioButtonHex_clicked()
{
    ui->lcdNumber->setDigitCount(4);
    ui->lcdNumber->setHexMode();
}

void Widget::on_pushButton_clicked()
{
    close();
}
