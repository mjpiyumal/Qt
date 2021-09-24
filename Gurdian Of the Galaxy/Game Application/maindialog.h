#ifndef MAINDIALOG_H
#define MAINDIALOG_H
#include <game.h>
#include <QDialog>

namespace Ui {
class maindialog;
}

class maindialog : public QDialog
{
    Q_OBJECT

public:
    explicit maindialog(QWidget *parent = 0);
    void setGameObject(Game *g);
    ~maindialog();

private:
    Ui::maindialog *ui;

};

#endif // MAINDIALOG_H
