#include "Game.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>

int main() {
    std::map<std::string, char> players;
    players["Andrew"] = 'A';
    players["Ivan"] = 'I';
    players["Fatday"] = 'F';
    players["Klaus"] = 'K';
    players["Lingwei"] = 'L';
    players["Steven"] = 'S';
    
    Game game = Game(players);
    game.nextPlayer();
    game.movePlayer(5);
}
