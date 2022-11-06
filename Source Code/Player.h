#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Country.h"
#include "PlayerCommand.h"

class Player {
    public:
        Player(std::string playerName);
        virtual void performTurn() = 0;

    private:
        Country* country;
        std::string playerName;
        std::vector<PlayerCommand*> playerCommands;
};

#endif