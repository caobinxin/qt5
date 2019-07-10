#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>

class QWDlgManual : public QDialog
{
    Q_OBJECT

private:
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QRadioButton *rBtnBlack;
    QRadioButton *rBtnRed;
    QRadioButton *rBtnBlue;
    QPlainTextEdit *txtEdit;
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QPushButton *btnClose;

    void iniUI(); //ui create and init
    void iniSignalSlots(); // init signal and slots

private slots:
    void on_chkBoxUnder(bool checked); // Underline
    void on_chkBoxItalic(bool checked); // Italic
    void on_chkBoxBold(bool checked); // Bold
    void setTextFontColor();// set text font color

public:
    QWDlgManual(QWidget *parent = 0);
    ~QWDlgManual();
};

#endif // QWDLGMANUAL_H
