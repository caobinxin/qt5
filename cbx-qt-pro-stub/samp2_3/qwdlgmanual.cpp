#include "qwdlgmanual.h"

void QWDlgManual::iniUI()
{
    chkBoxUnder = new QCheckBox(tr("Underline"));
    chkBoxItalic = new QCheckBox(tr("Italic"));
    chkBoxBold = new QCheckBox(tr("Bold"));

    QHBoxLayout *HLay1 = new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxItalic);
    HLay1->addWidget(chkBoxBold);

    rBtnBlack = new  QRadioButton(tr("Black"));
    rBtnRed = new QRadioButton(tr("Red"));
    rBtnBlue = new QRadioButton(tr("Blue"));
    QHBoxLayout *HLay2 = new QHBoxLayout;
    HLay2->addWidget(rBtnBlack);
    HLay2->addWidget(rBtnBlue);
    HLay2->addWidget(rBtnRed);

    btnOk = new QPushButton(tr("Ok"));
    btnCancel = new QPushButton(tr("Cancel"));
    btnClose = new QPushButton(tr("Close"));
    QHBoxLayout *HLay3 = new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOk);
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("Hello wold\n\nIt is my demo.");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout *VLay = new QVBoxLayout;
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}

void QWDlgManual::iniSignalSlots()
{
    connect(rBtnRed,SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnBlue,SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    connect(rBtnBlack,SIGNAL(clicked()), this, SLOT(setTextFontColor()));

    connect(chkBoxBold, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxBold(bool)));
    connect(chkBoxUnder, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_chkBoxItalic(bool)));

    connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));

}

void QWDlgManual::on_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxItalic(bool checked)
{

}

void QWDlgManual::on_chkBoxBold(bool checked)
{

}

void QWDlgManual::setTextFontColor()
{

}

QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("From createed manually!!!");
}

QWDlgManual::~QWDlgManual()
{

}
