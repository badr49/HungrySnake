#include "mainWindow.h"
#include <QApplication>
mainWindow *jeux;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    jeux = new mainWindow();
    jeux->show();
    jeux->displayMainMenu("HungrySnake","Play");
    return a.exec();
}
