#include "FlagState.h"
#include "WhiteFlagState.h"
#include "HomeFlagState.h"
#include "Flag.h"

Flag::Flag() {
    flagState = new HomeFlagState();
}

Flag::~Flag() {
    delete  flagState;
}

bool Flag::isActive() {
    return flagState->isActive();
}

void Flag::surrender() {
    delete flagState;
    flagState = new WhiteFlagState();
}
