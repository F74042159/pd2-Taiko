#include "score.h"


Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    score = 0;

    //draw the text
    setPlainText(QString("Score: ")+QString::number(score));//Score:0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;

    setPlainText(QString("Score: ")+QString::number(score));//score:1...
}

int Score::getScore()
{
    return score;
}
