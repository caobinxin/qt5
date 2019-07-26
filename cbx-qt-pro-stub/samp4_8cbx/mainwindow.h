#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTreeWidgetItem>

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
    void on_actAddFolder_triggered();

    void on_actAddFiles_triggered();

private:
    Ui::MainWindow *ui;

    // 枚举类型
    enum treeItemType{itTopItem = 1001, itGroupItem, itImageItem};
    enum treeColNum{ colItem = 0, colItemType = 1};// 目录树　列的编号
    void iniTree(); //目录树　初始化

    void addFolderItem(QTreeWidgetItem *parItem, QString dirName);
    QString getFinalFolderName(const QString &fullPathName);
    void addImageItem(QTreeWidgetItem *parItem, QString imgName);
};

#endif // MAINWINDOW_H
