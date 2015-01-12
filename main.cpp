#include "adventuretimeprogram.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdventureTimeProgram w;
    w.show();

    return a.exec();
}
