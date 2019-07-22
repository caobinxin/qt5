#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushBtnReadCurrentDataAndTime_clicked();

    void on_pushBtnSettingDateTime_clicked();

    void on_calendarWidget_selectionChanged();

    void on_timer_timeout();

    void on_pushBtnTimerStart_clicked();

    void on_pushBtnTimerStop_clicked();

private:
    Ui::Widget *ui;
    QTimer *fTimer;
    QTime fTimeCounter;
};

#endif // WIDGET_H
