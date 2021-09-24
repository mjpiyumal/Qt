#include <game.h>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <enemy.h>
#include <enemyb.h>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <button.h>
#include <QBrush>
#include <QImage>


Game:: Game(QWidget *parent){

    startGame();
}

void Game::displayGameOverWindow(){

            //disable all scene items
            for(size_t i=0,n=scene->items().size();i<n;i++){

                scene->items()[i]->setEnabled(false);
                QObject::disconnect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
            }


            drawPanel(0,0,1024,700,Qt::black,0.65);

            //draw panel
            drawPanel(310,100,400,400,Qt::lightGray,0.75);

            //set title
            QGraphicsTextItem *title= new QGraphicsTextItem("Gurdian of \n the Galaxy");
            QFont titleFont("Square Sans Serif 7",30);
            title->setFont(titleFont);
            int xPosi=360;
            int yPosi=150;
            title->setPos(xPosi,yPosi);
            scene->addItem(title);


            /// create game over window buttons ///

            //play again button
            Button *buttonPlayAgain= new Button(QString("Play Again"));
            int xpPos=410;
            int ypPos=250;
            buttonPlayAgain->setPos(xpPos,ypPos);
            connect(buttonPlayAgain,SIGNAL(clicked()),this,SLOT(restartGame()));
            scene->addItem(buttonPlayAgain);

            // quit button
            Button *buttonQuit= new Button(QString("Quit Game"));
            int qxPos=410;
            int qyPos=350;
            buttonQuit->setPos(qxPos,qyPos);
            connect(buttonQuit,SIGNAL(clicked()),this,SLOT(close()));
            scene->addItem(buttonQuit);

}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){

       QGraphicsRectItem *panel= new QGraphicsRectItem(x,y,width,height);
       QBrush brush;
       brush.setStyle(Qt::SolidPattern);
       brush.setColor(color);
       panel->setBrush(brush);
       panel->setOpacity(opacity);
       scene->addItem(panel);

}

void Game::startGame(){
    //clear the screen
      //scene->clear();


    // create the scene
        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,1024,700);
        setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
        setScene(scene);

        //off Vertical and horizontal scroll bars
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(1024,700);

        // create the player
        player = new Player();
        //player->setRect(0,0,100,100);
        player->setPos(460,500);

        // make the player focusable
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();

        // add the player to the scene
        scene->addItem(player);

        // create the score/health
        score = new Score();
        scene->addItem(score);
        health = new Health();
        health->setPos(health->x(),health->y()+25);
        scene->addItem(health);

        // spawn enemies
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
        timer->start(2000);

        //second enemy
           QTimer * timerx = new QTimer();
            QObject::connect(timerx,SIGNAL(timeout()),player,SLOT(spawn()));
            timerx->start(10000);

        //play background music
           //Repeat audio clip
          QMediaPlaylist * repeat=  new QMediaPlaylist();
          repeat-> addMedia(QUrl("qrc:/sound/Spacecraft.mp3"));
          repeat->setPlaybackMode(QMediaPlaylist::Loop);


         QMediaPlayer * media = new QMediaPlayer();
         media->setPlaylist(repeat);
         media->play();
}

/*void Game:: displayMainMenu(){

        //create the title
    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("Gurdian of the Galaxy"));
    QFont titleFont("Square Sans Serif 7",30);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos   );
    scene->addItem(titleText);

    //create the play button
    Button *playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(restartGame()));
    scene->addItem(playButton);

    //create the quit button
     Button *quitButton = new Button(QString("Quit"));
     int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
     int qyPos = 350;
     quitButton->setPos(qxPos,qyPos);
     connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
     scene->addItem(quitButton);


}*/

void Game::restartGame(){
        score=0;
        scene->clear();
        startGame();

}


