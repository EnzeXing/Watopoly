#include "commandInput.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <fstream>

int main(int argc, std::string argv[]) {
    if (argc == 1) {
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
      return 0;
    } else if (argc == 3) {
      std::ifstream infile{argv[2]};
      CommandInput input{std::make_shared<Game>(infile)};
      input.readInput(std::cin);
      return 0;
    } else {
      //testing mode
      return 0;
    }
}
      

