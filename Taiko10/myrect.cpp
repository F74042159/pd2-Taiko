#include "myrect.h"

#include "red_drum.h" //why can't I put this in myrect.h
#include "blue_drum.h" //why can't I put this in myrect.h
#include "game.h" //why can't I put this in myrect.h

extern Game *game;//there is an external global object called game

MyRect::MyRect(){
}

void MyRect::spawn()
{
    //if mytime=0 stop spawn drums
    if(game->mytimer->mytime==0){
        game->stopSpawn();
    }

    //random 0,1
    srand(time(NULL));
    int random_number;
    random_number=(rand()%2);

    //creat an enemy(an item)
    if(random_number==0){
        RedDrum *reddrum= new RedDrum();
        scene()->addItem(reddrum);
    }
    else if(random_number==1){
        BlueDrum *bluedrum= new BlueDrum();
        scene()->addItem(bluedrum);
    }
}

