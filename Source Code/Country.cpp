#include <iostream>
#include "config.h"
#include "Country.h"

Country::Country(std::string countryName) {
    this->countryName = countryName;
    money = COUNTRY_START_AMOUNT; // default amount
    flag = new Flag();
}

void Country::surrender() {
    flag->surrender();
    std::cout << countryName << " has changed their home flag to the white flag, they've given up fighting\n";
}

void Country::executeCommand(PlayerCommand *playerCommand) {
    if(playerCommand != NULL) {
        playerCommand->executeCommand(this);
    }
}

void Country::printArmies() {
    if(armies.size() == 0) {
        std::cout << countryName << " has no armies\]n";
    }
    else {
        std::cout << countryName << " armies indices: " << endl;

        for(int index = 0; index < armies.size(); index++) {
            ArmyUnit *unit = armies.at(index);
            std::cout << index << ". " << unit->getUnitType() << " at " << unit->getCurrentLocationName() << endl;
        }
    }
}

void Country::setCapitol(Node* node) {
    capital = node;
}

void Country::getCountryName() {
    return countryName;
}

void Country::addArmy(ArmyUnit* armyUnit) {
    if(armyUnit != NULL) {
        armies.push_back(armyUnit);
    }
}

