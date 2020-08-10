#include "Game.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>

int main() {
    /*std::map<std::string, std::string> players;
    players["Andrew"] = "A";
    players["Ivan"] = "I";
    players["Fatday"] = "F";
    players["Klaus"] = "K";
    players["Lingwei"] = "L";
    players["Steven"] = "S";*/
    
    std::ifstream infile{"Game1.txt"};
    
    Game game = Game(infile);
    game.drawBoard();
    game.nextPlayer();
    game.movePlayer(5);
    game.drawBoard();
    game.nextPlayer();
    game.movePlayer(5);
    game.drawBoard();
    std::ofstream outfile{"Game1.txt"};
    game.saveGame(outfile);
}
