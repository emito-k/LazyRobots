#include <iostream>
#include "MoveArmyCommand.h"

MoveArmyCommand::MoveArmyCommand() : PlayerCommand("Move Command") {
}

void MoveArmyCommand::executeCommand(Country* country) {
    if(country == NULL) {
        return;
    }

    bool flag = country->printArmies();

    if(flag) {

        int user_input = -1;

        std::vector<int> temp;
        for(int i = 0; i < flag; i++){
            temp.push_back(i);
        }

        std::cout << "Select the army you'd like to move: ";
        user_input = country->getPlayer()->getResponse(temp);
        //std::cin >> user_input;
        system("clear");

        ArmyUnit *armyUnit = country->getArmy(user_input);

        std::vector<Node *> nodes = armyUnit->moveOptions();
        std::vector<int> options;

        for (int index = 0; index < nodes.size(); index++) {
            options.push_back(index);
            std::cout << index << ". " << nodes.at(index)->getNodeName() << "\n";
        }

        std::cout << "Select the location you'd like to move the army unit: ";
        //std::cin >> user_input;
        user_input = country->getPlayer()->getResponse(options);

        system("clear");

        armyUnit->getCurrentNode()->removeArmy(armyUnit);
        nodes.at(user_input)->addArmy(armyUnit);

    }
}