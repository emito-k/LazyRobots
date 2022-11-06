#ifndef PLAYERCOMMAND_H
#define PLAYERCOMMAND_H

#include <string>
#include "Country.h"

class PlayerCommand {
    public:
        PlayerCommand(std::string commandName);
        virtual void executeCommand(Country* country) = 0;
        std::string getCommandName();
    
    private:
        std::string commandName;
};

#endif