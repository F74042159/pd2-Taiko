#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QTimer>
#include "score.h"
#include <QBrush>
#include <QImage>
#include "target.h"
#include "mytimer.h"
#include "button.h"
#include <QGraphicsTextItem>
#include <QObject>
#include <QFont>
#include <QMediaPlayer>

class Game: public QGraphicsView{
    Q_OBJECT
public:
    //constructor
    Game();

    // public member function
    void displayMainMenu();
    void gameover();
    void displayGameOverWindow();
    void stopSpawn();
    void stopCountdown();

    //public attributes
    QGraphicsScene *scene;
    MyRect *player;
    Score *score;
    Target *target;
    MyTimer *mytimer;
    QMediaPlayer* music;
public slots:
    void start();
    void restartGame();

private:
    void drawPanel(int x,int y,int width,int height,QColor color,double opacity);
    QTimer *timer;//for spawn drum periodically
    QTimer *countdown_timer;//for countdown periodically
};
#endif // GAME_H
