#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Country.h"
#include "PlayerCommand.h"

class Player {
    public:
        Player(std::string playerName, std::string playerType);
        virtual void performTurn() = 0;
        std::string getPlayerType();
        std::string getPlayerName();
        Country* getCountry();

    private:
        Country* country;
        std::string playerName;
        std::string playerType;
        std::vector<PlayerCommand*> playerCommands;
};

#endif