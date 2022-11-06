#include "SupplyArmyCommand.h"

SupplyArmyCommand::SupplyArmyCommand() : PlayerCommand("Supply Command") {
}

void SupplyArmyCommand::executeCommand(Country* country) {
    if(country == NULL) {
        return;
    }
    
    std::cout << "Select the army you'd like to carry out the supply command:\n";
    country->printArmies();

    int index = -1;

    std::cin >> index;

    ArmyUnit* armyUnit = country->getArmy(index);

    if(armyUnit == NULL) {
        return;
    }
    
    Node* node = armyUnit->getCurrentNode();

    

    // std::cin >> index;

    // ArmyUnit *enemyUnit = armyUnit->getTarget(index);

    // if(enemyUnit != NULL) {
    //     armyUnit->attackUnit(enemyUnit);
    // }
    
}

