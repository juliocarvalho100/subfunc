#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QMutex>
//class QThread;

// http://doc.qt.nokia.com/4.7-snapshot/thread-basics.html#example-3-clock
// hellothread/hellothread.h
class HelloThread : public QThread
{
    Q_OBJECT
private:
    void run();
    void work();
    QMutex mutex;
};

#endif // THREAD_H
