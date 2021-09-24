#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>


class Health: public QGraphicsTextItem{

public:
    //constructor
    Health(QGraphicsItem * parent =0);

    //member function
    void decrease();
    int getHealth();

private:
    //variable
    int health;

};

#endif // HEALTH_H
