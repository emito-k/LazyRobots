#include <iostream>
#include "ArmyAttackCommand.h"

ArmyAttackCommand::ArmyAttackCommand() : PlayerCommand("Attack Command") {
}

void ArmyAttackCommand::executeCommand(Country *country) {
    if(country == NULL) {
        return;
    }

    std::cout << "Select the army you'd like to carry out the attack:\n";
    country->printArmies();

    int index = -1;

    std::cin >> index;

    ArmyUnit* armyUnit = country->getArmy(index);

    if(armyUnit == NULL) {
        return;
    }
    
    armyUnit->printTargets();

    std::cin >> index;

    ArmyUnit *enemyUnit = armyUnit->getTarget(index);

    if(enemyUnit != NULL) {
        armyUnit->attackUnit(enemyUnit);
    }
    
    // std::cout << "Select the army you'd like to carry out the attack:\n";
}
