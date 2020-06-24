#ifndef MOVESNAKE_H
#define MOVESNAKE_H

#include <QKeyEvent>
#include <QGraphicsItem>
#include "snakepart.h"
#include "mainWindow.h"
#include "food.h"

class MoveSnake:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    SnakePart *snakeHead;
    SnakePart *snakeTail;
    QString direction;
    QTimer *t;
//    QTimer *foodTimer;
    QGraphicsTextItem *espace;

public:
    MoveSnake(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void addPart();
    void moveSnake();
    int fx;
    int fy;
    food *f1;

public slots:
    void move();
    void makeFood();
};

#endif

