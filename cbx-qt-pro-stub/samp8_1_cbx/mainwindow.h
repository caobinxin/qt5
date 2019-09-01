#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include <QRect>
#include <QPen>

#include <QMainWindow>

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

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;


    void fillRect();// p208 中的例子

    void fillRectPicture(); // p211的例子

    void fillGradualChange(); // p213 的例子　辐射渐变的例子

    void fillLinearChange(); // 线性渐变的例子

    void fillConicalChange(); // 锥形渐变
};

#endif // MAINWINDOW_H
