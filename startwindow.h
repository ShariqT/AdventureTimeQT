#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

signals:
    void transitionTo(QString newWindowName);


public slots:
    void goToSetup();

private:
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
