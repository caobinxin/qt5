#ifndef DIALOG_H
#define DIALOG_H
#include "qmythread.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;

private:
    QThreadDAQ threadProducer;
    QThreadShow threadConsumer;

private slots:
    void onthreadB_newValue(int *data, int count, int bufNo);
    void on_btnStartThread_clicked();
    void on_btnStopThread_clicked();
    void on_btnClearText_clicked();
};

#endif // DIALOG_H
