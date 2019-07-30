#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnOpen_clicked()
{
    // 选择单个文件
    QString curPath = QDir::currentPath(); // 获取应用程序当前目录
    QString dlgTitle = "选择一个文件";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";
    QString aFileName = QFileDialog::getOpenFileName(this,
                          dlgTitle, curPath, filter);

    if(!aFileName.isEmpty()){
        ui->plainTextEdit->appendPlainText(aFileName);
    }
}



void MainWindow::on_btnOpenMulti_clicked()
{
    // 选择多个文件
    QString curPath = QDir::currentPath();
    QString dlgTitle = "选择多个文件";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";
    QStringList fileList = QFileDialog::getOpenFileNames(this,
                              dlgTitle, curPath, filter);
    for(int i = 0; i < fileList.count(); i++){
        ui->plainTextEdit->appendPlainText(fileList.at(i));
    }
}




void MainWindow::on_btnSelDir_clicked()
{
    // 选择文件夹
    QString curPath = QCoreApplication::applicationDirPath();
    QString dlgTitle = "选择一个目录";
    QString selectedDir = QFileDialog::getExistingDirectory(this,
                             dlgTitle, curPath, QFileDialog::ShowDirsOnly);

    if(!selectedDir.isEmpty()){
        ui->plainTextEdit->appendPlainText(selectedDir);
    }
}

void MainWindow::on_btnSave_clicked()
{
    // 保存文件
    QString curPath = QCoreApplication::applicationDirPath();
    QString dlgTitle = "保存文件";
    QString filter = "h 文件(*.h);;c++文件(*.cpp);所有文件(*.*)";
    QString aFileName = QFileDialog::getSaveFileName(this,
                           dlgTitle, curPath, filter); // 此时弹出来的 要覆盖是假的， 如果要想真正的覆盖，需要在code中去写

    if(!aFileName.isEmpty()){
        ui->plainTextEdit->appendPlainText(aFileName);
    }
}



void MainWindow::on_btnColor_clicked()
{
    // 选择颜色
    QPalette pal = ui->plainTextEdit->palette(); // 获取现有的 palette（调色板）
    QColor iniColor = pal.color(QPalette::Text); // 现有的文字颜色
    QColor color = QColorDialog::getColor(iniColor, this, "选择字体颜色");

    if(color.isValid()){
        pal.setColor(QPalette::Text, color);
        ui->plainTextEdit->setPalette(pal);
    }
}




void MainWindow::on_btnFont_clicked()
{
    // 选择字体
    QFont iniFont = ui->plainTextEdit->font();
    bool ok = false;

    QFont font = QFontDialog::getFont(&ok, iniFont);
    if(ok){
        ui->plainTextEdit->setFont(font);
    }
}

void MainWindow::on_btnInputString_clicked()
{
    // 输入字符串
    QString dlgTitle = "输入文字对话框";
    QString txtLabel = "请输入文件名";
    QString defaultInput = "新建文件.txt";
    QLineEdit::EchoMode echoMode = QLineEdit::Normal;// 正常的输入 QLineEdit::Password
//    QLineEdit::EchoMode echoMode = QLineEdit::Password;

    bool ok = false;
    QString text = QInputDialog::getText(this, dlgTitle, txtLabel, echoMode,defaultInput, &ok);

    if(ok && !text.isEmpty()){
        ui->plainTextEdit->appendPlainText(text);
    }
}

void MainWindow::on_btnInputInt_clicked()
{
    // 输入整数
    QString dlgTitle = "输入整数对话框";
    QString txtLabel = "设置字体大小";
    int defaultValue = ui->plainTextEdit->font().pointSize();
    int minValue = 6, maxValue = 50, stepValue = 1;

    bool ok = false;
    int inputValue = QInputDialog::getInt(this, dlgTitle, txtLabel, defaultValue, minValue
                                          ,maxValue,stepValue, &ok);

    if(ok){
        QFont font = ui->plainTextEdit->font();
        font.setPointSize(inputValue);
        ui->plainTextEdit->setFont(font);
    }

}

void MainWindow::on_btnInputFloat_clicked()
{
    // 输入浮点数
    QString dlgTitle = "输入浮点数对话框";
    QString txtLabel = "输入一个浮点数";
    float defaultValue = 3.13;
    float minValue = 0, maxValue = 10000;
    int decimals = 2; // 小数点的位数
    bool ok = false;

    float inputValue = QInputDialog::getDouble(this, dlgTitle,txtLabel
                                               ,defaultValue, minValue,maxValue
                                               ,decimals, &ok);

    if(ok){
        QString str = QString::asprintf("输入一个浮点数:%.2f", inputValue);
        ui->plainTextEdit->appendPlainText(str);
    }
}

void MainWindow::on_btnInputItem_clicked()
{
    // 条目选择输入
    QStringList items;
    items << "优秀" << "良好" << "合格" << "不合格";
    QString dlgTitle = "条目选择对话框";
    QString txtLabel = "请选择级别";
    int curIndex = 0;
    bool editable = false; // comboBox 是否可编辑
    bool ok = false;
    QString text = QInputDialog::getItem(this, dlgTitle, txtLabel, items, curIndex, editable, &ok);

    if(ok && !text.isEmpty()){
        ui->plainTextEdit->appendPlainText(text);
    }
}

void MainWindow::on_btnMsgInformation_clicked()
{
    // information 对话框
    QString dlgTitle = "information 消息框";
    QString strInfo = "文件已经打开， 字体大小已经设置";
    QMessageBox::information(this, dlgTitle, strInfo, QMessageBox::Ok, QMessageBox::NoButton);
}

void MainWindow::on_btnMsgWarning_clicked()
{
    // warning
    QString dlgTitle = "warning 消息框";
    QString strInfo = "文件内容已经被修改";
    QMessageBox::warning(this, dlgTitle, strInfo);
}

void MainWindow::on_btnMsgCritical_clicked()
{
    // critical
    QString dlgTitle = "critical 消息框";
    QString strInfo = "有不明程序访问网络";
    QMessageBox::critical(this, dlgTitle, strInfo);
}

void MainWindow::on_btnMsgAbout_clicked()
{
    // about
    QString dlgTitle = "about 消息框";
    QString strInfo = "我开发的数据查看软件 v1.0\n 保留所有版权，违者必究!!!";
    QMessageBox::about(this,dlgTitle, strInfo);
}

void MainWindow::on_btnMsgAboutQt_clicked()
{
    QMessageBox::aboutQt(this, "曹斌鑫和Qt");
}

void MainWindow::on_btnMsgQuestion_clicked()
{
    QString dlgTitle = "Question 消息框";
    QString strInfo = "文件已经被修改，是否保存修改?";
    QMessageBox::StandardButton defaultBtn = QMessageBox::NoButton;
    QMessageBox::StandardButton result; //返回选择的按钮
    result = QMessageBox::question(this, dlgTitle, strInfo,
                                   QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
                                   defaultBtn);

    if(result == QMessageBox::Yes)
        ui->plainTextEdit->appendPlainText("Question 消息框：yes　被选中");
    else if(result == QMessageBox::No)
        ui->plainTextEdit->appendPlainText("Question 消息框：　NO 被选中");
    else if(result == QMessageBox::Cancel)
        ui->plainTextEdit->appendPlainText("Question 消息框: Cancel　被选中");
    else
        ui->plainTextEdit->appendPlainText("Question 消息框：　无选择");
}
