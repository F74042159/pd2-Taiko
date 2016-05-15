#ifndef TIMER_H
#define TIMER_H

#include <QtCore>
#include <QGraphicsTextItem>
#include <QFont>
#include <QObject>


class Timer : public QGraphicsTextItem,public QObject
{
    Q_OBJECT
public:
    Timer(QGraphicsItem*parent=0);
    void decrease();
public slots:
    void countdown();
private:
    int time;
};

#endif // TIMER_H
