#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setCentralWidget(ui->centralWidget);

    // 状态栏初始化创建
    labCellIndex = new QLabel("当前单元格坐标：", this);
    labCellIndex->setMinimumWidth(250);
    labCellType = new QLabel("当前单元格的类型：", this);
    labCellType->setMinimumWidth(200);
    labStudID = new QLabel("学生ID:", this);
    labStudID->setMinimumWidth(200);

    ui->statusBar->addWidget(labCellIndex);
    ui->statusBar->addWidget(labCellType);
    ui->statusBar->addWidget(labStudID);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createItemsARow(int rowNo, QString name, QString sex, QDate birth, QString nation, bool isPM, int score)
{
    qDebug()<< __func__;
    // 为一行的单元格创建 Items
    QTableWidgetItem *item;
    QString str;
    uint studID = 2013170184;// 学号基数

    // 姓名
    item = new QTableWidgetItem(name, MainWindow::ctName);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    studID += rowNo; // 学号 = 基数 + 行号
    item->setData(Qt::UserRole, QVariant(studID)); // 设置StudID为data
    ui->tableWidget->setItem(rowNo, MainWindow::colName, item);

    // 性别
    QIcon icon;
    if (sex == "男"){
        icon.addFile(":/icons/男.png");
    }else{
        icon.addFile(":/icons/女.png");
    }
    item = new QTableWidgetItem(sex, MainWindow::ctSex);
    item->setIcon(icon);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(rowNo, MainWindow::colSex, item);

    // 生日
    str = birth.toString("yyyy-M-d");
    qDebug()<< str ;
    item = new QTableWidgetItem(str, MainWindow::ctBirth);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(rowNo, MainWindow::colBirth, item);

    // 民族
    item = new QTableWidgetItem(nation, MainWindow::ctNation);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(rowNo, MainWindow::colNation, item);

    // 是否是党员
    item = new QTableWidgetItem("党员", MainWindow::ctParthyM);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    if(isPM){
        item->setCheckState(Qt::Checked);
    }else{
        item->setCheckState(Qt::Unchecked);
    }

    item->setBackgroundColor(Qt::yellow);
    ui->tableWidget->setItem(rowNo, MainWindow::colPartyM, item);

    // 分数
    str.setNum(score);
    item = new QTableWidgetItem(str, MainWindow::ctScore);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(rowNo, MainWindow::colScore, item);
}

void MainWindow::on_btnSetHeader_clicked()
{
    qDebug() << __func__;
    // 设置表头
    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText << "姓名" << "性别" << "生日" << "名族" << "是否党员" << "分数" ;

    ui->tableWidget->setColumnCount(headerText.count());
    for(int i = 0; i < ui->tableWidget->columnCount(); i++){
        headerItem = new QTableWidgetItem(headerText.at(i));
        QFont font = headerItem->font();
        font.setBold(true);// 设置为粗体
        font.setPointSize(12); // 字体大小
        headerItem->setTextColor(Qt::red);
        headerItem->setFont(font);
        ui->tableWidget->setHorizontalHeaderItem(i, headerItem);
    }
}

void MainWindow::on_btnIniData_clicked()
{
    qDebug()<< __func__;
    // 初始化表格内容
    QString strName, strSex;
    bool isParty = false;
    QDate birth;
    birth.setDate(1994, 10, 4); // 初始化一个日期
    ui->tableWidget->clearContents(); // 只清除工作区，不清除表头
    int Rows = ui->tableWidget->rowCount(); // 数据区的行数
    qDebug() << Rows;
    for (int i = 0; i < Rows; i++){
        strName = QString::asprintf("学生%d:", i);
        if((i % 2) == 0){// 分奇数和偶数设置性别和图标
            strSex = "男";
        }else{
            strSex = "女";
        }

        createItemsARow(i, strName, strSex, birth, "汉", isParty, 70);
        birth = birth.addDays(20);// 日期增加20天
        isParty != isParty;
    }
}

void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    // 当前选择单元格 发生变化时的响应
    QTableWidgetItem *item = ui->tableWidget->item(currentRow, currentColumn);
    if(NULL == item) return;

    labCellIndex->setText(QString::asprintf("当前单元格的坐标: %d行 , %d列", currentRow, currentColumn));
    int cellType = item->type();
    labCellType->setText(QString::asprintf("当前单元格类型： %d", cellType));
    item = ui->tableWidget->item(currentRow, MainWindow::colName);// 第一列的item
    int ID = item->data(Qt::UserRole).toInt(); // 读取用户自定义的数据
    labStudID->setText(QString::asprintf("学生 ID: %d", ID));
}

void MainWindow::on_btnInsertRow_clicked()
{
    qDebug()<< __func__;
    // 插入一行
    int curRow = ui->tableWidget->currentRow();
    ui->tableWidget->insertRow(curRow); // 插入一行，不会自动为单元格创建item
    createItemsARow(curRow, "新学生", "男", QDate::fromString("1992-1-2", "yyyy-M-d"), "苗族", true, 30);
}

void MainWindow::on_btnAppendRow_clicked()
{
    qDebug() << __func__;
    int curRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(curRow); // 在表格末尾添加一行
    createItemsARow(curRow, "新生", "女", QDate::fromString("1932-1-4", "yyyy-M-d"), "汉族", true, 40);
}

void MainWindow::on_chkBoxTabEditable_clicked(bool checked)
{
    // 设置编辑模式
    if(checked){
        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);// 双击或者获取焦点后单击，进入编辑状态
    }else{
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}

void MainWindow::on_chkBoxHeaderH_clicked(bool checked)
{
    // 是否显示行表头
    ui->tableWidget->horizontalHeader()->setVisible(checked);
}

void MainWindow::on_chkBoxHeaderV_clicked(bool checked)
{
    // 是否显示列表头
    ui->tableWidget->verticalHeader()->setVisible(checked);
}

void MainWindow::on_chkBoxRowColor_clicked(bool checked)
{
    // 设置间隔行底色
    ui->tableWidget->setAlternatingRowColors(checked);
}

void MainWindow::on_rBtnSelectItem_clicked()
{
    // 选择行为为 单元格选择
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
}

void MainWindow::on_rBtnSelectRow_clicked()
{
    // 行选择
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::on_btnReadToEdit_clicked()
{
    // 将所有单元表格的内容 提取到字符串中，显示在 PlainTextEdit组件里
    QString str;
    QTableWidgetItem *cellItem;
    ui->textEdit->clear();
    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
        str = QString::asprintf("第 %d 行：", i + 1);
        for(int j = 0; j < ui->tableWidget->columnCount()-1; j++){
            cellItem = ui->tableWidget->item(i, j); // 获取单元格的item
            str = str + cellItem->text() + "  ";
        }
        cellItem = ui->tableWidget->item(i, colPartyM); // 最后一列
        if(cellItem->checkState() == Qt::Checked){
            str += "党员";
        }else{
            str += "群众";
        }
        ui->textEdit->appendPlainText(str);
    }
}
