#include "Player.h"

Player::Player(std::string playerName, std::string playerType) {
    this->playerName = playerName;
    this->playerType = playerType;
    playerCommands.push_back(new ArmyAttackCommand());
    playerCommands.push_back(new MoveArmyCommand());
    playerCommands.push_back(new SupplyArmyCommand());
    playerCommands.push_back(new CreateArmyCommand());
    playerCommands.push_back(new SurrenderCommand());
}

PlayerCommand* PlayerCommand::getCommand(int index) {
    if(index < 0 || index >= playerCommands.size()) {
        return NULL;
    }

    return playerCommands.at(index);
}

Country* Player::getCountry() {
    return country;
}

std::string Player::getPlayerName() {
    return playerName;
}

std::string Player::getPlayerType() {
    return playerType;
}
