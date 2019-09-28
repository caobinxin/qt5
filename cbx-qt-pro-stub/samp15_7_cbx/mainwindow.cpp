#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labCameraState = new QLabel("摄像头state:");
    labCameraState->setMinimumWidth(150);
    ui->statusBar->addWidget(labCameraState);

    LabCameraMode = new QLabel("抓取模式:");
    LabCameraMode->setMinimumWidth(150);
    ui->statusBar->addWidget(LabCameraMode);

    LabInfo = new QLabel("");
    ui->statusBar->addPermanentWidget(LabInfo);

    // 枚举出当前系统中的摄像头资源
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.size() > 0){
        iniCamera(); // 初始化摄像头
        iniImageCapture(); // 初始化静态抓图
        iniVideoRecorder(); // 初始化视屏录制
        curCamera->start();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniCamera()
{
    // 创建　QCamera 对象
    QCameraInfo curCameraInfo = QCameraInfo::defaultCamera(); // 获取系统默认的摄像头
    ui->comboBoxCameraDevices->addItem(curCameraInfo.description());
    ui->comboBoxCameraDevices->setCurrentIndex(0);

    curCamera = new QCamera(curCameraInfo, this); // 创建摄像头对象
    QCameraViewfinderSettings viewfinderSettings;
    viewfinderSettings.setResolution(640, 480);
    viewfinderSettings.setMinimumFrameRate(15.0);
    viewfinderSettings.setMaximumFrameRate(30.0);
    curCamera->setViewfinderSettings(viewfinderSettings);
    curCamera->setViewfinder(ui->viewFinder); // 设置预览框
    curCamera->setCaptureMode(QCamera::CaptureViewfinder);

    // 判断摄像头　是否支持抓图，　录制视屏
    ui->checkBoxCapture->setChecked(
                curCamera->isCaptureModeSupported(QCamera::CaptureStillImage)); // 抓图

    ui->checkBoxVideotape->setChecked(curCamera->isCaptureModeSupported(QCamera::CaptureVideo)); // 视屏录制

    connect(curCamera, SIGNAL(stateChanged(QCamera::State)),
            this, SLOT(on_cameraStateChanged(QCamera::State)));

    connect(curCamera, SIGNAL(captureModeChanged(QCamera::CaptureModes)),
            this, SLOT(on_cameraCaptureModeChanged(QCamera::CaptureModes)));

}

void MainWindow::iniImageCapture()
{
    // 创建 QCameraImageCapture 对象
    imageCapture = new QCameraImageCapture(curCamera, this);
    imageCapture->setBufferFormat(QVideoFrame::Format_Jpeg); // 缓冲区格式

    // 设置抓图存储目标为文件，　抓取的图片会自动保存到用户目录的　图片　文件夹里
    imageCapture->setCaptureDestination(
                QCameraImageCapture::CaptureToFile); // 保存目标

    connect(imageCapture, SIGNAL(readyForCaptureChanged(bool)),
            this, SLOT(on_imageReadyForCapture(bool)));

    connect(imageCapture, SIGNAL(imageCaptured(int, const QImage &)),
            this, SLOT(on_imageCaptured(int, const QImage &)));

    connect(imageCapture, SIGNAL(imageSaved(int, const QString &)),
            this, SLOT(on_imageSaved(int, const QString &)));
}

void MainWindow::iniVideoRecorder()
{
    // 创建　QMediaRecorder 对象
    mediaRecorder = new QMediaRecorder(curCamera, this);
    ui->checkBoxMute->setChecked(mediaRecorder->isMuted());

    connect(mediaRecorder, SIGNAL(stateChanged(QMediaRecorder::State)),
            this, SLOT(on_videoStateChanged(QMediaRecorder::State)));

    connect(mediaRecorder, SIGNAL(durationChanged(qint64)),
            this, SLOT(on_videoDurationChanged(qint64)));
}

void MainWindow::on_cameraStateChanged(QCamera::State state)
{
    // 摄像机状态变化时
    switch (state) {
        case QCamera::UnloadedState:
            labCameraState->setText("摄像头state: UnloadedState"); break;

        case QCamera::LoadedState:
            labCameraState->setText("摄像头state: LoadedState"); break;

        case QCamera::ActiveState:
            labCameraState->setText("摄像头state: ActiveState");
    }

    ui->actionStart->setEnabled(state != QCamera::ActiveState);
    ui->actionStop->setEnabled(state == QCamera::ActiveState);
}

void MainWindow::on_cameraCaptureModeChanged(QCamera::CaptureModes mode)
{
    if(mode == QCamera::CaptureStillImage){
        LabCameraMode->setText("抓取模式:stillImage");
    }else if(mode == QCamera::CaptureVideo){
        LabCameraMode->setText("抓取模式:Video");
    }else{
        LabCameraMode->setText("抓取模式: Viewfinder");
    }
}

void MainWindow::on_imageReadyForCapture(bool ready)
{
    // 可以抓图了
    ui->actionCapture->setEnabled(ready);
}

void MainWindow::on_imageCaptured(int id, const QImage &preview)
{
    // 抓取图片后显示
    Q_UNUSED(id);
    QImage scaledImage = preview.scaled(ui->labelImg->size(),
                                        Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->labelImg->setPixmap(QPixmap::fromImage(scaledImage));
}

void MainWindow::on_imageSaved(int id, const QString &fileName)
{
    // 文件保存后显示保存的文件名
    Q_UNUSED(id);
    LabInfo->setText("图片保存为: " + fileName);
}

void MainWindow::on_videoStateChanged(QMediaRecorder::State state)
{
    // 状态变化
    ui->actionStart->setEnabled(state != QMediaRecorder::RecordingState);
    ui->actionStop->setEnabled(state == QMediaRecorder::RecordingState);
}

void MainWindow::on_videoDurationChanged(qint64 duration)
{
    ui->labelRecordTime->setText(QString::asprintf("录制时间: %1 秒").arg(duration / 1000));
}

void MainWindow::on_actionOpenCamera_triggered()
{
    // 开启摄像头
    curCamera->start();
}

void MainWindow::on_actionCloseCamera_triggered()
{
    // 关闭摄像头
    curCamera->stop();
}

void MainWindow::on_actionCapture_triggered()
{
    // 抓图　按钮
    if(curCamera->captureMode() != QCamera::CaptureStillImage){
        curCamera->setCaptureMode(QCamera::CaptureStillImage);
    }
    imageCapture->capture();
}

void MainWindow::on_actionStart_triggered()
{
    // 开始录像
    if(!mediaRecorder->isAvailable()){
        QMessageBox::critical(this, "错误", "不支持视屏录制!\n mediaRecorder->isAvailable() == false");
        return;
    }

    if(curCamera->captureMode() != QCamera::CaptureVideo){
        curCamera->setCaptureMode(QCamera::CaptureVideo);
    }

    QString selectedFile = ui->lineEditSaveFileName->text().trimmed();
    if(selectedFile.isEmpty()){
        QMessageBox::critical(this, "错误", "请先设置录音输出文件");
        return;
    }

    if(QFile::exists(selectedFile)){
        if(!QFile::remove(selectedFile)){
            QMessageBox::critical(this, "错误", "所设置录音输出文件被占用, 无法删除");
            return;
        }
    }

    mediaRecorder->setOutputLocation(QUrl::fromLocalFile(selectedFile));
    mediaRecorder->record();
}

void MainWindow::on_actionStop_triggered()
{
    // 停止录像
    mediaRecorder->stop();
}
