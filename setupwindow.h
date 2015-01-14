#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H

#include <QWidget>
#include <random>


namespace Ui {
class SetupWindow;
}

class SetupWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SetupWindow(QWidget *parent = 0);
    ~SetupWindow();
    int tmp_health;
    int tmp_stress;
    int tmp_melee;
    int tmp_ranged;
    int tmp_mech;
    int tmp_tech;
    QString tmp_name;


signals:
    void updatePlayer(QVector<int> newStats);
    void updatePlayerName(QString newName);

private:
    Ui::SetupWindow *ui;
    int dice_roll();
    std::default_random_engine generator;

private slots:
    void on_rollButton_clicked();
    void on_continueButton_clicked();
};

#endif // SETUPWINDOW_H
