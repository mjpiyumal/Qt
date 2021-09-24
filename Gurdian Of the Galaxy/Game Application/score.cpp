#include <score.h>
#include <QFont>


Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent){

    //Initialize score to 0
    score = 0;

    //draw the text
    setPlainText(QString("Score: ")+ QString::number (score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Square Sans Serif 7",16));



}

void Score::increase(){

score++;
setPlainText(QString("Score: ")+ QString::number (score));

}

int Score::getScore(){
return score;

}
