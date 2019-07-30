#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QFileDialog>
#include <QTextStream>
#include <qwintspindelegate.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

private slots:
    void on_actOpen_triggered();

private:
    Ui::MainWindow *ui;
    int FixedColumnCount = 6;

    QWIntSpinDelegate intSpinDelegate; // 整形数

    QLabel *labCurFile; // 当前文件
    QLabel *labCellPos; // 当前单元格行列号
    QLabel *labCellText; // 当前单元格内容
    QStandardItemModel *theModel; // 数据模型
    QItemSelectionModel *theSelection; // 选择模型

    void iniModelFromStringList(QStringList &); // 从StringList 初始化数据模型

};

#endif // MAINWINDOW_H
