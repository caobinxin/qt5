#ifndef QWDIALOGPEN_H
#define QWDIALOGPEN_H

#include "mysharedlib_global.h"
#include <QDialog>
#include <QPen>

namespace Ui {
class QWDialogPen;
}

class MYSHAREDLIBSHARED_EXPORT QWDialogPen : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialogPen(QWidget *parent = nullptr);
    ~QWDialogPen();

private:
    Ui::QWDialogPen *ui;

private:
    QPen m_pen; // 成员变量

public:
    void setPen(QPen pen);// 设置QPen, 用于对话框的界面显示
    QPen getPen(); // 获取对话框设置的QPen 的属性
    static QPen getPen(QPen iniPen, bool &ok); // 静态函数

private slots:
    void on_btnColor_clicked();

};

#endif // QWDIALOGPEN_H
