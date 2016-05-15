#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <stdlib.h>
#include <ctime> //for time()

#include <QGraphicsScene>
#include <QKeyEvent>



class MyRect:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    MyRect();
public slots:
    void spawn();

};



#endif // MYRECT_H
