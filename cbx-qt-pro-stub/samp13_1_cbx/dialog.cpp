#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(&threadA, SIGNAL(started()), this, SLOT(onthreadA_started()));
    connect(&threadA, SIGNAL(finished()), this, SLOT(onthreadA_finished()));
    connect(&threadA, SIGNAL(newValue(int, int)), this, SLOT(onthreadA_newValue(int, int)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onthreadA_started()
{
    // 线程的 started()　信号的响应槽函数
    ui->labStatus->setText("Thread 状态： thread started");
}

void Dialog::onthreadA_finished()
{
    // 线程的　finished() 信号的响应槽函数
    ui->labStatus->setText("Thread状态: thread finished");
}

void Dialog::onthreadA_newValue(int seq, int diceValue)
{
    // QDiceThread 的newValue()信号的响应槽函数，显示骰子次数和点数
    QString str = QString::asprintf("第%d次掷骰子，点数为:%d", seq, diceValue);
    ui->textEdit->append(str);
    QPixmap pic; // 图片显示
    QString filename = QString::asprintf(":/img/images/d%d.jpg", diceValue);
    pic.load(filename);
    ui->label->setPixmap(pic);
}

void Dialog::on_btnStartThread_clicked()
{
    // 启动线程
    threadA.start();
    ui->btnStartThread->setEnabled(false);
    ui->btnStopThread->setEnabled(true);
    ui->btnPausedThread->setEnabled(true);
    ui->btnStartDice->setEnabled(true);
    ui->btnClearText->setEnabled(false);
}

void Dialog::on_btnStartDice_clicked()
{
    // 开始　掷骰子
    threadA.diceBegin();
    ui->btnStartDice->setEnabled(false);
    ui->btnPausedThread->setEnabled(true);
}

void Dialog::on_btnPausedThread_clicked()
{
    // 暂停掷骰子
    threadA.dicePause();
    ui->btnStartDice->setEnabled(true);
    ui->btnStopThread->setEnabled(true);
    ui->btnPausedThread->setEnabled(false);
    ui->btnClearText->setEnabled(true);
}

void Dialog::on_btnClearText_clicked()
{
    // 清空文本, 按钮
    ui->textEdit->clear();
}

void Dialog::on_btnStopThread_clicked()
{
    // 结束
    threadA.stopThread();
    ui->btnStartDice->setEnabled(true);
    ui->btnStopThread->setEnabled(false);
    ui->btnPausedThread->setEnabled(false);
    ui->btnClearText->setEnabled(true);
    ui->btnStartThread->setEnabled(true);
}

void Dialog::closeEvent(QCloseEvent *event)
{
    // 窗口关闭事件，必须结束线程
    if(threadA.isRunning()){
        threadA.stopThread();
        threadA.wait();
    }
    event->accept();
}
