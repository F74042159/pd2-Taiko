#include "drum.h"
#include <QTimer>

extern Game *game;//there is an external global object called game

Drum::Drum(QGraphicsItem*parent)
{
    //set drums
    setRect(0,0,10,50);
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}


 void Drum::move(){
    //if drum collides with target, destroy drum
    QList<QGraphicsItem*>colliding_item = collidingItems();
    for(int i=0,n=colliding_item.size();i<n;i++){
        if(typeid(*(colliding_item[i]))==typeid(Enemy)){
            //increase the score

            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_item[i]);
            scene()->removeItem(this);

            //delete them both
            delete colliding_item[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(),y()-10);
    if(pos().y()+rect().height()<0){
        scene()->removeItem(this);
        delete this;
    }

}

