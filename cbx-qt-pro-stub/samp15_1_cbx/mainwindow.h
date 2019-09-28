#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDir>
#include <QFileDialog>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    QMediaPlayer *player; // 播放器
    QMediaPlaylist *playList; // 播放列表
    QString durationTime; // 总长度
    QString positionTime; // 当前播放到的位置

private slots:
    // 自定义槽函数
    void onStateChanged(QMediaPlayer::State state); // 更新　播放，暂停，停止　按钮的状态
    void onPlaylistChanged(int position); //
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);

    void on_btnAdd_clicked();
    void on_btnRemove_clicked();
    void on_btnClear_clicked();
    void on_listWidget_doubleClicked(const QModelIndex &index);
    void on_btnPlay_clicked();
    void on_btnPause_clicked();
    void on_btnStop_clicked();
    void on_pushButton_9_clicked();
    void on_hSliderVolume_valueChanged(int value);
    void on_hSliderPlayStatus_valueChanged(int value);
};

#endif // MAINWINDOW_H
