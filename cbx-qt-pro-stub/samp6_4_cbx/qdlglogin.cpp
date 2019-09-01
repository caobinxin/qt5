#include "qdlglogin.h"
#include "ui_qdlglogin.h"
#include <QSettings>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QMouseEvent>

QDlgLogin::QDlgLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDlgLogin)
{
    ui->setupUi(this);

    ui->editPSWD->setEchoMode(QLineEdit::Password); // 设置为密码输入模式
    this->setAttribute(Qt::WA_DeleteOnClose); // 设置为关闭时删除
    this->setWindowFlags(Qt::SplashScreen);// 设置为SplashScreen,没有边框
//    this->setWindowFlags(Qt::FramelessWindowHint); // 无边框,但在任务栏显示标题
    readSettings(); // 读取存储的用户名和密码
}

QDlgLogin::~QDlgLogin()
{
    delete ui;
}

void QDlgLogin::readSettings()
{
    // 读取存储的用户名和密码，密码是经过加密的
    QString organization = "WWB-Qt"; // 用于注册表,
    QString appName = "samp6_5";
    QSettings settings(organization, appName);

    bool saved = settings.value("saved", false).toBool(); // 读取　saved
    m_user = settings.value("Username", "user").toString(); // 读取Username
    QString defaultPSWD = encrypt("123456"); // 缺省密码123456;
    m_pswd = settings.value("PSWD", defaultPSWD).toString(); // 读取　PSWD

    if(saved){
        ui->editUser->setText(m_user);
    }

    ui->checkBox->setChecked(saved);
}

void QDlgLogin::writeSettings()
{
    // 保存用户名，密码等设置
    QSettings settings("WWB-QT", "samp6_5"); // 注册表键组
    settings.setValue("Username", m_user); // 用户名
    settings.setValue("PSWD", m_pswd); // 密码，经过加密的
    settings.setValue("saved", ui->checkBox->isChecked());
}

QString QDlgLogin::encrypt(const QString &str)
{
    // 字符串MD5 算法加密
    QByteArray btArray;
    btArray.append(str);

    QCryptographicHash hash(QCryptographicHash::Md5); // Md5 加密算法
    hash.addData(btArray); // 添加数据
    QByteArray resultArray = hash.result(); // 返回最终的散列值
    QString md5 = resultArray.toHex(); // 转换为16进制字符串
    return md5;
}

void QDlgLogin::mousePressEvent(QMouseEvent *event)
{
    // 鼠标按下
    if(event->button() == Qt::LeftButton){
        // 鼠标左键按下
        m_moving = true;
        m_lastPos = event->globalPos() - pos(); //　记录下鼠标相对于窗口的位置
    }

    return QDialog::mousePressEvent(event);
}

void QDlgLogin::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标按下　左键移动
    if(m_moving && (event->buttons()) && Qt::LeftButton && (event->globalPos() - m_lastPos).manhattanLength() >
                                                            QApplication::startDragDistance()){
        move(event->globalPos() - m_lastPos);
        m_lastPos = event->globalPos() - pos();
    }

    return QDialog::mouseMoveEvent(event);
}

void QDlgLogin::mouseReleaseEvent(QMouseEvent *event)
{
    // 鼠标按键释放
    m_moving = false; // 停止移动
}

void QDlgLogin::on_btnOk_clicked()
{
    // 确认按钮
    QString user = ui->editUser->text().trimmed(); // 输入用户名
    QString pswd = ui->editPSWD->text().trimmed(); // 输入密码
    QString encrptPSWD = encrypt(pswd); // 对输入密码进行加密
    if(user == m_user && encrptPSWD == m_pswd){
        writeSettings();
        this->accept(); // 对话框　accept(),关闭对话框
    }else{
        m_tryCount++; // 试错次数
        if(m_tryCount > 3){
            QMessageBox::critical(this, "错误", "输入错误次数太多，强行退出");
            this->reject(); // 退出
        }else{
            QMessageBox::warning(this, "错误提示", "用户名或密码错误");
        }
    }
}
