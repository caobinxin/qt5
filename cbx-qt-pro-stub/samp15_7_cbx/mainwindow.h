#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QLabel>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QMessageBox>
#include <QFile>
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
    QCamera *curCamera = Q_NULLPTR;
    QCameraImageCapture *imageCapture; // 抓图
    QMediaRecorder *mediaRecorder; // 录像
    QLabel *labCameraState;
    QLabel *LabInfo;
    QLabel *LabCameraMode;

    void iniCamera(); // 初始化
    void iniImageCapture(); // 初始化静态抓图
    void iniVideoRecorder(); // 初始化视屏录制

private slots:
    void on_cameraStateChanged(QCamera::State state);
    void on_cameraCaptureModeChanged(QCamera::CaptureModes mode);

    // QCameraImageCapture 的槽函数
    void on_imageReadyForCapture(bool ready);
    void on_imageCaptured(int id, const QImage &preview);
    void on_imageSaved(int id, const QString &fileName);

    // QMediaRecorder 的槽函数
    void on_videoStateChanged(QMediaRecorder::State state);
    void on_videoDurationChanged(qint64 duration);

    void on_actionOpenCamera_triggered();
    void on_actionCloseCamera_triggered();
    void on_actionCapture_triggered();
    void on_actionStart_triggered();
    void on_actionStop_triggered();
};

#endif // MAINWINDOW_H
