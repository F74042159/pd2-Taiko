#include "blue_drum.h"

extern Game *game;//there is an external global object called game

BlueDrum::BlueDrum()
{
    //create pressSound
    pressSound = new QMediaPlayer();
    pressSound->setMedia(QUrl("qrc:/sounds/music/drum.mp3"));

    setPos(800,120);
    //draw the rect,random red or blue
    setPixmap(QPixmap(":/pics/picture/drum_blue"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}


 void BlueDrum::move(){
     //if drum collides with target, focus on bluedrum
     if(pos().x()==70){
         this->setFlag(QGraphicsItem::ItemIsFocusable);
         this->setFocus();
     }
     //clear the focus
     if(pos().x()==30) this->clearFocus();

    // move drum left
    setPos(x()-10,y());
    if(pos().x()+50<0){
        scene()->removeItem(this);
        delete this;
    }
}

 void BlueDrum::keyPressEvent(QKeyEvent *event){
     if (event->key() == Qt::Key_K){

         //play pressSound
         if (pressSound->state() == QMediaPlayer::PlayingState){
            pressSound->setPosition(0);
         }
         else if (pressSound->state() == QMediaPlayer::StoppedState){
          pressSound->play();
         }

         //remove the drum
         scene()->removeItem(this);
         //delete the drum
         delete this;
         //increase the score
         game->score->increase();

     }
}

