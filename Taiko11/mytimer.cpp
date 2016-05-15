#include "mytimer.h"
#include "game.h" //why can't I put this un mytimer.h


extern Game *game;//there is an external global object called game

MyTimer::MyTimer()
{
    mytime=30;

    //draw the text
    setPlainText(QString("Time: ")+QString::number(mytime));//Time:30
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

void MyTimer::decrease(){
    //end the game,write in here,not in game.cpp. Because game.cpp 只執行一次 這裡會重複被呼叫
    if(mytime==0){
        game->stopCountdown();
        game->gameover();
        return;
    }
    mytime--;

    setPlainText(QString("Time: ")+QString::number(mytime));//score:29...

}
