#include <health.h>
#include <QFont>
#include <QMessageBox>
#include <QDebug>
#include <game.h>
#include <maindialog.h>

extern Game *game;

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent){

    //Initialize health to 6
    health = 6;

    //draw the text
    setPlainText(QString("Life: ")+ QString::number (health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Square Sans Serif 7",16));

    setPos(0,20);

}

void Health::decrease(){

    if(health<=0){
        game->displayGameOverWindow();
        return;
    }
    else{

health--;
setPlainText(QString("Life: ")+ QString::number (health));
    }

}

int Health::getHealth(){
return health;

}
