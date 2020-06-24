    #include "movesnake.h"
#include "snakepart.h"
#include <QTimer>
#include <food.h>
#include <QDebug>
#include <QFont>

extern mainWindow *jeux;

MoveSnake::MoveSnake(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    snakeHead = new SnakePart(this);
    snakeHead->setForward(NULL);
    snakeHead->setBackward(NULL);
    snakeHead->setPos(200,200);
    snakeHead->setDirection("RIGHT");
    snakeHead->part = "HEAD";
    snakeHead->setImage();
    snakeTail = snakeHead;

    t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(move()));

    direction = "RIGHT";

    addPart();
    addPart();
    addPart();

    espace = new QGraphicsTextItem(this);
    espace->setVisible(true);
    espace->setPlainText("Appuyer sur espace pour commencer");
    espace->setPos(450,150);
    espace->setFont(QFont("",14));

}

void MoveSnake::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Down && snakeHead->getDirection() != "UP") {
        direction = "DOWN";
    }
    else if(event->key() == Qt::Key_Up && snakeHead->getDirection() != "DOWN") {
        direction = "UP";
    }
    else if(event->key() == Qt::Key_Right && snakeHead->getDirection() != "LEFT") {
        direction = "RIGHT";
    }
    else if(event->key() == Qt::Key_Left && snakeHead->getDirection() != "RIGHT") {
        direction = "LEFT";
    }
    else if(event->key() == Qt::Key_Space){
        if(t->isActive()){   
            t->stop();
            espace->setVisible(true);
        }
        else{
            t->start(90);
            espace->setVisible(false);
        }

    }
}


void MoveSnake::move() {
    snakeHead->setDirection(direction);
    moveSnake();

}

void MoveSnake::makeFood()
{
    f1 = new food(this);
    f1->setX(qrand() % (1200/40)* 40);
    f1->setY(qrand() % (720/40) * 40) ;
    fx = f1->x();
    fy = f1->y();

}

void MoveSnake::addPart(){
    SnakePart *part = new SnakePart(this);
    SnakePart *temp = snakeHead;
    while(temp->getBackward() != NULL) {
        temp = temp->getBackward();
    }
    temp->setBackward( part);
    part->setForward( temp);
    part->setBackward(NULL);
    part->addBehind();
    part->setDirection(temp->getDirection());
    snakeTail = part;
    part->part = "TAIL";
    if(temp != snakeHead){
        temp->part = "PART";
        part->setImage();
        temp->setImage();
    }
}

void MoveSnake::moveSnake()
{
   SnakePart *snakePart = snakeTail;

   while(snakePart!=NULL) {
       snakePart->move();
       snakePart = snakePart->getForward();
   }
// ajout d'une queue après passage sur un fruit
   if ( snakeHead->x()==fx && snakeHead->y()==fy ){
       jeux->score->setScore(jeux->score->getScore()+10);
       this->addPart();
       jeux->Menu->removeItem(f1);
       delete f1;
       makeFood();
   }
}

