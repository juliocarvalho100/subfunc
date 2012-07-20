#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QLCDNumber>
#include <QWidget>
#include <QHBoxLayout>

 class DigitalClock : public QLCDNumber
 {
     Q_OBJECT

 public:
     DigitalClock(QWidget *parent = 0);

 private slots:
     void showTime();
 };



 class DigitalClockWidget : public QWidget
 {
     Q_OBJECT

 public:
     DigitalClockWidget(QWidget *parent = 0);

 private slots:
     void showTime();

 private:
     QHBoxLayout *myQHBoxLayout;
     QLCDNumber *myQLCDNumber;
 };


#endif // DIGITALCLOCK_H
