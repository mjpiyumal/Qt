#include <maindialog.h>
#include <ui_maindialog.h>
#include <game.h>
#include <QApplication>

extern Game *game;

maindialog::maindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maindialog)
{
    ui->setupUi(this);
}

maindialog::~maindialog()
{
    delete ui;
}



