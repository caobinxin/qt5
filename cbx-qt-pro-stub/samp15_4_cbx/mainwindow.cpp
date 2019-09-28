#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 创建显示图表
    QChart *chart = new QChart;
    chart->setTitle("音频输入原始信号");

    ui->graphicsView->setChart(chart);
    lineSeries = new QLineSeries(); // 序列
    chart->addSeries(lineSeries);

    QValueAxis *axisX = new QValueAxis; // 坐标轴
    axisX->setRange(0, displayPointCount); // chart 显示　4000 个采样点数据
    axisX->setLabelFormat("%g");
    axisX->setTitleText("samples");

    QValueAxis *axisY = new QValueAxis; // y坐标轴
    axisY->setRange(0, 256); // unSingedInt 采样，　数据范围 0 ~ 255
    axisY->setTitleText("Audio level");

    chart->setAxisX(axisX, lineSeries);
    chart->setAxisY(axisY, lineSeries);
    chart->legend()->hide();

    ui->comboBoxInputDevs->clear();
    deviceList = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    for(int i=0; i < deviceList.count(); i++){
        QAudioDeviceInfo device = deviceList.at(i);
        ui->comboBoxInputDevs->addItem(device.deviceName());
    }

    if(deviceList.size() > 0){
        ui->comboBoxInputDevs->setCurrentIndex(0);
        curDevice = deviceList.at(0);
    }else{
        ui->actionStart->setEnabled(false);
        ui->actionTestSettings->setEnabled(false);
        ui->groupBox->setTitle("支持的音频输入设置(无设备)");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::SampleTypeString(QAudioFormat::SampleType sampleType)
{
    // 将QAudioFormat::SampleType 类型转换为字符串
    QString result("Unknown");
    switch (sampleType) {
        case QAudioFormat::SignedInt:
            result = "SignedInt"; break;
        case QAudioFormat::UnSignedInt:
            result = "UnSignedInt"; break;
        case QAudioFormat::Float:
            result = "Float"; break;
        case QAudioFormat::Unknown:
            result = "Unknown";
    }
    return result;
}

QString MainWindow::ByteOrderString(QAudioFormat::Endian endian)
{
    // 将　QAudioFormat::Endian 转换为字符串
    if(endian == QAudioFormat::LittleEndian) return "LittleEndian";
    else if(endian == QAudioFormat::BigEndian) return "BigEndian";
    else return "Unknown";
}

void MainWindow::on_IODevice_UpdateBlockSize(qint64 blockSize)
{

}

void MainWindow::on_comboBoxInputDevs_currentIndexChanged(int index)
{
    // 选择音频输入设备
    curDevice = deviceList.at(index); // 当前音频设备
    ui->comboBoxCodec->clear(); // 支持的音频编码
    QStringList codecs = curDevice.supportedCodecs();
    for(int i = 0; i < codecs.size(); ++i){
        ui->comboBoxCodec->addItem(codecs.at(i));
    }

    ui->comboBoxSampleRate->clear(); // 采样频率
    QList<int> sampleRate = curDevice.supportedSampleRates();
    for(int i = 0; i < sampleRate.size(); ++i){
        ui->comboBoxSampleRate->addItem(QString("%1").arg(sampleRate.at(i)));
    }

    ui->comboBoxChannals->clear(); // 支持的通道数
    QList<int> Channels = curDevice.supportedChannelCounts();
    for(int i = 0; i < Channels.size(); i++){
        ui->comboBoxChannals->addItem(QString("%1").arg(Channels.at(i)));
    }

    ui->comboBoxSamplaType->clear(); // 支持的采样点类型
    QList<QAudioFormat::SampleType> sampleTypes = curDevice.supportedSampleTypes();
    for(int i = 0; i < sampleTypes.size(); i++){
        ui->comboBoxSamplaType->addItem(SampleTypeString(sampleTypes.at(i)), QVariant(sampleTypes.at(i)));
    }

    ui->comboBoxSampleSize->clear(); // 采样点大小
    QList<int> sampleSizes = curDevice.supportedSampleSizes();
    for(int i = 0; i < sampleSizes.size(); i++){
        ui->comboBoxSampleSize->addItem(QString("%1").arg(sampleSizes.at(i)));
    }

    ui->comboBoxEndianners->clear(); // 字节序
    QList<QAudioFormat::Endian> endians = curDevice.supportedByteOrders();
    for(int i = 0; i < endians.size(); i++){
        ui->comboBoxEndianners->addItem(ByteOrderString(endians.at(i)));
    }
}

void MainWindow::on_actionTestSettings_triggered()
{
    // 测试音频输入设备是否支持　选择的设置
    QAudioFormat settings;
    settings.setCodec(ui->comboBoxCodec->currentText());
    settings.setSampleRate(ui->comboBoxSampleRate->currentText().toInt());
    settings.setChannelCount(ui->comboBoxChannals->currentText().toInt());
    settings.setSampleType(QAudioFormat::SampleType(
                               ui->comboBoxSamplaType->currentData().toInt()));

    settings.setSampleSize(ui->comboBoxSampleSize->currentText().toInt());

    if(ui->comboBoxEndianners->currentText() == "LittleEndian"){
        settings.setByteOrder(QAudioFormat::LittleEndian);
    }else {
        settings.setByteOrder(QAudioFormat::BigEndian);
    }

    if(curDevice.isFormatSupported(settings)){
        QMessageBox::information(this, "音频测试", "测试成功，输入设备支持此设置");
    }else{
        QMessageBox::critical(this, "音频测试", "测试失败, 输入设备不支持此设置");
    }
}

void MainWindow::on_actionStart_triggered()
{
    // 开始音频输入
    QAudioFormat defaultAudioFormat; // 缺省格式
    defaultAudioFormat.setSampleRate(8000);
    defaultAudioFormat.setChannelCount(1);
    defaultAudioFormat.setSampleSize(8);
    defaultAudioFormat.setCodec("audio/pcm");
    defaultAudioFormat.setByteOrder(QAudioFormat::LittleEndian);
    defaultAudioFormat.setSampleType(QAudioFormat::UnSignedInt);
    if(!curDevice.isFormatSupported(defaultAudioFormat)){
        QMessageBox::critical(this, "测试", "测试失败, 输入设备不支持此设置");
        return;
    }

    audioInput = new QAudioInput(curDevice, defaultAudioFormat, this);
    audioInput->setBufferSize(displayPointCount);

    // 接受音频输入数据的流设备
    displayDevice = new QmyDisplayDevice(lineSeries, displayPointCount, this);

    connect(displayDevice, SIGNAL(updateBlockSize(qint64 blockSize)), this, SLOT(on_IODevice_UpdateBlockSize(qint64)));

    displayDevice->open(QIODevice::WriteOnly);

    audioInput->start(displayDevice);
    ui->actionStart->setEnabled(false);
    ui->actionStop->setEnabled(true);
}
