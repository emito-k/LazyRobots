#include "Player.h"

Player::Player(std::string playerName, std::string playerType) {
    this->playerName = playerName;
    this->playerType = playerType;
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
