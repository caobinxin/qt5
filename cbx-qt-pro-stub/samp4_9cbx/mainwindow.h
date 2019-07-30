#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtDebug>
#include <QDate>
#include <QTableWidgetItem>
#include <QFont>
#include <QIcon>
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
    void on_btnSetHeader_clicked();

    void on_btnIniData_clicked();

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_btnInsertRow_clicked();

    void on_btnAppendRow_clicked();

    void on_chkBoxTabEditable_clicked(bool checked);

    void on_chkBoxHeaderH_clicked(bool checked);

    void on_chkBoxHeaderV_clicked(bool checked);

    void on_chkBoxRowColor_clicked(bool checked);

    void on_rBtnSelectItem_clicked();

    void on_rBtnSelectRow_clicked();

    void on_btnReadToEdit_clicked();

private:
    Ui::MainWindow *ui;
    // 自定义 单元格 Type 的类型， 在创建单元格的item的时候用
    enum CellType{ctName=1000, ctSex, ctBirth, ctNation, ctParthyM, ctScore};
    // 各字段在表格中的列号
    enum FieldColNum{colName=0, colSex, colBirth, colNation, colPartyM, colScore};

    QLabel *labCellIndex; // 状态栏上用于显示单元格的行号，列号
    QLabel *labCellType; // 状态栏上用于显示单元格的 type
    QLabel *labStudID; // 状态栏上用于显示学号

    // 为某一行创建items
    void createItemsARow(int rowNo, QString name, QString sex, QDate birth, QString nation, bool isPM, int score);
};

#endif // MAINWINDOW_H
