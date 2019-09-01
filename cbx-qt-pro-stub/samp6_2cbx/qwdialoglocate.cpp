#include "qwdialoglocate.h"
#include "ui_qwdialoglocate.h"

#include <mainwindow.h>

QWDialogLocate::QWDialogLocate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogLocate)
{
    ui->setupUi(this);
}

QWDialogLocate::~QWDialogLocate()
{
    delete ui;
}

void QWDialogLocate::setSpinRange(int rowCount, int colCount)
{

}

void QWDialogLocate::setSpinValue(int rowNo, int colNo)
{
    // 设置SpinBox组件的数值
    ui->spinBoxRow->setValue(rowNo);
    ui->spinBoxColumn->setValue(colNo);
}

void QWDialogLocate::on_btnSetText_clicked()
{
    // 定位到单元格，并设置字符串
    int row = ui->spinBoxRow->value(); // 行号
    int col = ui->spinBoxColumn->value(); // 列号

    MainWindow *parWind = (MainWindow*)parentWidget(); // 获取主窗口
    parWind->setACellText(row, col, ui->lineEdit->text()); // 调用主窗口函数

    if(ui->checkBoxRow->isChecked()){
        // 行增
        ui->spinBoxRow->setValue( 1+ ui->spinBoxRow->value());
    }

    if(ui->checkBoxColumn->isChecked()){
        // 列增
        ui->spinBoxColumn->setValue(1 + ui->spinBoxColumn->value());
    }
}

void QWDialogLocate::closeEvent(QCloseEvent *event)
{
    // 窗口关闭　event 参照书中 p159
    MainWindow *parWind = (MainWindow *)parentWidget(); // 获取父窗口指针
    parWind->setActLocalEnable(true); // 可以继续点击工具栏中的按键
    parWind->setDlgLocateNull();// 将窗口指针设置为NULL
}
