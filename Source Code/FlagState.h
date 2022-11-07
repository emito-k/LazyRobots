#ifndef FLAGSTATE_H
#define FLAGSTATE_H

class FlagState {
public:
    // @returns true or false depending on the flag state which tells whether a country will fight or not
    virtual bool isActive() = 0;
};

#endif