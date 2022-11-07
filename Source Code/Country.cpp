#include <iostream>
#include <unistd.h>
#include "config.h"
#include "Country.h"
#include "TankUnit.h"
#include "AttackHelicopterUnit.h"

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
    if(playerCommand != nullptr) {
        playerCommand->executeCommand(this);
    }
}

bool Country::printArmies() {
    if(armies.empty()) {
        std::cout << countryName << " has no armies\n";
        sleep(2);
        system("clear");
        return false;
    }
    else {
        std::cout << countryName << " armies indices: " << std::endl;

        for(int index = 0; index < armies.size(); index++) {
            ArmyUnit *unit = armies.at(index);
            std::cout << index << ". " << unit->getUnitType() << " at " << unit->getCurrentLocationName() << std::endl;
        }
        return true;
    }
}

void Country::setCapitol(Node* node) {
    capital = node;
}

std::string Country::getCountryName() {
    return countryName;
}

void Country::addArmy(ArmyUnit* armyUnit) {
    if(armyUnit != nullptr) {
        capital->addArmy(armyUnit);
        armies.push_back(armyUnit);
    }
}

ArmyUnit *Country::getArmy(int index) {
    return armies.at(index);
}

void Country::createArmy() {
    int index = 0;
    std::cout << "1. TankUnit\n";
    std::cout << "2. AttackHelicopterUnit\n";
    std::cout << "3. InfantryUnit\n";
    std::cout << "4. SupplyUnit\n>";
    std::cin >> index;

    ArmyUnit *armyUnit = nullptr;
    if(index == 1)
        armyUnit = capital->getFactory(1)->createUnit(this);
    else if(index == 2)
        armyUnit = capital->getFactory(2)->createUnit(this);
    else if(index == 3)
        armyUnit = capital->getFactory(0)->createUnit(this);
    else if(index == 4)
        armyUnit = capital->getFactory(3)->createUnit(this);
    else
        std::cout << "Invalid index!!!" << std::endl;
    if(armyUnit != nullptr) {
        system("clear");
        std::cout << "Building " << armyUnit->getUnitType() << "..." << std::endl;
        addArmy(armyUnit);
    }

}

int Country::getMoney() const {
    return money;
}

bool Country::isActive() {
    return flag->isActive();
}

