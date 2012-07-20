#include <QtGui/QApplication>
#include "mainwindow.h"
#include "thread.h"
#include <QDebug>
#include <QThreadPool>
#include <QFuture>
#include <QtCore>
#include <QtGui>

void hello()
{
    qDebug() << "Hello from thread " << QThread::currentThread();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    //QTableWidget tableWidget(12, 3);
    //tableWidget.show();

    HelloThread thread;
    thread.start();
    qDebug() << "hello from GUI thread " << app.thread()->currentThreadId();
    thread.wait();  // do not exit before the thread is completed!

    thread.work();
    thread.method1();
    thread.method2();


    // 1. Using the thread pool
    qDebug() << "\n1. Using the thread pool";
    Work work;
    work.setAutoDelete(false);
    QThreadPool *threadPool = QThreadPool::globalInstance();
    threadPool->start(&work);
    qDebug() << "hello from GUI thread " << QThread::currentThread();
    threadPool->waitForDone();

    // 2. Using QtConcurrent
    qDebug() << "\n2. Using QtConcurrent";
    QFuture<void> future = QtConcurrent::run(hello);
    qDebug() << "hello from GUI thread " << QThread::currentThread();
    future.waitForFinished();

    // 3.Clock
    // http://doc-snapshot.qt-project.org/4.8/thread-basics.html#example-3-clock
    QWidget widget;
    QLabel *label = new QLabel;
    QHBoxLayout *layout = new QHBoxLayout(&widget);
    layout->addWidget(label);
    widget.setWindowTitle("clock");
    //instantiate thread object
    ClockThread clockThread;
    QObject::connect(&clockThread, SIGNAL(sendTime(QString)), label, SLOT(setText(QString)), Qt::QueuedConnection);
    clockThread.start();
    widget.show();
    app.exec();
    clockThread.quit();
    clockThread.wait();


    
    return app.exec();
}
