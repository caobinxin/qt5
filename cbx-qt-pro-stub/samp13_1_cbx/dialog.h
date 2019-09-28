#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "qdicethread.h"
#include <QCloseEvent>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnStartThread_clicked();

    void on_btnPausedThread_clicked();

    void on_btnStartDice_clicked();

private:
    Ui::Dialog *ui;

private:
    QDiceThread threadA;
private slots:
    // 自定义槽函数
    void onthreadA_started();
    void onthreadA_finished();
    void onthreadA_newValue(int seq, int diceValue);
    void on_btnClearText_clicked();
    void on_btnStopThread_clicked();


private:
    void closeEvent(QCloseEvent *event);
};

#endif // DIALOG_H
