#include "commandInput.h"
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <fstream>

void usage() {
    std::cerr << "Too many arguments!" << std::endl;
    std::cerr << "Command Line Options:" << std::endl;
    std::cerr << "A: -load file" << std::endl;
    std::cerr << "B: -testing" << std::endl;
} // usage


int main(int argc, std::string argv[]) {
    if (argc >= 4) {
      usage();
      return 1;
    } else if ((argc == 1) || (argv[0] == "./Watopoly")) {
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
    } else if (argc == 2) {
      //testing mode
      return 0;
    } else if (argv[1] == "-load") {
      std::ifstream infile{argv[2]};
      CommandInput input{std::make_shared<Game>(infile)};
      input.readInput(std::cin);
      //testing mode
      return 0;
    } else {
      std::ifstream infile{argv[3]};
      CommandInput input{std::make_shared<Game>(infile)};
      input.readInput(std::cin);
      //testing mode
      return 0;
    }
}
   
      
        
      
        
        

      

