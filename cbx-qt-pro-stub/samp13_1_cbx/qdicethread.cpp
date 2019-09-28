#include "qdicethread.h"

QDiceThread::QDiceThread()
{

}

void QDiceThread::diceBegin()
{
    // 开始掷骰子
    m_paused = false;
}

void QDiceThread::dicePause()
{
    // 暂停掷骰子
    m_paused = true;
}

void QDiceThread::stopThread()
{
    // 停止线程
    m_stop = true;
}

void QDiceThread::run()
{
    // 线程的任务
    m_stop = false; //
    m_seq = 0; // 掷骰子的次数
    qsrand(QTime::currentTime().msec()); // 随机数初始化，qsrand 是线程安全的
    while(!m_stop){
        // 循环主体
        if(!m_paused){
            m_diceValue = qrand(); // 获取随机数
            m_diceValue = (m_diceValue % 6) + 1;
            m_seq++;
            emit newValue(m_seq,m_diceValue); // 发射信号
        }
        msleep(500); // 线程休眠 500ms
    }
    quit(); // 相当于 exit(0), 退出线程的事件循环
}
