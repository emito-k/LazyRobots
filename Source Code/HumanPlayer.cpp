#include <iostream>
#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(std::string playerName) : Player(playerName, "Human") {}

void HumanPlayer::performTurn() {
    bool chosen_options[7] = {0};
    std::vector<int> options;
    options.push_back(0);

    int user_input;

    while(!chosen_options[0]) {
        std::cout << std::endl;
        std::cout << "Select your next action: (" << Player::getPlayerName() << " : Country currently has R" << this->getCountry()->getMoney()  << ")\n";
        std::cout << "0. End turn\n";
        if(!chosen_options[1]){
            options.push_back(1);
            std::cout << "1. Attack army\n";
        }
        if(!chosen_options[2]){
            options.push_back(2);
            std::cout << "2. Move army\n";}
        if(!chosen_options[3]){
            options.push_back(3);
            std::cout << "3. Supply army\n";}
        if(!chosen_options[4]){
            options.push_back(4);
            std::cout << "4. Create army\n";}
        if(!chosen_options[5]){
            options.push_back(5);
            std::cout << "5. Surrender\n";}
        if(!chosen_options[6]){
            options.push_back(6);
            std::cout << "6. Show armies\n";}

        std::cout << "> ";

        //std::cin >> user_input;
        user_input = getResponse(options);

        if(user_input < 0 || user_input > 6 || chosen_options[user_input]) {
            continue;
        }

        chosen_options[user_input] = true;
        system("clear");

        if(!chosen_options[0]) {
            if(user_input == 6){
                this->getCountry()->printArmies();
            }
            else
                Player::getCommand(user_input-1)->executeCommand(Player::getCountry());
        }
    }
}

int HumanPlayer::getResponse(std::vector<int> options) {
    int val;

    std::cin >> val;
    bool flag = false;
    while(!flag) {
        for (int i = 0; i < options.size(); i++) {
            if (options.at(i) == val) {
                flag = true;
                return val;
            }
        }
        std::cout << "Invalid option. Please enter valid option: ";
        std::cin >> val;
    }
}
