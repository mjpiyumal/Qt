#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>


//player class inherit from  QGraphicsPixmapItem
class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    //constructors
    Player(QGraphicsItem * parent=0);

    //public methods (events)
    void keyPressEvent(QKeyEvent * event);


public slots:

    //member functions
    void spawn();
    void collidesWithEnemy();


private:
    QMediaPlayer * bulletsound;


};

#endif // PLAYER_H
