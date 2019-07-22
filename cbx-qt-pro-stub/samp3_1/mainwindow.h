#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPerson.h"

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

    QPersion *boy;
    QPerson *girl;

private slots:
    void on_ageChanged(int value);
    void on_spin_valueChanged(int arg1);


};

#endif // MAINWINDOW_H
