#include "startwindow.h"
#include "ui_startwindow.h"
#include <QPixmap>

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    QImage image(":/assets/DeathRace_Mustang.png");
    ui->startImage->setScaledContents(true);
    ui->startImage->setPixmap(QPixmap::fromImage(image));
    ui->startImage->resize(122.5 * ui->startImage->pixmap()->size());
    connect(ui->startButton,SIGNAL(clicked()),this, SLOT(goToSetup()));
    connect(this,SIGNAL(transitionTo(QString)),parentWidget(),SLOT(changeCentralWidget(QString)));

}

StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::goToSetup(){
    //stuff
    emit transitionTo("setupwindow");
}



