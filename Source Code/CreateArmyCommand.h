#ifndef CREATEARMYCOMMAND_H
#define CREATEARMYCOMMAND_H

#include "PlayerCommand.h"

class CreateArmyCommand : public PlayerCommand {
public:
    CreateArmyCommand();
    void executeCommand(Country* country) override;
};

#endif