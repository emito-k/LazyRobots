#ifndef COUNTRY_H
#define COUNTRY_H

#include <vector>
#include <string>
#include "Flag.h"
#include "Node.h"
#include "Player.h"
#include "PlayerCommand.h"

class PlayerCommand;
class ArmyUnit;
class Node;

class Country {
public:
    // @param countryName is the name of the country
    // @returns nothing
    Country(std::string countryName);
    void surrender();
    bool printArmies();
    void executeCommand(PlayerCommand *playerCommand);
    void setCapitol(Node* node);
    std::string getCountryName();
    void addArmy(ArmyUnit* armyUnit);
    ArmyUnit* getArmy(int index);
    void createArmy();
    int getMoney() const;
    bool isActive();

private:
    Node* capital;
    Flag* flag;
    std::vector<ArmyUnit*> armies;
    int money;
    std::string countryName;
};

#endif