#ifndef COUNTRY_H
#define COUNTRY_H

#include <vector>
#include <string>
// #include "ArmyUnit"
#include "Flag.h"
#include "Node.h"

class PlayerCommand;
class ArmyUnit;

class Country {
    public:
        // @param countryName is the name of the country
        // @returns nothing
        Country(string countryName);
        void surrender();
        void printArmies();
        void executeCommand(PlayerCommand *playerCommand);
        void setCapitol(Node* node);
        std::string getCountryName();
        void addArmy(ArmyUnit* armyUnit);

    private:
        Node* capital;
        Flag* flag;
        std::vector<ArmyUnit*> armies;
        int money;
        std::string countryName;
};

#endif