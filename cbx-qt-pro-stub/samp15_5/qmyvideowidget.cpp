#include "qmyvideowidget.h"
#include <QKeyEvent>

QmyVideoWidget::QmyVideoWidget(QWidget *parent)
{

}

void QmyVideoWidget::keyPressEvent(QKeyEvent *event)
{
    // 按键事件，　esc 退出全屏事件
    if((event->key() == Qt::Key_Escape) && (isFullScreen())){
        setFullScreen(false);
        event->accept();
        QVideoWidget::keyPressEvent(event);
    }
}

void QmyVideoWidget::mousePressEvent(QMouseEvent *event)
{
    // 鼠标事件，单击控制暂停和继续播放
    if(event->button() == Qt::LeftButton){
        if(thePlayer->state() == QMediaPlayer::PlayingState){
            thePlayer->pause();
        }else{
            thePlayer->play();
        }
    }
    QVideoWidget::mousePressEvent(event);
}

void QmyVideoWidget::setMediaPlayer(QMediaPlayer *player)
{
    // 设置播放器
    thePlayer = player;
}
