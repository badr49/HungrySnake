#ifndef SNAKEPART_H
#define SNAKEPART_H

#include <QGraphicsRectItem>
class SnakePart:public QGraphicsPixmapItem
{
private:
    SnakePart *forward;
    SnakePart *backward;
    QString direction;

public:
    SnakePart(QGraphicsItem *parent = 0);
//les getters et les setters
    SnakePart *getForward() ;
    void setForward(SnakePart *value);
    SnakePart *getBackward() ;
    void setBackward(SnakePart *value);
    QString getDirection() ;
    void setDirection( QString value);
    void move();
    void addBehind();
    QString part;
    void setImage();
    void CheckGameOver();

};

#endif
