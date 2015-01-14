#include "adventuretimeprogram.h"
#include "startwindow.h"
#include "setupwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QVector>

AdventureTimeProgram::AdventureTimeProgram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
  player(new Player)
{

    ui->setupUi(this);
    screen = new StartWindow(this);
    setCentralWidget(screen);
}

AdventureTimeProgram::~AdventureTimeProgram()
{
    delete ui;
}


void AdventureTimeProgram::changeCentralWidget(QString windowName){
    delete screen;
    if(windowName == "startwindow"){
        screen = new StartWindow(this);
        setCentralWidget(screen);

    }

    if(windowName == "setupwindow"){
        screen = new SetupWindow(this);
        setCentralWidget(screen);
        qDebug() << windowName;
        connect(centralWidget(), SIGNAL(updatePlayer(QVector<int>)),this, SLOT(updatePlayerStats(QVector<int>)));
        connect(centralWidget(), SIGNAL(updatePlayerName(QString)), this, SLOT(updatePlayerName(QString)));
    }

}

void AdventureTimeProgram::updatePlayerStats(QVector<int> stats){
    /*the stats are put in a particular order
      0 - health
      1 - stress
      2 - melee
      3 - ranged
      4-  mech
      5- tech
     */

    player->setHealth(stats.at(0));
    player->setStress( stats.at(1));
    player->setMelee(stats.at(2));
    player->setRanged(stats.at(3));
    player->setMech(stats.at(4));
    player->setTech(stats.at(5));
    player->save();
}

void AdventureTimeProgram::updatePlayerName(QString newName){
    player->setPlayerName(newName);
    qDebug() << "The new player name is " << player->playerName();
    if(player->save()){
     qDebug() << "file was saved!";
    }else{
        qDebug() << "file was not saved!";
    }
}
