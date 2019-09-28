#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSoundEffect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this); // 播放器
    playList = new QMediaPlaylist(this); // 播放列表
    playList->setPlaybackMode(QMediaPlaylist::Loop); // 循环播放
    player->setPlaylist(playList);

    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(onStateChanged(QMeidaPlayer::State)));

    connect(player, SIGNAL(positionChanged(qint64)),
            this, SLOT(onPositionChanged(qint64)));

    connect(player, SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));

    connect(player, SIGNAL(currentIndexChanged(int)),
            this, SLOT(onPlaylistChanged(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStateChanged(QMediaPlayer::State state)
{
    // 播放器状态变化，　更新按钮的状态
    ui->btnPlay->setEnabled(!(state == QMediaPlayer::PlayingState));
    ui->btnPause->setEnabled(state == QMediaPlayer::PlayingState);
    ui->btnStop->setEnabled(state == QMediaPlayer::PlayingState);
}

void MainWindow::onPlaylistChanged(int position)
{
    // 播放列表变化，更新当前播放文件名显示
    ui->listWidget->setCurrentRow(position);
    QListWidgetItem *item = ui->listWidget->currentItem();
    if(item){
        ui->labelInfo->setText(item->text());
    }
}

void MainWindow::onDurationChanged(qint64 duration)
{
    // 文件时长变化，更新进度显示
    ui->hSliderPlayStatus->setMaximum(duration);
    int secs = duration/1000; // 秒
    int mins = secs/60; // 分钟
    secs = secs%60; // 余数秒
    durationTime = QString::asprintf("%d:%d", mins, secs);
    ui->labelStatus->setText(positionTime + "/" + durationTime);
}

void MainWindow::onPositionChanged(qint64 position)
{
    // 当前文件播放位置变化，更新进度显示
    if(ui->hSliderPlayStatus->isSliderDown()){
        // 正处于手动调整的状态，不处理
        return;
    }
    ui->hSliderPlayStatus->setSliderPosition(position);
    int secs = position/1000; // 秒
    int mins = secs/60; // 分钟
    secs = secs%60; // 余数秒
    positionTime = QString::asprintf("%d:%d", mins, secs);
    ui->labelStatus->setText(positionTime + "/" + durationTime);
}

void MainWindow::on_btnAdd_clicked()
{
    // 添加文件
    QString curPath = QDir::homePath(); // 获取用户目录
    QString dlgTitle = "选择音频文件";
    QString filter = "音频文件(*.mp3 *.wav);;mp3文件(*.mp3);;wav文件(*.wav);;wma文件(*.wma);;所有文件(*.*)";
    QStringList fileList = QFileDialog::getOpenFileNames(this, dlgTitle, curPath, filter);
    if(fileList.count() < 1){
        return;
    }
    for(int i = 0; i < fileList.count(); i++){
        QString aFile = fileList.at(i);
        playList->addMedia(QUrl::fromLocalFile(aFile)); // 添加文件
        QFileInfo fileInfo(aFile);
        ui->listWidget->addItem(fileInfo.fileName()); // 添加到界面文件列表
    }
    if(player->state() != QMediaPlayer::PlayingState){
        playList->setCurrentIndex(0);
    }
    player->play();
}

void MainWindow::on_btnRemove_clicked()
{
    // 移除一个文件
    int pos = ui->listWidget->currentRow();
    QListWidgetItem *item = ui->listWidget->takeItem(pos);
    delete item; // 从listWidget 里删除
    playList->removeMedia(pos); // 从播放列表里删除
}

void MainWindow::on_btnClear_clicked()
{
    // 清空列表
    playList->clear();
    ui->listWidget->clear();
    player->stop();
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    // 双击时切换播放文件
    int rowNo = index.row();
    playList->setCurrentIndex(rowNo);
    player->play();
}

void MainWindow::on_btnPlay_clicked()
{
    // 播放
    if(playList->currentIndex() < 0){
        playList->setCurrentIndex(0);
    }
    player->play();
}



void MainWindow::on_btnPause_clicked()
{
    // 暂停播放
    player->pause();
}

void MainWindow::on_btnStop_clicked()
{
    // 停止播放
    player->stop();
}

void MainWindow::on_pushButton_9_clicked()
{
    // 静音控制
    bool mute = player->isMuted();
    player->setMuted(!mute);
    if(mute){
        ui->pushButton_9->setIcon(QIcon(":/img/images/volumn.bmp"));
    }else {
        ui->pushButton_9->setIcon(QIcon(":/img/images/mute.bmp"));
    }
}


void MainWindow::on_hSliderVolume_valueChanged(int value)
{
    // 调整音量
    player->setVolume(value);
}

void MainWindow::on_hSliderPlayStatus_valueChanged(int value)
{
    // 文件进度调控
    player->setPosition(value);
}
