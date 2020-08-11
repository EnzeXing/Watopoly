void CommandInput::TimHortons(std::istream & in) {
    game->printMessage("You are in the DC Tims Line :(\nDo you want to roll dice, pay $50 or use a Roll Up the Rim Cup?");
    std::string command;
    in >> command;
    if (command == "roll") {
      if (game->rollDouble()) {
        game->printMessage("Your rolled doubles!\nYou are out of the line!");
        game->leaveLine();
      } else {
        game->printMessage("Your didn't roll doubles...\nYou are still in the line ...");
        game->stayInLine();
      }
    } else if (command == "pay") {
      game->buyCoffee()
      game->printMessage("You payed $50!\nYou are out of the line!");
    } else if (command == "use") {
      game->useRimCup();
      game->printMessage("You used a Roll Up the Rim Cup!\nYou are out of the line!");
    }
}
      
      
    
  
