#ifndef QMYCAMERABASE_H
#define QMYCAMERABASE_H

#include <QObject>
#include    <QCameraInfo>
#include    <QCamera>
#include    <QLabel>

#include    <QCameraViewfinder>
#include    <QCameraImageCapture>
#include    <QMediaRecorder>

class QMyCameraBase : public QObject
{
    Q_OBJECT

private:
    QCamera     *curCamera=Q_NULLPTR;//

    QCameraImageCapture *imageCapture; //抓图
    QMediaRecorder* mediaRecorder;//录像
    QVideoWidget *videoItem; // 视图

    QLabel   *LabCameraState;
    QLabel   *LabInfo;
    QLabel   *LabCameraMode;

public:
//    void    iniCamera(QGraphicsVideoItem *videoItem);//初始化

    void    iniCamera(QVideoWidget *videoItem);//初始化
    void    iniImageCapture();//初始化静态画图
    void    iniVideoRecorder();//初始化视频录制

public:
    explicit QMyCameraBase(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QMYCAMERABASE_H
