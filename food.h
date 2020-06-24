#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsPixmapItem>
class food:public QGraphicsPixmapItem
{
public:
    food(QGraphicsItem *parent = 0);
    int score;

};

#endif
