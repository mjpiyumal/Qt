 #ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

//bullet class inherit from QGraphicsPixmapItem
class Bullet: public QObject,public QGraphicsPixmapItem{

    Q_OBJECT

public:
    //constructor
    Bullet(QGraphicsItem * parent=0);


public slots:
    //member functions
    void move();


};

#endif // BULLET_H
