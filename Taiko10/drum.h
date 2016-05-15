#ifndef DRUM_H
#define DRUM_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include <typeinfo>
#include "game.h"

class Drum : public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    Drum(QGraphicsItem*parent = 0);
public slots:
    void move();
};

#endif // DRUM_H
