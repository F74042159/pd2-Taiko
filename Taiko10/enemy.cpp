#include "enemy.h"
#include <QTimer>
#include <QDebug>


Enemy::Enemy()
{
    setPos(800,120);

    //draw the rect,random red or blue
    setPixmap(QPixmap(":/pics/picture/drum_blue"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}


 void Enemy::move(){
    // move enemy down
    setPos(x()-10,y());
    if(pos().x()+50<0){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"enemy deleted";
    }
}
