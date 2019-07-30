#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include <QtDebug>
#include <QLabel>
#include <QPixmap>

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

    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

    void on_actDeleteItem_triggered();

    void on_actScanItems_triggered();

    void on_actZoomFitH_triggered();

    void on_actQuit_triggered();

    void on_actZoomIn_triggered();

    void on_actZoomRealSize_triggered();

    void on_actDockVisible_triggered(bool checked);

    void on_actDockFloat_triggered(bool checked);

    void on_dockWidget_visibilityChanged(bool visible);

    void on_dockWidget_topLevelChanged(bool topLevel);

private:
    Ui::MainWindow *ui;
    QLabel *LabFileName; // 用于状态栏文件名的显示
    QPixmap curPixMap; //当前的图片
    float pixRatio; // 当前图片的缩放比例

    // 枚举类型
    enum treeItemType{itTopItem = 1001, itGroupItem, itImageItem};
    enum treeColNum{ colItem = 0, colItemType = 1};// 目录树　列的编号
    void iniTree(); //目录树　初始化

    void addFolderItem(QTreeWidgetItem *parItem, QString dirName);
    QString getFinalFolderName(const QString &fullPathName);
    void addImageItem(QTreeWidgetItem *parItem, QString imgName);
    void displayImage(QTreeWidgetItem *curItem);
    void changeItemCaption(QTreeWidgetItem *curItem);
};

#endif // MAINWINDOW_H
