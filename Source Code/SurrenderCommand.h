#ifndef SURRENDERCOMMAND_H
#define SURRENDERCOMMAND_H

#include "PlayerCommand.h"

class SurrenderCommand : public PlayerCommand {
public:
    SurrenderCommand();
    void executeCommand(Country* country) override;
};

#endif