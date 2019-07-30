#include "qwintspindelegate.h"

QWIntSpinDelegate::QWIntSpinDelegate(QObject *parent)
{

}

QWidget *QWIntSpinDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // 创建代理 编辑组件
    QSpinBox *editor = new QSpinBox(parent);
    editor->setFrame(false); // 设置为无边款
    editor->setMinimum(0);
    editor->setMaximum(100000);
    return editor;
}

void QWIntSpinDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    // 从数据模型获取数据， 显示到代理组件中
    int value = index.model()->data(index, Qt::EditRole).toInt();
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void QWIntSpinDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    // 将代理组件的数据保存到数据模型中
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}

void QWIntSpinDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
