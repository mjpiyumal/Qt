#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include<QGraphicsRectItem>
#include<QGraphicsSceneMouseEvent>


//Button class inherit
class Button : public QObject, public QGraphicsRectItem{

    Q_OBJECT
  public:
    //constructors
      Button(QString name, QGraphicsItem *parent = 0);


      //public methods (events)
      void mousePressEvent(QGraphicsSceneMouseEvent *event);
      void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
      void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

  signals:
      //member function
      void clicked();

  private:
      QGraphicsTextItem *text;


};

#endif // BUTTON_H
