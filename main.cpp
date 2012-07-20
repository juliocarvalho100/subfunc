#include <QtGui/QApplication>
#include "mainwindow.h"
#include "thread.h"
#include <QDebug>

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
    
    return app.exec();
}
