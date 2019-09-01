#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <qwdialogsize.h>
#include <qwdialogheaders.h>
#include <qwdialoglocate.h>
#include <QCloseEvent>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setACellText(int row, int column, QString text);
    void setActLocalEnable(bool flag);
    void setDlgLocateNull(); // 将窗口指针设置为NULL

private slots:
    void on_actSetSize_triggered();

    void on_actSetHeader_triggered();

    void on_actLocate_triggered();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QStandardItemModel *theModel; // 数据模型
    QItemSelectionModel *theSelection; // 选择模型

    QWDialogHeaders *dlgSetHeaders = NULL;

    QWDialogLocate *dlgLocate = NULL;

    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
