#include <QtGui/QApplication>
#include "mainwindow.h"


// http://doc.qt.nokia.com/4.7-snapshot/thread-basics.html#example-3-clock
// hellothread/hellothread.h
 class HelloThread : public QThread
 {
     Q_OBJECT
 private:
     void run(){
        qDebug() << "hello from worker thread " << thread()->currentThreadId();
     }
 };

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //QTableWidget tableWidget(12, 3);
    //tableWidget.show();

    HelloThread thread;
    thread.start();
    qDebug() << "hello from GUI thread " << app.thread()->currentThreadId();
    thread.wait();  // do not exit before the thread is completed!
    
    return a.exec();
}
