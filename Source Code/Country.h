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
        /**
        * Changes the state of the flag from home flag to white flag
        */
        void surrender();
        /**
        * Prints out a list of all the army units it control
        */
        void printArmies();
        /**
        * The function executes the executeCommand method of @param playerCommand 
        */
        void executeCommand(PlayerCommand *playerCommand);
        /**
        * The function sets @param node to be the capitol of the Country object
        */
        void setCapitol(Node* node);
        /**
        * @returns the name of the country object
        */
        std::string getCountryName();
        /**
        * The function adds @armyUnit into the array of armies
        */
        void addArmy(ArmyUnit* armyUnit);
        /**
        * @returns the result of the flag state isActive function
        */
        bool isActive();

    private:
        Node* capital;
        Flag* flag;
        std::vector<ArmyUnit*> armies;
        int money;
        std::string countryName;
};

#endif
