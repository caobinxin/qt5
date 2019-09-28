#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmyudpbase.h"
#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsVideoItem>

#include "qmycamerabase.h"
#include <QBuffer>
#include <QScreen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QMyUdpBase *udptest;

    QGraphicsVideoItem *videoItem;

private slots:
    void on_bind_success(QString successMsg);// 端口绑定成功　返回
    void on_receive_msg(QString);


    void on_btnSend_clicked();
    void on_actionBind_triggered();
};

#endif // MAINWINDOW_H
