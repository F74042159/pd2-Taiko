#include "game.h"

Game::Game()
{
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/pics/picture/start")));
    setScene(scene);
}

void Game::displayMainMenu()
{
    //create the start button
    Button* startButton = new Button(QString("Start"));
    startButton->setPos(100,450);
    connect(startButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(startButton);

    //create the exit button
    Button* exitButton = new Button(QString("Exit"));
    exitButton->setPos(500,450);
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(exitButton);

}

void Game::start(){

    //clear the screen
    scene->clear();
    setBackgroundBrush(QBrush(QImage(":/pics/picture/background")));

    // create an item to put into the scene
    player = new MyRect();
    // add the item(player) to the scene
    scene->addItem(player);

    //create the score
    score = new Score();
    score->setPos(score->x()+600,score->y());
    //initialize
    score->score=0;
    //add score to the scene
    scene->addItem(score);


    //spawn enemy
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1000);

    //create the target
    target = new Target();
    scene->addItem(target);

    //create the timer
    mytimer = new MyTimer();
    mytimer->setPos(mytimer->x()+100,mytimer->y());
    //initialize
    mytimer->mytime=30;
    //add timer to the scene
    scene->addItem(mytimer);

    //countdown
    countdown_timer = new QTimer();
    QObject::connect(countdown_timer,SIGNAL(timeout()),mytimer,SLOT(decrease()));
    countdown_timer->start(1000);

    //play background music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/music/bg.mp3"));
    music->play();
}
void Game::stopSpawn()
{
    timer->stop();
    timer->blockSignals(true);
    timer->deleteLater();
}

void Game::stopCountdown()
{
    countdown_timer->stop();
    countdown_timer->blockSignals(true);
    countdown_timer->deleteLater();
}
void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    //draw a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::gameover()
{
    displayGameOverWindow();
}

void Game::displayGameOverWindow()
{
    //stop music
    music->stop();

    //disable all scene items (therefore can not eliminate remainding drums when press keys)when GameOverWindow pop up
    for(size_t i=0,n=scene->items().size();i<n;i++){
        scene->items()[i]->setEnabled(false);
    }
    //pop up semi transparent panel
    drawPanel(0,0,800,600,Qt::black,0.8);

    //draw panel
    drawPanel(200,100,400,400,Qt::lightGray,0.9);

    //create playAgain button
    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(300,275);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    //create exit button
    Button* exit = new Button(QString("Exit"));
    exit->setPos(300,350);
    scene->addItem(exit);
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));

    //create the text announcing final score
    QGraphicsTextItem* overScore = new QGraphicsTextItem(QString("Score: ")+QString::number(score->score));
    overScore->setFont(QFont("comic sans",30));
    overScore->setPos(300,200);
    scene->addItem(overScore);
}
void Game::restartGame()
{
    //clear some stuff then call start()
    //scene->clear();

    start();
}


