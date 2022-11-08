#include "SupplyArmyCommand.h"
#include <unistd.h>

SupplyArmyCommand::SupplyArmyCommand() : PlayerCommand("Supply Command") {
}

void SupplyArmyCommand::executeCommand(Country* country) {
    if(country == NULL) {
        return;
    }

    int flag = country->printArmies();

    if(flag){
        std::cout << "Select the army you'd like to carry out the supply command: ";
        int index = -1;

        //std::cin >> index;

        std::vector<int> temp;
        for(int i = 0; i < flag; i++){
            temp.push_back(i);
        }
        index = country->getPlayer()->getResponse(temp);

        ArmyUnit* armyUnit = country->getArmy(index);

        if(armyUnit == NULL) {
            return;
        }

        Node* node = armyUnit->getCurrentNode();

        std::vector<ArmyUnit*> armies = node->getOccupants();
        if(armies.size() == 1){
            std::cout << "No armies to supply" << std::endl;
            sleep(3);
            if(country->getPlayer()->getPlayerType() == "Human")
                system("clear");
        }
        else {
            auto iter = armies.begin();
            std::vector<ArmyUnit*> armiesToSupply;
            std::vector<int> options;
            int i = 0, j = 0;
            for (iter; iter != armies.end(); iter++) {
                if ((*iter) != armyUnit && (*iter)->getCountry() == armyUnit->getCountry()) {
                    options.push_back(i);
                    std::cout << i++ << ". " << (*iter)->getUnitType() << std::endl;
                    armiesToSupply.push_back(*iter);
                    j++;
                }
            }
            if(j != 0) {
                int choice = 0;
                std::cout << "Select the army you'd like to supply: ";
                //std::cin >> choice;
                choice = country->getPlayer()->getResponse(options);

                armyUnit->supplyUnit(armies.at(choice));
                if(country->getPlayer()->getPlayerType() == "Human")
                    system("clear");
                std::cout << armyUnit->getUnitType() << " has supplied " << armiesToSupply.at(choice)->getUnitType() << std::endl;
            }
            else
                std::cout << "No armies to supply" << std::endl;
        }
    }

}