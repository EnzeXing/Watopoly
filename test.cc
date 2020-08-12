#include "CommandInput.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>

int main() {
    std::map<std::string, std::string> players;
    players["Andrew"] = "A";
    players["Ivan"] = "I";
    players["Fatday"] = "F";
    players["Klaus"] = "K";
    players["Lingwei"] = "L";
    players["Steven"] = "S"; 
    
    // std::ifstream infile{"Game1.txt"};
    
    CommandInput input{std::make_shared<Game>(players)};
    input.readInput(std::cin);
    game.saveGame(outfile);
}
