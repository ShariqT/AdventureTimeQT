#include "player.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

Player::Player()
{
    //on inital construction, we don't add anything to the attributes
    //
}

Player::~Player()
{

}

//setters
void Player::setHealth( int newHealth ){
    _health = newHealth;
}

void Player::setMech( int newMech ){
    _mech = newMech;
}

void Player::setMelee( int newMelee ){
    _melee = newMelee;
}

void Player::setRanged( int newRanged ){
    _ranged = newRanged;
}

void Player::setStress( int newStress ){
    _stress = newStress;
}

void Player::setTech( int newTech ){
    _tech = newTech;
}

void Player::setPlayerName( QString newPlayerName ){
    _playerName = newPlayerName;
}

//getters
int Player::tech(){
    return _tech;
}

QString Player::playerName(){
    return _playerName;
}

int Player::health(){
    return _health;
}

int Player::mech( ){
    return _mech;
}

int Player::melee(){
    return _melee;
}

int Player::ranged(){
    return _ranged;
}

int Player::stress(){
    return _stress;
}

void Player::loadViaSaveFile(){
    //we will read the character json file with this method
}


bool Player::save(){
    QFile saveFile("player.json");
    QJsonObject playerJsonObj;
    playerJsonObj["health"] = _health;
    playerJsonObj["stress"] = _stress;
    playerJsonObj["melee"] = _melee;
    playerJsonObj["ranged"] = _ranged;
    playerJsonObj["mech"] = _mech;
    playerJsonObj["tech"] = _tech;
    playerJsonObj["name"] = _playerName;

    if(!saveFile.open(QIODevice::WriteOnly)){
        return false;
    }

    QJsonDocument playerJSON(playerJsonObj);
    saveFile.write(playerJSON.toJson());
    return true;
}

