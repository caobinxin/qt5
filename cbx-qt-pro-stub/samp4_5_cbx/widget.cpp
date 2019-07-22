#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    fTimer = new QTimer(this);
    fTimer->stop();
    fTimer->setInterval(1000);
    connect(fTimer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushBtnReadCurrentDataAndTime_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(curDateTime.time());
    ui->lineEditTime->setText(curDateTime.toString("hh:mm:ss"));

    ui->dateEdit->setDate(curDateTime.date());
    ui->lineEditDate->setText(curDateTime.toString("yyyy-MM-dd"));
    ui->dateTimeEdit->setDateTime(curDateTime);
    ui->lineEditDateTime->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

void Widget::on_pushBtnSettingDateTime_clicked()
{
    QString str = ui->lineEditDateTime->text();
    str = str.trimmed();
    if(!str.isEmpty()){
        QDateTime dateTime = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(dateTime);
    }
}

void Widget::on_calendarWidget_selectionChanged()
{
    QDate dt = ui->calendarWidget->selectedDate();
    QString str = dt.toString("yyyy年M月d日");
    ui->labelSelectDate->setText(str);
}

void Widget::on_timer_timeout()
{
    // 定时器中断响应
    QTime curTime = QTime::currentTime();
    ui->lcdNumMinute->display(curTime.minute());
    ui->lcdNumSecond->display(curTime.second());
    ui->lcdNumMillisecond->display(curTime.msec());

    int va = ui->progressBar->value();
    va++;
    if(va > 100) va = 0;

    ui->progressBar->setValue(va);
}

void Widget::on_pushBtnTimerStart_clicked()
{
    fTimer->start();
    fTimeCounter.start();

    ui->pushBtnTimerStart->setEnabled(false);
    ui->pushBtnTimerStop->setEnabled(true);
    ui->pushBtnSettingCycle->setEnabled(false);
}

void Widget::on_pushBtnTimerStop_clicked()
{
    fTimer->stop();
    int tmMsec = fTimeCounter.elapsed();
    int ms = tmMsec % 1000;
    int sec = tmMsec / 1000;

    QString str = QString::asprintf("流逝的时间: %d 秒， %d　毫秒", sec, ms);
    ui->labelOutTime->setText(str);

    ui->pushBtnTimerStart->setEnabled(true);
    ui->pushBtnTimerStop->setEnabled(false);
    ui->pushBtnSettingCycle->setEnabled(true);
}
