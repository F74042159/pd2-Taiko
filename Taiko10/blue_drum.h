#ifndef BLUE_DRUM_H
#define BLUE_DRUM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "myrect.h"
#include "game.h"
#include <QTimer>


class BlueDrum : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    BlueDrum();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void move();
private:
    QMediaPlayer* pressSound;

};

#endif // BLUE_DRUM_H
