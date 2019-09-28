#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
using namespace QtCharts;
#include <QAudioInput>

#include <QAudioDeviceInfo>

#include "qmydisplaydevice.h"
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
    const qint64 displayPointCount = 4000;
    QLineSeries *lineSeries; // 曲线序列
    QList<QAudioDeviceInfo> deviceList; // 音频输入设备列表
    QAudioDeviceInfo curDevice; // 当前输入设备
    QmyDisplayDevice *displayDevice; // 用于显示的IODevice
    QAudioInput *audioInput; // 音频输入设备
    QString SampleTypeString(QAudioFormat::SampleType sampleType);
    QString ByteOrderString(QAudioFormat::Endian endian);

private slots:
    void on_IODevice_UpdateBlockSize(qint64 blockSize);
    void on_comboBoxInputDevs_currentIndexChanged(int index);
    void on_actionTestSettings_triggered();
    void on_actionStart_triggered();
};

#endif // MAINWINDOW_H
