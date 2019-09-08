#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDataWidgetMapper>
#include "qwcomboboxdelegate.h"

#include <QFileDialog>
#include <QMessageBox>

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
    void on_actOpenDB_triggered();

private:
    Ui::MainWindow *ui;

private:
    QSqlDatabase DB; // 数据库连接
    QSqlTableModel *tabModel; // 数据模型
    QItemSelectionModel *theSelection; // 选择模型
    QDataWidgetMapper *dataMapper; // 数据映射
    QWComboBoxDelegate delegateSex; // 自定义数据代理，性别
    QWComboBoxDelegate delegateDepart; // 自定义数据代理，　部门
    void openTable(); // 打开数据表
    void getFieldNames(); // 获取字段名称，填充　排序字段的comboBox


private slots:
    void on_currentChanged(QModelIndex &current, QModelIndex &previous);
    void on_currentRowChanged(QModelIndex &current, QModelIndex &previous);

    void on_actRecAppend_triggered();
};

#endif // MAINWINDOW_H
