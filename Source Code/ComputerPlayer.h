#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"

class ComputerPlayer : public Player {
public:
    /**
    * sets the #playerName to @param playerName and sets #playerType to "Computer"
    */
    ComputerPlayer(std::string playerName = "Bobert");
    /**
    * This function prompts itself to select a command and pass it to the #country object's executeCommand function
    */
    void performTurn() override;
};

#endif
