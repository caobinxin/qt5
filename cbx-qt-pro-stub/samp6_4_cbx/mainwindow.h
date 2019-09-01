#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qformdoc.h>
#include <QMdiSubWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actNew_triggered();

    void on_actOpen_triggered();

    void on_actCascade_triggered();

    void on_actTile_triggered();

    void on_actCloseAll_triggered();


    void on_actViewMode_triggered(bool checked);

    void on_mdiArea_subWindowActivated(QMdiSubWindow *arg1);

    void on_actCut_triggered();

    void on_actFont_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
