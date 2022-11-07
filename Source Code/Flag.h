#ifndef FLAG_H
#define FLAG_H

#include "FlagState.h"

class Flag {
public:
    // ! The constructor initializes the #flagState member to home flag state
    Flag();
    // ! The destructor deallocates the #flagState member
    ~Flag();
    // @returns the either true or false depending on the state of the flag
    bool isActive();
    // ! changes the state of the #flagState member to white flag state
    void surrender();

private:
    // ! This is the flag state object
    FlagState *flagState;
};

#endif