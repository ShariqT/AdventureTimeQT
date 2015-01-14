#ifndef PLAYER_H
#define PLAYER_H
#include <QString>

class Player
{
public:
    Player();
    ~Player();
    int health();
    int stress();
    int mech();
    int tech();
    int melee();
    int ranged();
    QString playerName();
    void setHealth(int newHealth);
    void setStress(int newStress);
    void setMech( int newMech);
    void setMelee( int newMelee );
    void setRanged( int newRanged );
    void setPlayerName( QString newName );
    void setTech(int newTech);
    void loadViaSaveFile();
    bool save();

private:
    int _health;
    int _stress;
    int _mech;
    int _tech;
    int _melee;
    int _ranged;
    QString _playerName;

};

#endif // PLAYER_H
