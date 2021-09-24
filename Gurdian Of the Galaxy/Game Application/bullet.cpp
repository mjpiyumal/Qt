#include <bullet.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <enemy.h>
#include <enemyb.h>
#include <typeinfo>
#include <game.h>
#include <maindialog.h>

extern Game * game; //external global object

Bullet::Bullet(QGraphicsItem * parent): QObject(),QGraphicsPixmapItem(parent){

    //drew the rect
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/images/bullets.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Bullet::move(){
    //bullet collides with the enemy and destroy

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n= colliding_items.size();i<n;i++){//++1
        if(typeid(*(colliding_items[i]))== typeid(Enemy)){
            //Increse the score
            game->score->increase();


            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //clean heap memory
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //Destroy Enemyb
    QList<QGraphicsItem *> colliding_item = collidingItems();
    for(int i=0, n= colliding_item.size();i<n;i++){
        if(typeid(*(colliding_item[i]))== typeid(Enemyb)){
              game->score->increase();

              scene()->removeItem(colliding_item[i]);
              scene()->removeItem(this);
              //clean heap memory
              delete colliding_item[i];
              delete this;
              return;
        }

    }


    //move bullet up
    setPos(x(),y()-10);
    if(pos().y()+pixmap().height() < 0){

        scene()->removeItem(this);
        delete this;
     //qDebug()<<"Bullet delete";

    }

}
