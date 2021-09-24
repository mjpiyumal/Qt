#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

//inherit from QGraphicsPixmapItem
class Enemy: public QObject,public QGraphicsPixmapItem{

   Q_OBJECT

public:

    //constructors
   Enemy(QGraphicsItem *parent = 0);

public slots:
   //function
   void move();


};

#endif // ENEMY_H



