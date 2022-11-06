#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player {
    public:
        ComputerPlayer(std::string playerName = "Bobert");
        void performAction() override;
};

#endif