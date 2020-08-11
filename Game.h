#ifndef _GAME_H_
#define _GAME_H_

#include "Player.h"
#include "Building.h"
#include "Property.h"
#include "NonProperty.h"
#include "Board.h"
#include "Dice.h"
#include "Exception.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>

class Game {
  private:
    std::vector<std::shared_ptr<Building>> buildings;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Player>>::iterator currentPlayer;
    std::shared_ptr<Board> board;
    std::shared_ptr<Dice> dice;
    std::shared_ptr<RimCup> rimcup;
  public:
    Game(std::map<std::string, std::string> player_names);
    Game(std::ifstream & file);
    std::shared_ptr<Board> getBoard();
    std::string currentPlayerName();
    void nextPlayer();
    void movePlayer(int steps);
    std::shared_ptr<Player> findPlayer(std::string s);
    std::shared_ptr<Building> findBuilding(std::string name);
    void purchase(std::string buildingName);
    void tradeBuilding(std::string buildingName, std::string receiver);
    void tradeBuilding(std::string giver, std::string receiver, std::string buildingName);
    void trade(std::string receiver, int giveAmount, std::string buildingName);
    void trade(std::string receiver, std::string buildingName, int receiveAmount);
    void trade(std::string receiver, std::string giveBuildingName, std::string receiveBuildingName);
    void mortgage(std::string buildingName);
    void unmortgage(std::string buildingName);
    void bankrupt(std::shared_ptr<Player>);
    void saveGame(std::ofstream & file);
    void drawBoard();
    void roll();
    bool rollDouble();
    void useRimCup();
    void buyCoffee();
    void stayInLine();
    void leaveLine();
    void printMessage(std::string message);
};

#endif
