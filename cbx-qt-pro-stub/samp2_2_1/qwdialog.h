#ifndef QWDIALOG_H
#define QWDIALOG_H

#include <QDialog>

namespace Ui {
class QWDialog;
}

class QWDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QWDialog(QWidget *parent = nullptr);
    ~QWDialog();

private:
    Ui::QWDialog *ui;
};

#endif // QWDIALOG_H