#include <enemy.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <health.h>
#include <game.h>
#include "maindialog.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem * parent): QObject(),QGraphicsPixmapItem(parent){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //drew the rect
    //setRect(0,0,100,100);
    setPixmap(QPixmap(":/images/enemy.png"));

    //Connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move(){

    //move enemy down
    setPos(x(),y()+5);
    if(pos().y() > 600){

        if(game->health->getHealth()==0){

            game->displayGameOverWindow();
        }
        else{
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
        }

        // decrese the health
        // game->health->decrease();

       // scene()->removeItem(this);
       // delete this;
     //qDebug()<<"Bullet delete";

    }

}
