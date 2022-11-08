#include <iostream>
#include "ArmyAttackCommand.h"

ArmyAttackCommand::ArmyAttackCommand() : PlayerCommand("Attack Command") {
}

void ArmyAttackCommand::executeCommand(Country *country) {
    if(country == nullptr) {
        return;
    }

    int flag = country->printArmies();

    if(flag != 0){
        std::cout << "Select the army you'd like to carry out the attack:\n";
        int index = -1;

        //std::cin >> index;
        std::vector<int> temp;
        for(int i = 0; i < flag; i++){
            temp.push_back(i);
        }
        index = country->getPlayer()->getResponse(temp);

        ArmyUnit* armyUnit = country->getArmy(index);

        if(armyUnit == nullptr) {
            return;
        }

        flag = armyUnit->printTargets();

        if(flag) {
            //std::cin >> index;

            ArmyUnit *enemyUnit = armyUnit->getTarget(index);

            if(enemyUnit != nullptr) {
                armyUnit->attackUnit(enemyUnit);
            }
        }
    }
}
