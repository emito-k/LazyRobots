#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Country.h"
#include "PlayerCommand.h"

class PlayerCommand;

class Player {
public:
    Player(std::string playerName, std::string playerType);
    virtual void performTurn() = 0;
    virtual int getResponse(std::vector<int> options) = 0;
    std::string getPlayerType();
    std::string getPlayerName();
    Country* getCountry();
    PlayerCommand* getCommand(int index);
private:
    Country* country;
    std::string playerName;
    std::string playerType;
    std::vector<PlayerCommand*> playerCommands;
};

#endif
