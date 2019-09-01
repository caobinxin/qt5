#include "qwdialogheaders.h"
#include "ui_qwdialogheaders.h"


QWDialogHeaders::QWDialogHeaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QWDialogHeaders)
{
    ui->setupUi(this);
    model = new QStringListModel;
    ui->listView->setModel(model);
}

QWDialogHeaders::~QWDialogHeaders()
{
    QMessageBox::information(this, "提示", "设置表头标题对话框被删除");
    delete ui;
}

void QWDialogHeaders::setHeaderList(QStringList &headers)
{
    // 初始化数据模型的字符串列表
    model->setStringList(headers);
}

QStringList QWDialogHeaders::headerList()
{
    // 返回字符串列表
    return model->stringList();
}
