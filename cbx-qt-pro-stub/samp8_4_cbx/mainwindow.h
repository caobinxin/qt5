#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include <QPoint>
#include <QResizeEvent>


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
    QGraphicsScene *scene;
    QLabel *labViewCord;
    QLabel *labSceneCord;
    QLabel *labItemCord;

    void iniGraphicsSystem(); // 创建Graphics View 的各项

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_mouseMovePoint(QPoint point);
    void on_mouseClicked(QPoint point);
};

#endif // MAINWINDOW_H
