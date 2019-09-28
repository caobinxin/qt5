#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setFixedSize( this->width (),this->height ());

    player = new QMediaPlayer(this); // 创建视频播放器
    player->setNotifyInterval(2000); // 信息更新周期2000ms
    player->setVideoOutput(ui->widget); // 视屏显示组件
    ui->widget->setMediaPlayer(player); // 设置显示组件关联的播放器

    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(on_StateChanged(QMediaPlayer::State)));

    connect(player, SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));

    connect(player, SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StateChanged(QMediaPlayer::State state)
{
    // 播放器状态变化
    ui->pushButtonPlay->setEnabled(!(state == QMediaPlayer::PlayingState));
    ui->pushButtonPause->setEnabled(state == QMediaPlayer::PlayingState);
    ui->pushButtonStop->setEnabled(state == QMediaPlayer::PlayingState);

}

void MainWindow::onDurationChanged(qint64 duration)
{
    // 文件时长发生变化
    ui->horizontalSliderDuration->setMaximum(duration);
    int secs = duration / 1000; // 秒
    int mins = secs / 60; // 分钟
    secs = secs % 60; // 余数秒

    durationTime = QString::asprintf("%d:%d", mins, secs);
    ui->labelDuration->setText(positionTime + "/" + durationTime);
}

void MainWindow::onPositionChanged(qint64 position)
{
    // 文件播放位置发生变化
    if(ui->horizontalSliderDuration->isSliderDown()){
        // 如果正在拖动滑条, 退出
        return;
    }

    ui->horizontalSliderDuration->setSliderPosition(position);
    int secs = position / 1000; // 秒
    int mins = secs / 60; // 分钟
    secs = secs % 60; // 余数秒

    positionTime = QString::asprintf("%d:%d", mins, secs);
    ui->labelDuration->setText(positionTime + "/" + durationTime);

}

void MainWindow::on_pushButtonOpenFile_clicked()
{
    // 打开文件
    QString curPath = QDir::homePath(); // 获取系统当前目录
    QString dlgTitle = "选择视屏文件"; // 对话框标题
    QString filter = "wmv文件(*.wmv);;mp4文件(*.mp4);;所有文件(*.*)";
    QString aFile = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
    if(aFile.isEmpty()){
        return;
    }

    QFileInfo fileInfo(aFile);
    ui->labelInfo->setText(fileInfo.fileName());
    player->setMedia(QUrl::fromLocalFile(aFile)); // 设置播放文件
    player->play();
}

void MainWindow::on_pushButtonPlay_clicked()
{
    // 播放
    player->play();
}

void MainWindow::on_pushButtonPause_clicked()
{
    // 暂停
    player->pause();
}

void MainWindow::on_pushButtonStop_clicked()
{
    // 停止
    player->stop();
}

void MainWindow::on_horizontalSliderVolume_valueChanged(int value)
{
    // 调节音量
    player->setVolume(value);
}

void MainWindow::on_pushButtonVolume_clicked()
{
    // 静音　按钮
    bool mute = player->isMuted();
    player->setMuted(!mute);

    if(mute){
        ui->pushButtonVolume->setText("静音");
    }else{
        ui->pushButtonVolume->setText("音量");
    }
}

void MainWindow::on_horizontalSliderDuration_valueChanged(int value)
{
    // 播放位置
    player->setPosition(value);
}

void MainWindow::on_pushButtonFullWindow_clicked()
{
    // 全屏按钮
    ui->widget->setFullScreen(true);
}
