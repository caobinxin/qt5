#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    recorder = new QAudioRecorder(this);
    connect(recorder, SIGNAL(stateChanged(QMediaRecorder::State)),
            this, SLOT(onStateChanged(QMediaRecorder::State)));

    connect(recorder, SIGNAL(durationChanged(qint64)),
            this, SLOT(onDurationChanged(qint64)));

    probe = new QAudioProbe; // 探测缓冲区
    connect(probe, SIGNAL(audioBufferProbed(QAudioBuffer)),
            this, SLOT(processBuffer(QAudioBuffer)));

    probe->setSource(recorder); // 指定探测对象

    if(recorder->defaultAudioInput().isEmpty()){
        return; // 无音频输入设备
    }

    foreach(const QString &device, recorder->audioInputs()){
        ui->comboBoxInputDev->addItem(device); // 音频输入设备列表
    }

    foreach(const QString &codecName, recorder->supportedAudioCodecs()){
        ui->comboBoxCode->addItem(codecName); // 支持的音频编码
    }

    foreach(int sampleRate, recorder->supportedAudioSampleRates()){
        ui->comboBoxSamplingRate->addItem(QString::number(sampleRate)); // 采样率设置
    }

    // channels 通道数
    ui->comboBoxChannalCount->addItem("1");
    ui->comboBoxChannalCount->addItem("2");
    ui->comboBoxChannalCount->addItem("4");

    // quality 品质
    ui->horizontalSliderFixedQuality->setRange(0, int(QMultimedia::VeryHighQuality));
    ui->horizontalSliderFixedQuality->setValue(int(QMultimedia::NormalQuality));

    // bitrates 比特率
    ui->comboBoxFixedBitRate->addItem("32000");
    ui->comboBoxFixedBitRate->addItem("64000");
    ui->comboBoxFixedBitRate->addItem("96000");
    ui->comboBoxFixedBitRate->addItem("128000");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStateChanged(QMediaRecorder::State state)
{
    // 根据recorder 的 stateChanged()信号，　更新 ui 中的 暂停 停止　等按钮的使能状态
    ui->actionRecord->setEnabled(state != QMediaRecorder::RecordingState);
    ui->actionPause->setEnabled(state == QMediaRecorder::RecordingState);
    ui->actionStop->setEnabled(state == QMediaRecorder::RecordingState);
    ui->btnGetFile->setEnabled(state == QMediaRecorder::StoppedState);
    ui->lineEditOutFile->setEnabled(state==QMediaRecorder::StoppedState);
}

void MainWindow::onDurationChanged(qint64 duration)
{
    // 录音持续时间变化
    ui->labelRecordDuration->setText(QString("已录制 %1 秒").arg(duration / 1000));
}

void MainWindow::processBuffer(const QAudioBuffer &buffer)
{
    // 处理探测到的缓冲区
    ui->spinBoxBufByteCount->setValue(buffer.byteCount()); // 缓冲区字节数
    ui->spinBoxBufDuration->setValue(buffer.duration() / 1000); // 缓冲区时长
    ui->spinBoxFrameNumber->setValue(buffer.frameCount()); // 缓冲区帧数
    ui->spinBoxSamplingRate->setValue(buffer.sampleCount()); // 缓冲区采样数
    QAudioFormat audioFormat = buffer.format(); // 缓冲区格式

    ui->spinBoxChannolCount->setValue(audioFormat.channelCount()); //通道数
    ui->spinBoxSampleSize->setValue(audioFormat.sampleSize()); // 采样大小
    ui->spinBoxSampleRate->setValue(audioFormat.sampleRate()); // 采样率
    ui->spinBoxBytePerFrame->setValue(audioFormat.bytesPerFrame());

    if(audioFormat.byteOrder() == QAudioFormat::LittleEndian){
        ui->lineEditByteOrder->setText("LittleEndian"); // 小端
    }else{
        ui->lineEditByteOrder->setText("BigEndian"); // 大端
    }

    ui->lineEditCode->setText(audioFormat.codec()); // 编码格式

    if(audioFormat.sampleType() == QAudioFormat::SignedInt)// 采样点类型
        ui->lineEditSampleType->setText("SignedInt");
    else if(audioFormat.sampleType() == QAudioFormat::UnSignedInt)
        ui->lineEditSampleType->setText("UnsignedInt");
    else if(audioFormat.sampleType() == QAudioFormat::Float)
        ui->lineEditSampleType->setText("Float");
    else {
        ui->lineEditSampleType->setText("Unknown");
    }
}

void MainWindow::on_actionRecord_triggered()
{
   // 开始录音
    if(recorder->state() == QMediaRecorder::StoppedState){ // 已停止, 重新设置
        QString selectedFile = ui->lineEditOutFile->text().trimmed();
        if(selectedFile.isEmpty()){
            QMessageBox::critical(this, "错误", "请先设置输出文件");
            return;
        }

        if(QFile::exists(selectedFile)){
            if(!QFile::remove(selectedFile)){
                QMessageBox::critical(this, "错误", "所设置录音输出文件无法删除");
                return;
            }
        }

        recorder->setOutputLocation(QUrl::fromLocalFile(selectedFile));
        recorder->setAudioInput(ui->comboBoxInputDev->currentText()); // 输入设备
        QAudioEncoderSettings settings; // 音频编码设置
        settings.setCodec(ui->comboBoxCode->currentText()); // 编码
        settings.setSampleRate(ui->comboBoxSamplingRate->currentText().toInt());
        settings.setBitRate(ui->comboBoxFixedBitRate->currentText().toInt()); // 比特率
        settings.setChannelCount(ui->comboBoxChannalCount->currentText().toInt());
        settings.setQuality(QMultimedia::EncodingQuality(ui->horizontalSliderFixedQuality->value()));

        if(ui->radioButtonFixedQuality->isChecked()){
            // 编码模式为固定模式
            settings.setEncodingMode(QMultimedia::ConstantQualityEncoding);
        }else{
            settings.setEncodingMode(QMultimedia::ConstantBitRateEncoding);
        }

        recorder->setAudioSettings(settings); // 音频设置
    }

    recorder->record();
}

void MainWindow::on_actionPause_triggered()
{
    // 暂停
    recorder->pause();
}

void MainWindow::on_actionStop_triggered()
{
    // 停止
    recorder->stop();
}
