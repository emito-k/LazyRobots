#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(std::string playerName);
    void performTurn() override;
    int getResponse(std::vector<int> options) override;
};

#endif