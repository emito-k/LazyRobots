#include "SurrenderCommand.h"

SurrenderCommand::SurrenderCommand() : PlayerCommand("Surrender Command") {}

void SurrenderCommand::executeCommand(Country* country) {
    if(country == NULL) {
        return;
    }

    country->surrender();
}