#ifndef main_Window_H
#define main_Window_H


#include <QGraphicsView>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "movesnake.h"
#include "score.h"
#include "button.h"

class mainWindow:public QGraphicsView
{
    Q_OBJECT
public:
    mainWindow(QWidget *parent = 0);
    Score *score;
    QGraphicsScene *Menu ;
    void displayMainMenu(QString title, QString play);
    QGraphicsTextItem *titleText;

public slots:
    void start();
    void gameOver();
};

#endif

