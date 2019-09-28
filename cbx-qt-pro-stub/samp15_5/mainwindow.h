#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "qmyvideowidget.h"

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
    QMediaPlayer *player; // 视频播放器
    QString durationTime;
    QString positionTime;

private slots:
    void on_StateChanged(QMediaPlayer::State state);
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void on_pushButtonOpenFile_clicked();
    void on_pushButtonPlay_clicked();
    void on_pushButtonPause_clicked();
    void on_pushButtonStop_clicked();
    void on_horizontalSliderVolume_valueChanged(int value);
    void on_pushButtonVolume_clicked();
    void on_horizontalSliderDuration_valueChanged(int value);
    void on_pushButtonFullWindow_clicked();
};

#endif // MAINWINDOW_H
