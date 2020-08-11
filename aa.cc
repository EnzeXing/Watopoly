void CommandInput::TimHortons(std::istream & in, std::shared_ptr<Player> p) {
  std::string command;
  in >> command;
  if (command == "roll") {
    int first = p->roll();
    int second = p->roll();
    if (first == second) {
      p
    
  
