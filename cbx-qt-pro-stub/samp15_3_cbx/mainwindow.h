                                           #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAudioRecorder>
#include <QAudioProbe>
#include <QMessageBox>
#include <QFile>
#include <QUrl>

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
    QAudioRecorder *recorder; // 音频录音
    QAudioProbe *probe; // 探测 缓冲区

private slots:
    // 自定义槽函数
    void onStateChanged(QMediaRecorder::State state);
    void onDurationChanged(qint64 duration);
    void processBuffer(const QAudioBuffer &buffer);
    void on_actionRecord_triggered();
    void on_actionPause_triggered();
    void on_actionStop_triggered();
};

#endif // MAINWINDOW_H
