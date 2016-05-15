#ifndef MYTIMER_H
#define MYTIMER_H

#include <QtCore>
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>


class MyTimer :public QGraphicsTextItem{
    Q_OBJECT//no #include<QObject> and :public QObject(I don't know why!!!)
public:
    MyTimer();
    int mytime;
public slots:
    void decrease();
};
#endif // MYTIMER_H
