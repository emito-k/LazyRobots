#ifndef ARMYATTACKCOMMAND_H
#define ARMYATTACKCOMMAND_H

#include "PlayerCommand.h"

class ArmyAttackCommand : public PlayerCommand {
public:
    /**
    * Constructor that intializes the PlayerCommand parent function with "Attack Commad"
    */
    ArmyAttackCommand();
    /*
    * This function uses @param country to issue an attack command on enemy units
    */
    void executeCommand(Country *country) override;
};

#endif
