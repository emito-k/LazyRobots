#include <iostream>
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(std::string playerName) : Player(playerName, "Human") {}

void HumanPlayer::performAction() {
    bool chosen_options[6] = {0};

    int user_input;

    while(!chosen_options[0]) {
        std::cout << "Select your next action: (" << Player::getPlayerName() << ")\n";
        std::cout << "0. End turn\n";
        if(!chosen_options[1]) std::cout << "1. Attack army\n";
        if(!chosen_options[2]) std::cout << "2. Move army\n";
        if(!chosen_options[3]) std::cout << "3. Supply army\n";
        if(!chosen_options[4]) std::cout << "4. Create army\n";
        if(!chosen_options[5]) std::cout << "5. Surrender\n";

        std::cout << "> ";
        
        std::cin >> user_input;

        if(user_input < 0 || user_input > 5 || chosen_options[user_input]) {
            continue;
        }

        chosen_options[user_input] = true;

        if(!chosen_options[0]) {
            Player::getCountry()->executeCommand(Player::getCommand(user_input));
        }
    }
}
