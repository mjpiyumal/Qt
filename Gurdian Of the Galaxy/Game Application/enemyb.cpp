#include <enemyb.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <health.h>
#include <stdlib.h> //rand()-> realy large int
#include <maindialog.h>

extern Game * game;

Enemyb::Enemyb(QGraphicsItem * parent): QObject(),QGraphicsPixmapItem(parent){

    int random_number = rand() % 700;
    // set random position
    setPos(random_number,0);

    //drew the rect
    //setRect(0,0,50,50);
    setPixmap(QPixmap(":/images/enemyb.png"));

    //Connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemyb::move(){

    //move enemy down
    setPos(x(),y()+5);
    if(pos().y()>600){
            if(game->health->getHealth()==0)
            {
                game->displayGameOverWindow();
            }
            else

            {
                game->health->decrease();
                scene()->removeItem(this);
                delete this;
     //qDebug()<<"Bullet delete";

        }

    }
}

