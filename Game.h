#ifndef _GAME_H_
#define _GAME_H_

#include "Player.h"
#include "Building.h"
#include "Property.h"
#include "NonProperty.h"
#include "Board.h"
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>

class Game {
  private:
    std::vector<std::shared_ptr<Building>> buildings;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Player>>::it currentPlayer;
    std::shared_ptr<Board> board;
    std::shared_ptr<Dice> dice;
  public:
    Game(std::map<std::string, char> player_names);
    Game(std::ifstream file);
    void nextPlayer();
    void movePlayer(int steps);
    std::shared_ptr<Player> findPlayer(std::string s);
    void bankrupt(std::shared_ptr<Player>);
    void saveGame(std::ofstream file);
};

#endif
