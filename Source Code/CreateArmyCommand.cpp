#include <iostream>
#include <iostream>
#include "CreateArmyCommand.h"

CreateArmyCommand::CreateArmyCommand() : PlayerCommand("Create Army Command") {
}

void CreateArmyCommand::executeCommand(Country* country) {
    if(country == NULL) {
        return;
    }

    std::cout << "The country currently has R" << country->getMoney() << ", what would you like to build? " << std::endl;

    country->createArmy();
}
