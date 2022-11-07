#ifndef SUPPLYARMYCOMMAND_H
#define SUPPLYARMYCOMMAND_H

#include "PlayerCommand.h"

class SupplyArmyCommand : public PlayerCommand {
public:
    SupplyArmyCommand();
    void executeCommand(Country* country) override;
};

#endif