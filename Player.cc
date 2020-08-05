#include "Player.h"
#include <stdexcept>

std::string Player::getName() {
    return name;
}

char Player::getSymbol() {
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
    position = p;
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
