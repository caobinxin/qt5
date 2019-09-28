#ifndef QMYVIDEOWIDGET_H
#define QMYVIDEOWIDGET_H

#include <QVideoWidget>
#include <QMediaPlayer>
class QmyVideoWidget : public QVideoWidget
{
public:
    QmyVideoWidget(QWidget *parent = Q_NULLPTR);
private:
    QMediaPlayer *thePlayer;

protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);

public:
    void setMediaPlayer(QMediaPlayer *player);
};

#endif // QMYVIDEOWIDGET_H
