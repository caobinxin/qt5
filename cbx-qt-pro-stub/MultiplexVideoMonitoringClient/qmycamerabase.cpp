#include "qmycamerabase.h"

void QMyCameraBase::iniCamera(QVideoWidget *videoItem)
{
    //  创建  QCamera对象
        this->videoItem = videoItem;

        QCameraInfo curCameraInfo=QCameraInfo::defaultCamera(); //获取缺省摄像头

        curCamera=new QCamera(curCameraInfo,this); //创建摄像头对象

        QCameraViewfinderSettings viewfinderSettings;
        viewfinderSettings.setResolution(640, 480);
        viewfinderSettings.setMinimumFrameRate(15.0);
        viewfinderSettings.setMaximumFrameRate(30.0);
        curCamera->setViewfinderSettings(viewfinderSettings);

        curCamera->setViewfinder(this->videoItem); //设置取景框预览
        curCamera->setCaptureMode(QCamera::CaptureVideo);

        connect(curCamera,SIGNAL(stateChanged(QCamera::State)),
                this,SLOT(on_cameraStateChanged(QCamera::State)));
        connect(curCamera,SIGNAL(captureModeChanged(QCamera::CaptureModes)),
                this,SLOT(on_cameraCaptureModeChanged(QCamera::CaptureModes)));
        curCamera->start();
}

QMyCameraBase::QMyCameraBase(QObject *parent) : QObject(parent)
{

}

