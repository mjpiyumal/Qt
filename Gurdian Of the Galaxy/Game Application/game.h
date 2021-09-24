#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <player.h>
#include <score.h>
#include <health.h>
#include <QTimer>

//game class inherit from QWidget
class Game: public QGraphicsView{
    Q_OBJECT

public:

    //constructors
    Game(QWidget * parent = NULL);

    //public methods
    void displayGameOverWindow();
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void startGame();
    //void displayMainMenu();


    //public attributes
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    QTimer * timer;

public slots:

    void restartGame();
    //void startGame();

};


#endif // GAME_H
