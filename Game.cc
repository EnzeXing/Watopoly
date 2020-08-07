#include "Game.h"
#include "Property.h"
#include "NonProperty.h"
#include <algorithm>

Game::Game(std::map<std::string, char> players) {
    dice = std::make_shared<Dice>;
    board = nullptr;
    
    for (auto n : players) {
        players.emplace_back(std::make_shared<Player>(n.first, n.second, 0, dice));
    }
    currentPlayer = players.begin();
    
    buildings.emplace_back(std::make_shared<OSAP>("OSAP", 0));
    buildings.emplace_back(std::make_shared<Academic>("AL", 1, nullptr, "Arts1", 40, 50, std::vector<unsigned int>{2, 10, 30, 90, 160, 250}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 2));
    buildings.emplace_back(std::make_shared<Academic>("ML", 3, nullptr, "Arts1", 60, 50, std::vector<unsigned int>{4, 20, 60, 180, 320, 450}));
    buildings.emplace_back(std::make_shared<Tuition>("Tuition", 4));
    buildings.emplace_back(std::make_shared<Residence>("MKV", 5, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("ECH", 6, nullptr, "Arts2", 100, 50, std::vector<unsigned int>{6, 30, 90, 270, 400, 550}));
    buildings.emplace_back(std::make_shared<NeedlesHall>("Needles Hall", 7));
    buildings.emplace_back(std::make_shared<Academic>("PAS", 8, nullptr, "Arts2", 100, 50, std::vector<unsigned int>{6, 30, 90, 270, 400, 550}));
    buildings.emplace_back(std::make_shared<Academic>("HH", 9, nullptr, "Arts2", 120, 50, std::vector<unsigned int>{8, 40, 100, 300, 450, 600}));
    buildings.emplace_back(std::make_shared<TimHortens>("DC Tims Line", 10));
    buildings.emplace_back(std::make_shared<Academic>("RCH", 11, nullptr, "Eng", 140, 100, std::vector<unsigned int>{10, 50, 150, 450, 625, 750}));
    buildings.emplace_back(std::make_shared<Gym>("PAC", 12, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("DWE", 13, nullptr, "Eng", 140, 100, std::vector<unsigned int>{10, 50, 150, 450, 625, 750}));
    buildings.emplace_back(std::make_shared<Academic>("CPH", 14, nullptr, "Eng", 160, 100, std::vector<unsigned int>{12, 60, 180, 500, 700, 900}));
    buildings.emplace_back(std::make_shared<Residence>("UWP", 15, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("LHI", 16, nullptr, "Health", 180, 100, std::vector<unsigned int>{14, 70, 200, 550, 750, 950}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 17));
    buildings.emplace_back(std::make_shared<Academic>("BMH", 18, nullptr, "Health", 180, 100, std::vector<unsigned int>{14, 70, 200, 550, 750, 950}));
    buildings.emplace_back(std::make_shared<Academic>("OPT", 19, nullptr, "Health", 200, 100, std::vector<unsigned int>{16, 80, 220, 600, 800, 1000}));
    buildings.emplace_back(std::make_shared<Goose>("Goose Nesting", 20));
    buildings.emplace_back(std::make_shared<Academic>("EV1", 21, nullptr, "Env", 220, 150, std::vector<unsigned int>{18, 90, 250, 700, 875, 1050}));
    buildings.emplace_back(std::make_shared<NeedlesHall>("Needles Hall", 22));
    buildings.emplace_back(std::make_shared<Academic>("EV2", 23, nullptr, "Env", 220, 150, std::vector<unsigned int>{18, 90, 250, 700, 875, 1050}));
    buildings.emplace_back(std::make_shared<Academic>("EV3", 24, nullptr, "Env", 240, 150, std::vector<unsigned int>{20, 100, 300, 750, 925, 1100}));
    buildings.emplace_back(std::make_shared<Residence>("V1", 25, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("PHYS", 26, nullptr, "Sci1", 260, 150, std::vector<unsigned int>{22, 110, 330, 800, 975, 1150}));
    buildings.emplace_back(std::make_shared<Academic>("B1", 27, nullptr, "Sci1", 260, 150, std::vector<unsigned int>{22, 110, 330, 800, 975, 1150}));
    buildings.emplace_back(std::make_shared<Gym>("CIF", 28, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("B2", 29, nullptr, "Sci1", 280, 150, std::vector<unsigned int>{24, 120, 360, 850, 1025, 1200}));
    buildings.emplace_back(std::make_shared<GoToTim>("Go to Tims"), 30);
    buildings.emplace_back(std::make_shared<Academic>("EIT", 31, nullptr, "Sci2", 300, 200, std::vector<unsigned int>{26, 130, 390, 900, 1100, 1275}));
    buildings.emplace_back(std::make_shared<Academic>("ESC", 32, nullptr, "Sci2", 300, 200, std::vector<unsigned int>{26, 130, 390, 900, 1100, 1275}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 33));
    buildings.emplace_back(std::make_shared<Academic>("C2", 34, nullptr, "Sci2", 320, 200, std::vector<unsigned int>{28, 150, 450, 1000, 1200, 1400}));
    buildings.emplace_back(std::make_shared<Residence>("REV", 35, nullptr));
    buildings.emplace_back(std::make_shared<NeedlesHall>("Needles Hall", 36));
    buildings.emplace_back(std::make_shared<Academic>("MC", 37, nullptr, "MATH", 350, 200, std::vector<unsigned int>{35, 175, 500, 1100, 1300, 1500}));
    buildings.emplace_back(std::make_shared<CoopFee>("Co-op Fee", 38));
    buildings.emplace_back(std::make_shared<Academic>("DC", 39, nullptr, "MATH", 400, 200, std::vector<unsigned int>{50, 200, 600, 1400, 1700, 2000}));
}


