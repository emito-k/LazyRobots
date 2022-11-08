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

int Country::printArmies() {
    if(armies.empty()) {
        std::cout << countryName << " has no armies\n";
        sleep(2);
        system("clear");
        return 0;
    }
    else {
        std::cout << countryName << " armies indices: " << std::endl;

        for(int index = 0; index < armies.size(); index++) {
            ArmyUnit *unit = armies.at(index);
            std::cout << index << ". " << unit->getUnitType() << " at " << unit->getCurrentLocationName() << std::endl;
        }
        return armies.size();
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
    std::cout << "1. Make Tank Unit (150)\n";
    std::cout << "2. Make Attack Helicopter (200)\n";
    std::cout << "3. Make Infantry Unit (100)\n";
    std::cout << "4. Make SupplyUnit (150)\n>";
    //std::cin >> index;

    index = _player->getResponse({1,2,3,4});

    ArmyUnit *armyUnit = nullptr;
    if(index == 1) {
        if(money < 150)
            std::cout << "No enough cash" << std::endl;
        else {
            armyUnit = capital->getFactory(1)->createUnit(this);
            money -= 150;
        }
    }
    else if(index == 2) {
        if(money < 200)
            std::cout << "No enough cash" << std::endl;
        else {
            armyUnit = capital->getFactory(2)->createUnit(this);
            money -= 200;
        }
    }
    else if(index == 3) {
        if(money < 100)
            std::cout << "No enough cash" << std::endl;
        else {
            armyUnit = capital->getFactory(0)->createUnit(this);
            money -= 100;
        }
    }
    else if(index == 4) {
        if(money < 150)
            std::cout << "No enough cash" << std::endl;
        else {
            armyUnit = capital->getFactory(3)->createUnit(this);
            money -= 150;
        }
    }
    else
        std::cout << "Invalid index!!!" << std::endl;
    if(armyUnit != nullptr) {
        system("clear");
        std::cout << "Building " << armyUnit->getUnitType() << "..." << std::endl;
        sleep(2);
        system("clear");
        addArmy(armyUnit);
    }

}

int Country::getMoney() const {
    return money;
}

bool Country::isActive() {
    return flag->isActive();
}

Player *Country::getPlayer() {
    return _player;
}

void Country::setPlayer(Player* player) {
    _player = player;
}
