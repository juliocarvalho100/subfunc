#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QMutex>
#include <QRunnable>
#include <QDebug>

// http://doc.qt.nokia.com/4.7-snapshot/thread-basics.html#example-3-clock
// hellothread/hellothread.h
class HelloThread : public QThread
{
    Q_OBJECT
public:
    HelloThread(){number = 100.0;}
    void method1();
    void method2();
    void work();
private:
    void run();
    QMutex mutex;
    double number;
};

// http://doc-snapshot.qt-project.org/4.8/thread-basics.html#example-3-clock
class Work : public QRunnable
{
public:
    void run()
    {
        qDebug() << "Hello from thread " << QThread::currentThread();
    }
};

class ClockThread : public QThread
{
    Q_OBJECT
signals:
    void sendTime(QString time);
private:
    void run();
    QString m_lastTime;
private slots:
    void timerHit();

};

#endif // THREAD_H


