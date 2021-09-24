#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>


class Score: public QGraphicsTextItem{

public:
    //constructor
    Score(QGraphicsItem * parent =0);

    //member function
    void increase();
    int getScore();


private:

    //variable
    int score;

};
#endif // SCORE_H
