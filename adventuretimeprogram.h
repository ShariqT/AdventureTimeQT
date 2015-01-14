#ifndef ADVENTURETIMEPROGRAM_H
#define ADVENTURETIMEPROGRAM_H

#include <QMainWindow>
#include "player.h"
namespace Ui {
class MainWindow;
}

//add forward declarations for each of the screens in the app
class StartWindow;
class SetupWindow;


class AdventureTimeProgram : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdventureTimeProgram(QWidget *parent = 0);
    ~AdventureTimeProgram();
    Player *player;

private:
    Ui::MainWindow *ui;
   //the screen attribute will hold a pointer to different screen Widgets
    QWidget *screen;


private slots:
    void changeCentralWidget(QString windowToTransition);
    void updatePlayerStats(QVector<int> newStats);
    void updatePlayerName(QString newName);
};

#endif // ADVENTURETIMEPROGRAM_H
