#include "timer.h"
#include <QTimer>

Timer::Timer(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    time=30;

    //draw the text
    setPlainText(QString("Time: ")+QString::number(time));//Time:30
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

void Timer::decrease()
{
    //QTimer *timer2= new QTimer(this);
    //connect(timer2,SIGNAL(timeout()),this,SLOT(countdown()));
    //timer2->start(1000);

    setPlainText(QString("Timer: ")+QString::number(time));//score:29...
}
void Timer::countdown(){
    time--;
}
