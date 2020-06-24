#include "snakepart.h"
#include <QBrush>
#include <QDebug>
#include "mainWindow.h"
#include "food.h"
#include <typeinfo>

extern mainWindow *jeux;

SnakePart::SnakePart(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    setZValue(1);
}

SnakePart *SnakePart::getForward(){
    return forward;
}

void SnakePart::setForward(SnakePart *value){
    forward = value;
}

SnakePart *SnakePart::getBackward(){
    return backward;
}

void SnakePart::setBackward(SnakePart *value){
    backward = value;
}

QString SnakePart::getDirection(){
    return direction;
}

void SnakePart::setDirection( QString value){
    direction = value;
}


void SnakePart::move()
{
    static int first;

    if (direction == "DOWN")
        this->setY(this->y()+40);
    else if(direction == "UP")
        this->setY(this->y()-40);
    else if(direction == "LEFT")
        this->setX(this->x()-40);
    else if(direction == "RIGHT")
        this->setX(this->x()+40);
    if(this->getForward()!= NULL)
        direction = this->getForward()->direction;
    if(first){
    if(this->y() >= 720 ){
        jeux->gameOver();
    }
    else if(this->y()<0){
        jeux->gameOver();
    }
    else if(this->x() < 0){
        jeux->gameOver();
    }
    else if(this->x() >= 1200){
        jeux->gameOver();
    }

    }
    first++;
    setImage();

}

void SnakePart::addBehind()
{
    int x=0;
    int y=0;

    if(this->getForward()->getDirection() == "UP"){
        x = this->getForward()->x();
        y = this->getForward()->y() + 40;
    }
    else if(this->getForward()->getDirection() == "DOWN"){
        x = this->getForward()->x();
        y = this->getForward()->y() - 40;
    }
    else if(this->getForward()->getDirection() == "RIGHT"){
        y = this->getForward()->y();
        x = this->getForward()->x() - 40;
    }
    else if(this->getForward()->getDirection() == "LEFT"){
        y = this->getForward()->y();
        x = this->getForward()->x() + 40;
    }
    setPos(x,y);
}

void SnakePart::setImage()
{
    if(part == "HEAD"){
        setPixmap(QPixmap(":/images/head.png").scaled(40,40,Qt::KeepAspectRatio));
        setZValue(2);
    }
    else{
            setPixmap(QPixmap(":/images/tail.png").scaled(40,40));
    }
}

void SnakePart::CheckGameOver(){
    QList<QGraphicsItem*> collision = collidingItems();
    int n = collision.size();
    for (int i = 0; i < n; ++i){
        if(collision[i]) {
            if(typeid(collision[i])== typeid(SnakePart))
                jeux->gameOver();
                return;
       }
    }
}



