void CommandInput::TimHortons(std::istream & in, std::shared_ptr<Player> p) {
    game->printMessage("You are in the DC Tims Line :(\nDo you want to roll dice, pay $50 or use a Roll Up the Rim Cup?");
    std::string command;
    in >> command;
    if (command == "roll") {
      int first = p->roll();
      game->printMessage("Dice 1: " + std::to_string(first));
      int second = p->roll();
      game->printMessage("Dice 2: " + std::to_string(second));
      if (first == second) {
        game->printMessage("Your rolled doubles!\nYou are out of the line!");
        p->resetTimRound();
      } else {
        game->printMessage("Your didn't roll doubles...\nYou are still in the line ...");
        p->addTimRound();
      }
    } else if (command == "pay") {
      p->giveMoney(nullptr, 50);
      game->printMessage("You payed $50!\nYou are out of the line!");
      p->resetTimRound();
    } else if (command == "use") {
      game->useRimCup();
      game->printMessage("You used a Roll Up the Rim Cup!\nYou are out of the line!");
      p->resetTimRound();
    }
}
      
      
    
  
