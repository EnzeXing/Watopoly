#include "Player.h"
#include "Building.h"
#include "Property.h"
#include "NonProperty.h"
#include <stdexcept>

Player::Player(std::string name, std::string symbol, int position, std::shared_ptr<Dice> dice, 
               int TimCup, int money, int TimRound) : name{name}, symbol{symbol}, position{position}, money{money}, rimCup{TimCup}, TimRound{TimRound}, dice{dice} {
    properties["Arts1"] = 0;
    properties["Arts2"] = 0;
    properties["Eng"] = 0;
    properties["Health"] = 0;
    properties["Env"] = 0;
    properties["Sci1"] = 0;
    properties["Sci2"] = 0;
    properties["Math"] = 0;
    properties["Residence"] = 0;
    properties["Gym"] = 0;
}

std::string Player::getName() {
    return name;
}

std::string Player::getSymbol() {
    return symbol;
}

int Player::getMoney() {
    return money;
}

void Player::giveMoney(std::shared_ptr<Player> other, int amount) {
    if (money < amount) {
        throw WatopolyException("Not enough money!");
    }
    
    money -= amount;
    if (other != nullptr) other->addMoney(amount);
}

void Player::addMoney(int amount) {
    money += amount;
}

unsigned int Player::getProperties(std::string type) {
    return properties[type];
}

void Player::addBuilding(std::string type) {
    properties[type]++;
}

void Player::loseBuilding(std::string type) {
    properties[type]--;
}

bool Player::hasFullMonopoly(std::string type) {
    if (type == "Arts1") {
        return properties[type] == 2;
    } else if (type == "Arts2") {
        return properties[type] == 3;
    } else if (type == "Eng") {
        return properties[type] == 3;
    } else if (type == "Health") {
        return properties[type] == 3;
    } else if (type == "Env") {
        return properties[type] == 3;
    } else if (type == "Sci1") {
        return properties[type] == 3;
    } else if (type == "Sci2") {
        return properties[type] == 3;
    } else if (type == "Math") {
        return properties[type] == 2;
    } else if (type == "Residence") {
        return properties[type] == 4;
    } else {
        return properties[type] == 2;
    }
}

void Player::move(int p) {
    position = (position + p + 40) % 40;
}

int Player::getCup() {
    return rimCup;
}

void Player::addCup() {
    rimCup++;
}

void Player::removeCup() {
    if (rimCup == 0) {
        throw WatopolyException("Not enough Rim Cup!");
    }
    rimCup--;
}

int Player::getTimRound() {
    return TimRound;
}

void Player::stayInLine() {
    TimRound++;
}

void Player::leaveLine() {
    TimRound = 0;
}

int Player::roll() {
    return dice->roll();
}
