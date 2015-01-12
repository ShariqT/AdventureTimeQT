#include "setupwindow.h"
#include "ui_setupwindow.h"
#include "errordialog.h"
#include <QDebug>
#include <chrono>
#include <QDialog>

SetupWindow::SetupWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SetupWindow)
{
    ui->setupUi(this);
}

SetupWindow::~SetupWindow()
{
    delete ui;
}

void SetupWindow::on_rollButton_clicked(){
    //setup random numbers for the player's new character
   tmp_health = dice_roll();
   tmp_stress = dice_roll();
   tmp_melee = dice_roll();
   tmp_ranged = dice_roll();
   tmp_mech = dice_roll();
   tmp_tech = dice_roll();

   //at the very least, a character has to have 10 health points
   if(tmp_health < 10){
       tmp_health = 10;
   }



   ui->healthValue->setText( QString( std::to_string(tmp_health).c_str() ));
   ui->stressValue->setText( QString( std::to_string(tmp_stress).c_str() ));
   ui->meleeValue->setText( QString( std::to_string(tmp_melee).c_str() ));
   ui->rangedValue->setText( QString( std::to_string(tmp_ranged).c_str() ));
   ui->mechValue->setText( QString( std::to_string(tmp_mech).c_str() ));
   ui->techValue->setText( QString(std::to_string(tmp_tech).c_str() ));

    ui->rollButton->setVisible(false);
}


void SetupWindow::on_continueButton_clicked(){
    //check for the playerName
    qDebug() << ui->characterName->text();
    if(ui->characterName->text() == ""){
        ErrorDialog dialog(this);
        dialog.setErrorMessage(QString("There was no player name given!"));
        dialog.exec();
    }

    QVector<int> newStats;
    newStats.append(tmp_health);
    newStats.append(tmp_stress);
    newStats.append(tmp_melee);
    newStats.append(tmp_ranged);
    newStats.append(tmp_mech);
    newStats.append(tmp_tech);

    emit updatePlayer(newStats);


}

int SetupWindow::dice_roll(){
    std::uniform_int_distribution<int> distribution(1,20);

    int number = distribution(generator);
    return number;
}

