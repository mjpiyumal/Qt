#include <button.h>
#include<QGraphicsTextItem>
#include<QBrush>
#include<QDebug>

Button:: Button(QString name, QGraphicsItem *parent):QGraphicsRectItem(parent){

    //draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

    //text
    text= new QGraphicsTextItem(name,this);
    int xPos=rect().width()/2-text->boundingRect().width()/2;
    int yPos=rect().height()/2-text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

      //allow responding to hover event
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //change color to darkblue
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkBlue);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //change color to red
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
