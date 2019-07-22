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


void Widget::on_btnInitList_clicked()
{
    QIcon icon;
    icon.addFile(":/images/城市建筑.png");
    ui->comboBox->clear();
    for(int i = 0; i < 20; i++){
        ui->comboBox->addItem(icon, QString::asprintf("城市 %d", i));//带图标
//        ui->comboBox->addItem(QString::asprintf("Item %d", i)); //不带图标
    }
}

void Widget::on_btnCityAreaCode_clicked()
{
    QMap<QString, int> cityZone;
    cityZone.insert("北京", 10); // 最后的10 是作为用户数据传入的
    cityZone.insert("上海", 21);
    cityZone.insert("兰州", 29);
    cityZone.insert("济南", 23);
    cityZone.insert("广州", 34);

    QIcon icon;
    icon.addFile(":/images/城市.png");

    ui->comboBox_2->clear();
    foreach(const QString &str, cityZone.keys())
        ui->comboBox_2->addItem(icon,str, cityZone.value(str));
}

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->plainTextEdit->appendPlainText(arg1);
}

void Widget::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString zone = ui->comboBox_2->currentData().toString();
    ui->plainTextEdit->appendPlainText(arg1 + "：区号＝" + zone);
}

void Widget::on_btnTextToComboBox_clicked()
{
    QTextDocument* doc = ui->plainTextEdit->document();//文本对象

    int cnt = doc->blockCount();//回车符是一个block

    QIcon icon(":/images/所在城市-01-01.png");
    ui->comboBox->clear();
    for(int i = 0; i < cnt; i++){
        QTextBlock textLine = doc->findBlockByNumber(i);
        QString str = textLine.text();
        ui->comboBox->addItem(icon, str);
    }
}

void Widget::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    //创建并显示标准弹出式菜单
}
