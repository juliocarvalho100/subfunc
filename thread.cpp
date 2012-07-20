#include "thread.h"
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QTimer>
#include <QDateTime>

void HelloThread::run()
{
    qDebug() << "hello from worker thread "
             << thread()->currentThreadId();
}

void HelloThread::work()
{
    this->mutex.lock();  // first thread can pass, other threads will be blocked here
    qDebug() << "Executing a thread-safe method...";
    this->mutex.unlock();
}

void HelloThread::method1()
{
    //mutex.lock();
    QMutexLocker locker(&mutex);

    number++;
    qDebug() << "number: " << number;
    number *= 5; qDebug() << "Multiply by 5"; qDebug() << number;
    number /= 4; qDebug() << "Devide by 4"; qDebug() << number;

    //mutex.unlock();
}

void HelloThread::method2()
{

    QMutexLocker locker(&mutex);
    number++;
    qDebug() << "number: " << number;
    number *= 3; qDebug() << "Multiply by 3"; qDebug() << number;
    number /= 2; qDebug() << "Devide by 2"; qDebug() << number;
}


void ClockThread::run()
{
    QTimer timer;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerHit()), Qt::DirectConnection);
    timer.setInterval(10);
    timer.start();   // puts one event in the threads event queue
    exec();
    timer.stop();
}

void ClockThread::timerHit()
{
    QString newTime= QDateTime::currentDateTime().toString("ddd MMMM d yy, hh:mm:ss");
    if(m_lastTime != newTime ){
        m_lastTime = newTime;
        emit sendTime(newTime) ;
    }
}
