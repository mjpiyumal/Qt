#include <player.h>
#include <QKeyEvent>
#include <bullet.h>
#include <QGraphicsScene>
#include <QList>
#include <enemy.h>
#include <enemyb.h>
#include <game.h>
#include <QTimer>
#include <typeinfo>
#include <QMediaPlayer>
#include <maindialog.h>

extern Game *game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/shoot.wav"));

    setPixmap(QPixmap(":/images/player.png"));

        QTimer *timer= new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(collidesWithEnemy()));
        timer->start(50);
}


void Player::keyPressEvent(QKeyEvent *event)

{
    ///
    ///Control panel
    ///
    if(event->key() == Qt::Key_Left){//go the left side
        if(pos().x()>0)
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){//go the right side
        if(pos().x()+100<800)
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Up){//go up

        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down){//go down

        setPos(x(),y()+10);
    }
    else if(event->key() == Qt::Key_Space){//fire button
        //create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        //play bullet sound
        if(bulletsound->state()==QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state()==QMediaPlayer::StoppedState){
            bulletsound->play();

        }

    }

}


void Player::spawn()
{
    //create an enemy
    Enemy * enemy = new Enemy();//enemy_1
    scene()->addItem(enemy);  //enemy_1
    Enemyb * enemyb = new Enemyb();
    scene()->addItem(enemyb);

}

void Player::collidesWithEnemy()
{
    QList<QGraphicsItem *> colliding_items= collidingItems();

    for(int i=0,n=colliding_items.size();i<n;i++)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            game->health->decrease();

            //remove colliding items
            scene()->removeItem(colliding_items[i]);

            //clean heap memory
            delete colliding_items[i];
            return;
        }
    }

    QList<QGraphicsItem *> colliding_item= collidingItems();

    for(int a=0,n=colliding_item.size();a<n;a++)
    {
        if(typeid(*(colliding_item[a])) == typeid(Enemyb))
        {
            game->health->decrease();

            //remove colliding items
            scene()->removeItem(colliding_item[a]);


           //clean heap memory
            delete colliding_item[a];
            return;
        }
    }

}


