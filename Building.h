#include <string>
#include <memory>
#include <algorithm>


class Player;

class Building {
  private:
    std::string name;
    int position;
  public:
    std::string getName();
    int getPosition();
    virtual void accept(Player & p) = 0;
};
