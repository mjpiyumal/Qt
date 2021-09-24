#ifndef ENEMYB_H
#define ENEMYB_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>



class Enemyb: public QObject,public QGraphicsPixmapItem{

   Q_OBJECT

public:

    //constructors
   Enemyb(QGraphicsItem *parent = 0);

public slots:
   //member function
   void move();


};

#endif
