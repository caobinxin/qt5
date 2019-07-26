#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

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
    void on_actInitList_triggered();

    void on_actInsert_triggered();

    void on_actDelete_triggered();

    void on_actAllSelect_triggered();

    void on_actNoAllSelect_triggered();

    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_listWidget_customContextMenuRequested(const QPoint &pos);

    void on_centralWidget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;

    void setActionsForButton();

    void createSelectionPopMenu();
};

#endif // MAINWINDOW_H
