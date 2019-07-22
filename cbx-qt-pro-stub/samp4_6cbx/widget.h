#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextBlock>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_btnInitList_clicked();

    void on_btnCityAreaCode_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_btnTextToComboBox_clicked();

    void on_plainTextEdit_customContextMenuRequested(const QPoint &pos);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
