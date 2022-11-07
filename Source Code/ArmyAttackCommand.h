#ifndef ARMYATTACKCOMMAND_H
#define ARMYATTACKCOMMAND_H

#include "PlayerCommand.h"

class ArmyAttackCommand : public PlayerCommand {
public:
    ArmyAttackCommand();
    void executeCommand(Country *country) override;
};

#endif
