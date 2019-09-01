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


    QString str = ui->lineEdit->text();
    emit changeCellText(row, col, str);

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
    // 窗口关闭事件，发射信号 actTab_Locate 能用
    emit changeActionEnable(true);
}

void QWDialogLocate::showEvent(QShowEvent *event)
{
    // 窗口显示事件，发射信号　使actTab_Locate　不能用
    emit changeActionEnable(false);
}
