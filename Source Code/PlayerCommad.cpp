#include "PlayerCommand.h"

PlayerCommand::PlayerCommand(std::string commandName) {
    this->commandName = commandName;
}

std::string PlayerCommand::getCommandName() {
    return commandName;
}
