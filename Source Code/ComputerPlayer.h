#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player {
public:
    /**
    * sets the #playerName to @param playerName and sets #playerType to "Computer"
    */
    ComputerPlayer(std::string playerName = "Bobert");
    void performTurn() override;
};

#endif
