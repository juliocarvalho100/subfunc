#include "thread.h"
#include <QThread>
#include <QDebug>
#include <QMutex>

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
