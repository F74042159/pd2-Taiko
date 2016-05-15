#ifndef RED_DRUM_H
#define RED_DRUM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include "myrect.h"
#include "game.h"
#include <QKeyEvent>
#include <QTimer>

class RedDrum : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    RedDrum();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void move();
private:
    QMediaPlayer* pressSound;
};

#endif // RED_DRUM_H
