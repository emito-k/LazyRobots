#include <iostream>
#include "MoveArmyCommand.h"

MoveArmyCommand::MoveArmyCommand() : PlayerCommand("Move Command") {
}

void MoveArmyCommand::executeCommand(Country* country) {
    if(country == NULL) {
        return;
    }

    country->printArmies();

    int user_input = -1;
    
    std::cout << "Select the army you'd like to move: ";
    std::cin >> user_input;

    ArmyUnit *armyUnit = country->getArmy(user_input);

    std::vector<Node*> nodes = armyUnit->moveOptions();

    for(int index = 0; index < nodes.size(); index++) {
        std::cout << index << ". " << nodes.at(index) << "\n";
    }

    std::cout << "Select the location you'd like to move the army unit: ";
    std::cin >> user_input;

    armyUnit->getCurrentNode()->removeArmy(armyUnit);
    nodes.at(user_input)->addArmy(armyUnit);

    std::cout << "The " << armyUnit->getUnitType() << " of " << armyUnit->getCountry;
}