#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(&threadConsumer, SIGNAL(newValue(int *, int, int)), this, SLOT(
                onthreadB_newValue(int *, int, int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onthreadB_newValue(int *data, int count, int bufNo)
{
    // 读取　threadConsumer 传递的缓冲区的数据
    QString str = QString::asprintf("第%d个缓冲区:", bufNo);
    for(int i=0; i < count; i++){
        str = str + QString::asprintf("%d ", *data);
        data++;
    }
    str += '\n';
    ui->plainTextEdit->appendPlainText(str);
}

void Dialog::on_btnStartThread_clicked()
{
    // 启动线程
    threadConsumer.start();
    threadProducer.start();
}

void Dialog::on_btnStopThread_clicked()
{
    // 结束线程
    threadConsumer.terminate();
    threadConsumer.wait();

    threadProducer.terminate();
    threadProducer.wait();
}

void Dialog::on_btnClearText_clicked()
{
    ui->plainTextEdit->clear();
}
