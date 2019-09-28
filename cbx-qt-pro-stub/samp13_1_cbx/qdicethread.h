#ifndef QDICETHREAD_H
#define QDICETHREAD_H
#include <QThread>
#include <QTime>

class QDiceThread : public QThread
{
    Q_OBJECT
    // 如果要引用qt中的特性，　就要在最开始的地方，添加　Q_OBJECT　很关键的
public:
    QDiceThread();

private:
    int m_seq = 0; // 掷骰子次数序号
    int m_diceValue; // 骰子点数
    bool m_paused = true; // 暂停
    bool m_stop = false; // 停止

protected:
    void run() Q_DECL_OVERRIDE; // 线程任务

public:
    void diceBegin(); // 掷一次骰子
    void dicePause(); // 暂停
    void stopThread(); // 结束线程

signals:
    void newValue(int seq, int diceValue); // 产生新点数的信号
};

#endif // QDICETHREAD_H
