#ifndef MOVEARMYCOMMAND_H
#define MOVEARMYCOMMAND_H

#include "PlayerCommand.h"

class MoveArmyCommand : public PlayerCommand {
public:
    MoveArmyCommand();
    void executeCommand(Country* country) override;
};

#endif
