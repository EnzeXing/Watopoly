#include "Game.h"
#include <algorithm>
#include <sstream>

Game::Game(std::map<std::string, std::string> p) {
    dice = std::make_shared<Dice>();
    rimcup = std::make_shared<RimCup>();
    board = std::make_shared<Board>();
    
    for (auto n : p) {
        players.emplace_back(std::make_shared<Player>(n.first, n.second, 0, dice, 0, 1500, 0));
        board->updatePlayer(0, 0, n.second);
    }
    currentPlayer = players.begin();
    
    buildings.emplace_back(std::make_shared<OSAP>("OSAP", 0));
    buildings.emplace_back(std::make_shared<Academic>("AL", 1, nullptr, "Arts1", 40, 50, std::vector<unsigned int>{2, 10, 30, 90, 160, 250}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 2, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("ML", 3, nullptr, "Arts1", 60, 50, std::vector<unsigned int>{4, 20, 60, 180, 320, 450}));
    buildings.emplace_back(std::make_shared<Tuition>("Tuition", 4));
    buildings.emplace_back(std::make_shared<Residence>("MKV", 5, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("ECH", 6, nullptr, "Arts2", 100, 50, std::vector<unsigned int>{6, 30, 90, 270, 400, 550}));
    buildings.emplace_back(std::make_shared<NeedlesHall>("NeedlesHall", 7, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("PAS", 8, nullptr, "Arts2", 100, 50, std::vector<unsigned int>{6, 30, 90, 270, 400, 550}));
    buildings.emplace_back(std::make_shared<Academic>("HH", 9, nullptr, "Arts2", 120, 50, std::vector<unsigned int>{8, 40, 100, 300, 450, 600}));
    buildings.emplace_back(std::make_shared<TimHortons>("DCTimsLine", 10));
    buildings.emplace_back(std::make_shared<Academic>("RCH", 11, nullptr, "Eng", 140, 100, std::vector<unsigned int>{10, 50, 150, 450, 625, 750}));
    buildings.emplace_back(std::make_shared<Gym>("PAC", 12, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("DWE", 13, nullptr, "Eng", 140, 100, std::vector<unsigned int>{10, 50, 150, 450, 625, 750}));
    buildings.emplace_back(std::make_shared<Academic>("CPH", 14, nullptr, "Eng", 160, 100, std::vector<unsigned int>{12, 60, 180, 500, 700, 900}));
    buildings.emplace_back(std::make_shared<Residence>("UWP", 15, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("LHI", 16, nullptr, "Health", 180, 100, std::vector<unsigned int>{14, 70, 200, 550, 750, 950}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 17, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("BMH", 18, nullptr, "Health", 180, 100, std::vector<unsigned int>{14, 70, 200, 550, 750, 950}));
    buildings.emplace_back(std::make_shared<Academic>("OPT", 19, nullptr, "Health", 200, 100, std::vector<unsigned int>{16, 80, 220, 600, 800, 1000}));
    buildings.emplace_back(std::make_shared<Goose>("GooseNesting", 20));
    buildings.emplace_back(std::make_shared<Academic>("EV1", 21, nullptr, "Env", 220, 150, std::vector<unsigned int>{18, 90, 250, 700, 875, 1050}));
    buildings.emplace_back(std::make_shared<NeedlesHall>("NeedlesHall", 22, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("EV2", 23, nullptr, "Env", 220, 150, std::vector<unsigned int>{18, 90, 250, 700, 875, 1050}));
    buildings.emplace_back(std::make_shared<Academic>("EV3", 24, nullptr, "Env", 240, 150, std::vector<unsigned int>{20, 100, 300, 750, 925, 1100}));
    buildings.emplace_back(std::make_shared<Residence>("V1", 25, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("PHYS", 26, nullptr, "Sci1", 260, 150, std::vector<unsigned int>{22, 110, 330, 800, 975, 1150}));
    buildings.emplace_back(std::make_shared<Academic>("B1", 27, nullptr, "Sci1", 260, 150, std::vector<unsigned int>{22, 110, 330, 800, 975, 1150}));
    buildings.emplace_back(std::make_shared<Gym>("CIF", 28, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("B2", 29, nullptr, "Sci1", 280, 150, std::vector<unsigned int>{24, 120, 360, 850, 1025, 1200}));
    buildings.emplace_back(std::make_shared<GoToTims>("GotoTims", 30));
    buildings.emplace_back(std::make_shared<Academic>("EIT", 31, nullptr, "Sci2", 300, 200, std::vector<unsigned int>{26, 130, 390, 900, 1100, 1275}));
    buildings.emplace_back(std::make_shared<Academic>("ESC", 32, nullptr, "Sci2", 300, 200, std::vector<unsigned int>{26, 130, 390, 900, 1100, 1275}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 33, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("C2", 34, nullptr, "Sci2", 320, 200, std::vector<unsigned int>{28, 150, 450, 1000, 1200, 1400}));
    buildings.emplace_back(std::make_shared<Residence>("REV", 35, nullptr));
    buildings.emplace_back(std::make_shared<NeedlesHall>("NeedlesHall", 36, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("MC", 37, nullptr, "MATH", 350, 200, std::vector<unsigned int>{35, 175, 500, 1100, 1300, 1500}));
    buildings.emplace_back(std::make_shared<CoopFee>("Co-opFee", 38));
    buildings.emplace_back(std::make_shared<Academic>("DC", 39, nullptr, "MATH", 400, 200, std::vector<unsigned int>{50, 200, 600, 1400, 1700, 2000}));
}

Game::Game(std::ifstream & file) {
    dice = std::make_shared<Dice>();
    board = std::make_shared<Board>();
    rimcup = std::make_shared<RimCup>();
    
    int numPlayer;
    file >> numPlayer;
    file.ignore();
    for (int i = 0; i < numPlayer; ++i) {
        std::string playerInfo;
        getline(file, playerInfo);
        std::istringstream ss1{playerInfo};
        
        std::string name;
        std::string symbol;
        int TimCup;
        int money;
        int position;
        int stuckAtTim;
        int TimRound = 0;
        
        ss1 >> name;
        ss1 >> symbol;
        ss1 >> TimCup;
        ss1 >> money;
        ss1 >> position;
        board->updatePlayer(position, position, symbol);
        
        if (position == 10) {
            ss1 >> stuckAtTim;
            if (stuckAtTim == 1) {
                ss1 >> TimRound;
            }
        }
        
        players.emplace_back(std::make_shared<Player>(name, symbol, position, dice, TimCup, money, TimRound));
    }
    
    
    currentPlayer = players.begin();
    
    buildings.emplace_back(std::make_shared<OSAP>("OSAP", 0));
    buildings.emplace_back(std::make_shared<Academic>("AL", 1, nullptr, "Arts1", 40, 50, std::vector<unsigned int>{2, 10, 30, 90, 160, 250}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 2, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("ML", 3, nullptr, "Arts1", 60, 50, std::vector<unsigned int>{4, 20, 60, 180, 320, 450}));
    buildings.emplace_back(std::make_shared<Tuition>("Tuition", 4));
    buildings.emplace_back(std::make_shared<Residence>("MKV", 5, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("ECH", 6, nullptr, "Arts2", 100, 50, std::vector<unsigned int>{6, 30, 90, 270, 400, 550}));
    buildings.emplace_back(std::make_shared<NeedlesHall>("NeedlesHall", 7, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("PAS", 8, nullptr, "Arts2", 100, 50, std::vector<unsigned int>{6, 30, 90, 270, 400, 550}));
    buildings.emplace_back(std::make_shared<Academic>("HH", 9, nullptr, "Arts2", 120, 50, std::vector<unsigned int>{8, 40, 100, 300, 450, 600}));
    buildings.emplace_back(std::make_shared<TimHortons>("DCTimsLine", 10));
    buildings.emplace_back(std::make_shared<Academic>("RCH", 11, nullptr, "Eng", 140, 100, std::vector<unsigned int>{10, 50, 150, 450, 625, 750}));
    buildings.emplace_back(std::make_shared<Gym>("PAC", 12, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("DWE", 13, nullptr, "Eng", 140, 100, std::vector<unsigned int>{10, 50, 150, 450, 625, 750}));
    buildings.emplace_back(std::make_shared<Academic>("CPH", 14, nullptr, "Eng", 160, 100, std::vector<unsigned int>{12, 60, 180, 500, 700, 900}));
    buildings.emplace_back(std::make_shared<Residence>("UWP", 15, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("LHI", 16, nullptr, "Health", 180, 100, std::vector<unsigned int>{14, 70, 200, 550, 750, 950}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 17, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("BMH", 18, nullptr, "Health", 180, 100, std::vector<unsigned int>{14, 70, 200, 550, 750, 950}));
    buildings.emplace_back(std::make_shared<Academic>("OPT", 19, nullptr, "Health", 200, 100, std::vector<unsigned int>{16, 80, 220, 600, 800, 1000}));
    buildings.emplace_back(std::make_shared<Goose>("GooseNesting", 20));
    buildings.emplace_back(std::make_shared<Academic>("EV1", 21, nullptr, "Env", 220, 150, std::vector<unsigned int>{18, 90, 250, 700, 875, 1050}));
    buildings.emplace_back(std::make_shared<NeedlesHall>("NeedlesHall", 22, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("EV2", 23, nullptr, "Env", 220, 150, std::vector<unsigned int>{18, 90, 250, 700, 875, 1050}));
    buildings.emplace_back(std::make_shared<Academic>("EV3", 24, nullptr, "Env", 240, 150, std::vector<unsigned int>{20, 100, 300, 750, 925, 1100}));
    buildings.emplace_back(std::make_shared<Residence>("V1", 25, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("PHYS", 26, nullptr, "Sci1", 260, 150, std::vector<unsigned int>{22, 110, 330, 800, 975, 1150}));
    buildings.emplace_back(std::make_shared<Academic>("B1", 27, nullptr, "Sci1", 260, 150, std::vector<unsigned int>{22, 110, 330, 800, 975, 1150}));
    buildings.emplace_back(std::make_shared<Gym>("CIF", 28, nullptr));
    buildings.emplace_back(std::make_shared<Academic>("B2", 29, nullptr, "Sci1", 280, 150, std::vector<unsigned int>{24, 120, 360, 850, 1025, 1200}));
    buildings.emplace_back(std::make_shared<GoToTims>("GotoTims", 30));
    buildings.emplace_back(std::make_shared<Academic>("EIT", 31, nullptr, "Sci2", 300, 200, std::vector<unsigned int>{26, 130, 390, 900, 1100, 1275}));
    buildings.emplace_back(std::make_shared<Academic>("ESC", 32, nullptr, "Sci2", 300, 200, std::vector<unsigned int>{26, 130, 390, 900, 1100, 1275}));
    buildings.emplace_back(std::make_shared<SLC>("SLC", 33, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("C2", 34, nullptr, "Sci2", 320, 200, std::vector<unsigned int>{28, 150, 450, 1000, 1200, 1400}));
    buildings.emplace_back(std::make_shared<Residence>("REV", 35, nullptr));
    buildings.emplace_back(std::make_shared<NeedlesHall>("NeedlesHall", 36, rimcup));
    buildings.emplace_back(std::make_shared<Academic>("MC", 37, nullptr, "MATH", 350, 200, std::vector<unsigned int>{35, 175, 500, 1100, 1300, 1500}));
    buildings.emplace_back(std::make_shared<CoopFee>("Co-opFee", 38));
    buildings.emplace_back(std::make_shared<Academic>("DC", 39, nullptr, "MATH", 400, 200, std::vector<unsigned int>{50, 200, 600, 1400, 1700, 2000}));
    
    for (int i = 0; i < 40; ++i) {
        std::string buildingInfo;
        getline(file, buildingInfo);
        std::istringstream ss1{buildingInfo};
        std::cerr << buildingInfo << std::endl;
        
        std::string name;
        std::string owner;
        int improvement;
        
        ss1 >> name;
        ss1 >> owner;
        
        if (owner != "BANK") {
            ss1 >> improvement;
            auto property = std::dynamic_pointer_cast<Property>(buildings[i]);
            std::cerr << "Convert1" << std::endl;
            property->setOwner(findPlayer(owner));
            std::cerr << owner << std::endl;
            findPlayer(owner)->addBuilding(property->getMonopoly());
            std::cerr << "Find player" << std::endl;
            auto academic = std::dynamic_pointer_cast<Academic>(property);
            if (academic != nullptr) {
                academic->setImprovement(improvement);
                std::cerr << "Set Improvement" << std::endl;
            } 
        }
        
    }
}

std::shared_ptr<Board> Game::getBoard() {
    return board;
}

std::string Game::currentPlayerName() {
    return (*currentPlayer)->getName();
}

void Game::nextPlayer() {
    currentPlayer++;
    if (currentPlayer == players.end()) currentPlayer = players.begin();
    std::string message = "Next player is " + (*currentPlayer)->getName();
    board->printMessage(message, std::cout);
}

void Game::movePlayer(int steps) {
    int position = ((*currentPlayer)->getPosition() + steps + 40) % 40;
    board->updatePlayer((*currentPlayer)->getPosition(), position, (*currentPlayer)->getSymbol());
    (*currentPlayer)->move(steps);
    std::string message = (*currentPlayer)->getName() + " arrives at " + buildings[(*currentPlayer)->getPosition()]->getName();
    board->printMessage(message, std::cout);
    try {
        (*currentPlayer)->visit(*(buildings[(*currentPlayer)->getPosition()]));
    } catch (NoOwner & e) {
        board->printMessage(e.message, std::cout);
        auto property = std::dynamic_pointer_cast<Property>(buildings[(*currentPlayer)->getPosition()]);
        try {
            (*currentPlayer)->giveMoney(nullptr, property->getPurchaseCost());
        } catch (giveMoneyAlert & e) {
            printMessage(e.message);
        } catch (NoEnoughMoney & e) {
            std::string message = "You don't have enough cash! You need " + std::to_string(e.needAmount) + " dollars.";
            board->printMessage(message, std::cout);
        }
        
        property->setOwner(*currentPlayer);
        (*currentPlayer)->addBuilding(property->getMonopoly());
        std::string message = (*currentPlayer)->getName() + " has bought " + property->getName();
        board->printMessage(message, std::cout);
        // need to call input.purchaseOrNot()
    } catch (NoEnoughMoney & e) {
        std::string message = "You don't have enough cash! You need " + std::to_string(e.needAmount) + " dollars.";
        board->printMessage(message, std::cout);
        // need to call input.NotEnoughMoney()
    } catch (giveMoneyAlert & e) {
        printMessage(e.message);
    } catch (NoEnoughCup & e) {
        board->printMessage(e.message, std::cout);
    } catch (TuitionException & e) {
        board->printMessage(e.message, std::cout);
        // need to call input.PayTuition()
    } catch (TimHortonsException & e) {
        board->printMessage(e.message, std::cout);
        (*currentPlayer)->stayInLine();
        (*currentPlayer)->move(-20);
        printMessage("You are sent to DC Tims Line.");
    } catch (getRimCup & e) {
        board->printMessage(e.message, std::cout);
        rimcup->giveCup(**currentPlayer);
    } catch (SLCException & e) {
        board->printMessage(e.message, std::cout);
        std::string message = "You need to go ";
        if (e.steps > 0) {
            message += "ahead " + std::to_string(e.steps) + " steps.";
        } else {
            int step = 0 - e.steps;
            message += "back " + std::to_string(step) + " steps.";
        }
        board->printMessage(message, std::cout);
        movePlayer(e.steps);
    } catch (GooseException & e) {
        board->printMessage(message, std::cout);
    } catch (NeedlesHallException & e) {
        board->printMessage(e.message, std::cout);
        if (e.amount > 0) {
            std::string message = "You receive " + std::to_string(e.amount) + " dollars.";
            board->printMessage(message, std::cout);
            (*currentPlayer)->addMoney(e.amount);
        } else {
            int a = 0 - e.amount;
            std::string message = "You lose " + std::to_string(a) + " dollars.";
            board->printMessage(message, std::cout);
            (*currentPlayer)->giveMoney(nullptr, e.amount);
        }
    } catch (ImprovementException & e) {
        board->printMessage(e.message, std::cout);
    }
}

std::shared_ptr<Player> Game::findPlayer(std::string s) {
    for (auto n : players) {
        if (n->getName() == s || n->getSymbol() == s) return n;
    }
    
    return nullptr;
}

std::shared_ptr<Building> Game::findBuilding(std::string name) {
    for (auto n : buildings) {
        if (n->getName() == name) return n;
    }
    return nullptr;
}

void Game::purchase(std::string buildingName) {
    auto building = findBuilding(buildingName);
    auto property = std::dynamic_pointer_cast<Property>(building);
    try {
        (*currentPlayer)->giveMoney(nullptr, property->getPurchaseCost());
    } catch (NoEnoughMoney & e) {
        // call input.notEnoughMoney()
    } catch (giveMoneyAlert & e) {
        printMessage(e.message);
    } 
    property->setOwner(*currentPlayer);
    (*currentPlayer)->addBuilding(property->getMonopoly());
    printMessage((*currentPlayer)->getName() + " has bought " + property->getName() + ".");
}

void Game::tradeBuilding(std::string buildingName, std::string receiver) {
    auto building = findBuilding(buildingName);
    if (building == nullptr) {
        printMessage("This building does not exist!");
        throw WrongBuildingException("");
    }
    
    auto property = std::dynamic_pointer_cast<Property>(building);
    if (property == nullptr || property->getOwner() != (*currentPlayer)) {
        printMessage("This building is not your property!");
        throw WrongBuildingException("");
    }
    
    auto player = findPlayer(receiver);
    if (player == nullptr) {
        printMessage("Wrong player name.");
        throw WrongPlayerException("");
    }
    
    property->setOwner(player);
    (*currentPlayer)->loseBuilding(property->getMonopoly());
    player->addBuilding(property->getMonopoly());
    std::string message = player->getName() + " now has " + property->getName() + ".";
    printMessage(message);
}

void Game::tradeBuilding(std::string giver, std::string receiver, std::string buildingName) {
    auto building = findBuilding(buildingName);
    if (building == nullptr) {
        printMessage("This building does not exist!");
        throw WrongBuildingException("");
    }
    
    auto property = std::dynamic_pointer_cast<Property>(building);
    auto g = findPlayer(giver);
    auto r = findPlayer(receiver);
    if (g == nullptr || r == nullptr) {
        printMessage("Wrong player name.");
        throw WrongPlayerException("");
    }
    
    if (property == nullptr || property->getOwner() != g) {
        printMessage("This building is not your property!");
        throw WrongBuildingException("");
    }
    
    property->setOwner(r);
    g->loseBuilding(property->getMonopoly());
    r->addBuilding(property->getMonopoly());
    std::string message = r->getName() + " now has " + property->getName() + ".";
    printMessage(message);
}

void Game::trade(std::string receiver, int giveAmount, std::string buildingName) {
    auto r = findPlayer(receiver);
    if (r == nullptr) {
        printMessage("Wrong player name.");
        throw WrongPlayerException("");
    }
    
    try {
        (*currentPlayer)->giveMoney(r, giveAmount);
    } catch (NoEnoughMoney & e) {
        printMessage(e.message);
        throw e;
    } catch (giveMoneyAlert & e) {
        printMessage(e.message);
    }
    
    tradeBuilding(receiver, (*currentPlayer)->getName(), buildingName);
}

void Game::trade(std::string receiver, std::string buildingName, int receiveAmount) {
    auto r = findPlayer(receiver);
    if (r == nullptr) {
        printMessage("Wrong player name.");
        throw WrongPlayerException("");
    }
    
    try {
        r->giveMoney(*currentPlayer, receiveAmount);
    } catch (NoEnoughMoney & e) {
        printMessage(e.message);
        throw e;
    } catch (giveMoneyAlert & e) {
        printMessage(e.message);
    }
    
    tradeBuilding((*currentPlayer)->getName(), receiver, buildingName);
}

void Game::trade(std::string receiver, std::string giveBuildingName, std::string receiveBuildingName) {
    tradeBuilding((*currentPlayer)->getName(), receiver, giveBuildingName);
    tradeBuilding(receiver, (*currentPlayer)->getName(), receiveBuildingName);
}

void Game::saveGame(std::ofstream & file) {
    file << players.size() << std::endl;
    auto n1 = currentPlayer;
    for (unsigned int i = 0; i < players.size(); ++i) {
        file << (*n1)->getName() << " " << (*n1)->getSymbol() << " " << (*n1)->getCup() << " " << (*n1)->getMoney() << " " << (*n1)->getPosition();
        if ((*n1)->getPosition() == 10) {
            if ((*n1)->getTimRound() == 0) file << " 0";
            else {
                file << " 1 " << (*n1)->getTimRound();
            }
        }
        file << std::endl;
        n1++;
        if (n1 == players.end()) n1 = players.begin();
    }
    
    for (auto n : buildings) {
        file << n->getName() << " ";
        auto n2 = std::dynamic_pointer_cast<Property>(n);
        if (n2 != nullptr) {
            if (n2->getOwner() != nullptr) {
                file << n2->getOwner()->getName() << " ";
            } else {
                file << "BANK ";
            }
            auto n3 = std::dynamic_pointer_cast<Academic>(n2);
            if (n3 != nullptr) {
                file << n3->getImprovement() << std::endl;
            } else {
                file << "0\n";
            }
        } else {
            file << "BANK 0" << std::endl;
        }
    }
    
    board->printMessage("This game has been saved.", std::cout);
}

int Game::sellImprovement(std::string buildingName) {
    auto building = findBuilding(buildingName);
    if (building == nullptr) {
        printMessage("Wrong building name.");
        throw WrongBuildingException("");
    }
    
    auto academic = std::dynamic_pointer_cast<Academic>(building);
    if (academic == nullptr || academic->getOwner() != (*currentPlayer)) {
        printMessage("This building is not your property.");
        throw WrongBuildingException("");
    }
    
    if (academic->getImprovement() == 0) {
        printMessage("This building has no improvement.");
        throw WrongBuildingException("");
    }
    
    int addAmount = academic->getImprovementCost() / 2;
    (*currentPlayer)->addMoney(addAmount);
    printMessage("You have sold an improvement of " + academic->getName() + " and received $" + std::to_string(addAmount) + ".");
    return addAmount;
}

int Game::mortgage(std::string buildingName) {
    auto building = findBuilding(buildingName);
    if (building == nullptr) {
        printMessage("Wrong building name.");
        throw WrongBuildingException("");
    }
    
    auto property = std::dynamic_pointer_cast<Property>(building);
    if (property == nullptr || property->getOwner() != (*currentPlayer)) {
        printMessage("This building is not your property!");
        throw WrongBuildingException("");
    }
    
    auto academic = std::dynamic_pointer_cast<Academic>(property);
    if (academic != nullptr && academic->getImprovement() > 0) {
        printMessage("You need to sell all improvements of this building before mortgage.");
        throw WrongBuildingException("");
    }
    
    if (property->Mortgage()) {
        printMessage("This building has been mortgaged!");
        throw WrongBuildingException("");
    } else {
        property->setMortgage(true);
        (*currentPlayer)->addMoney(property->getPurchaseCost() / 2);
        std::string message = "You have mortgaged " + property->getName() + " and received $" + std::to_string(property->getPurchaseCost() / 2) + ".";
        printMessage(message);
    }
    
    return property->getPurchaseCost() / 2;
}

void Game::unmortgage(std::string buildingName) {
    auto building = findBuilding(buildingName);
    if (building == nullptr) {
        printMessage("Wrong building name.");
        throw WrongBuildingException("");
    }
    
    auto property = std::dynamic_pointer_cast<Property>(building);
    if (property == nullptr || property->getOwner() != (*currentPlayer)) {
        printMessage("This building is not your property!");
        throw WrongBuildingException("");
    }
    
    if (!property->Mortgage()) {
        printMessage("This building is not mortgaged!");
        throw WrongBuildingException("");
    }
    
    int pay = property->getPurchaseCost() * 0.6;
    
    try {
        (*currentPlayer)->giveMoney(nullptr, pay);
    } catch (NoEnoughMoney & e) {
        printMessage(e.message);
        throw e;
    } catch (giveMoneyAlert & e) {
        printMessage(e.message);
        std::string message = "You have unmortgaged " + property->getName() + ".";
        printMessage(message);
        property->setMortgage(false);
    }
}

void Game::drawBoard() {
    board->drawBoard(std::cout);
}

void Game::roll() {
    int a = (*currentPlayer)->roll();
    printMessage("Dice1: " + std::to_string(a));
    int b = (*currentPlayer)->roll();
    printMessage("Dice2: " + std::to_string(b));
    (*currentPlayer)->move(a + b);    
}

bool Game::rollDouble() {
    int a = (*currentPlayer)->roll();
    printMessage("Dice1: " + std::to_string(a));
    int b = (*currentPlayer)->roll();
    printMessage("Dice2: " + std::to_string(b));
    return (a == b);
}

void Game::useRimCup() {
    rimcup->receiveCup(**currentPlayer);
    leaveLine();
}

void Game::buyCoffee() {
    (*currentPlayer)->giveMoney(nullptr, 50);
    leaveLine();
}

void Game::stayInLine() {
    (*currentPlayer)->stayInLine();
}

void Game::leaveLine() {
    (*currentPlayer)->leaveLine();
}

void Game::printMessage(std::string message) {
    board->printMessage(message, std::cout);
}
