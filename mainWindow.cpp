#include "mainWindow.h"
MoveSnake *snake;

mainWindow::mainWindow(QWidget *parent):QGraphicsView(parent)
{

    setFixedSize(1200,720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //affichage de l'application
    Menu = new QGraphicsScene(this);
    Menu->setSceneRect(0,0,1200,720);
    QGraphicsPixmapItem *bg = new QGraphicsPixmapItem();
    bg->setPixmap(QPixmap(":/images/bg.jpg").scaled(1200,720));
    Menu->addItem(bg);

    setScene(Menu);
    score = new Score();
    Menu->addItem(score);
    snake = NULL;

}

void mainWindow::displayMainMenu(QString title,QString play)
{
  //ajouter un titre
    titleText = new QGraphicsTextItem(title);
    QFont titleFont("arial" , 50);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 150;
    titleText->setPos(xPos,yPos);
    Menu->addItem(titleText);

   //créer un Button
    Button * playButton = new Button(play,titleText);
    int pxPos = 160 ;
    int pyPos = 160;
    playButton->setPos(pxPos,pyPos);

    connect(playButton,SIGNAL(clicked()) , this , SLOT(start()));
}
void mainWindow::start(){
    snake = new MoveSnake();
    snake->setFlag(QGraphicsItem::ItemIsFocusable);
    snake->setFocus();
    snake->makeFood();
    score->setVisible(true);
    score->setScore(0);
    Menu->addItem(snake);

    Menu->removeItem(titleText);
    delete titleText;

}

void mainWindow::gameOver(){
    titleText = new QGraphicsTextItem("Your Score is : "+ QString::number((score->getScore())));
    QFont titleFont("arial" , 30);
    titleText->setFont( titleFont);
    int xPos = width()/2 - titleText->boundingRect().width()/2;
    int yPos = 30;
    titleText->setPos(xPos,yPos);

    Menu->addItem(titleText);
    displayMainMenu("Game Over!","Play Again");
    Menu->removeItem(snake);
    Menu->removeItem(score);

}

