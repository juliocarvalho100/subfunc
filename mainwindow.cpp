#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "digitalclock.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DigitalClockWidget *myClockWidget = new DigitalClockWidget();
    ui->verticalLayout->addWidget(myClockWidget);
    myClockWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_2_tabCloseRequested(int index)
{
    ui->tabWidget_2->removeTab(index);
}
