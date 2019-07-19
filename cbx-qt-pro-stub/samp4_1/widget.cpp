#include "widget.h"
#include "ui_widget.h"

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

void Widget::on_pButtonCount_clicked()
{
    QString str = ui->lineEditNumber->text(); // read number
    int num = str.toInt();
    str = ui->lineEditUPrice->text();
    float price = str.toFloat();
    float total = num * price;
    str = str.sprintf("%.2f", total);
    ui->lineEditTPrice->setText(str);
}

void Widget::on_pushButtonTransformation_clicked()
{
    QString str = ui->lineEditTen->text();
    int val = str.toInt();

//    str = QString::number(val,16);
    str = str.setNum(val, 16);
    str = str.toUpper(); // Convert to capital letters.
    ui->lineEditHex->setText(str);

    str = str.setNum(val, 2);
    ui->lineEditTwo->setText(str);

}
