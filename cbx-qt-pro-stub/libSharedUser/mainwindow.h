#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPen>
#include <QPainter>

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


private:
    QPen mPen;
protected:
    void paintEvent(QPaintEvent *event);
private slots:
    void on_actionSetting_Pen_triggered();
};

#endif // MAINWINDOW_H
