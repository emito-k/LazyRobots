#ifndef HOMEFLAGSTATE_H
#define HOMEFLAGSTATE_H

#include "FlagState.h"

class HomeFlagState : public FlagState {
public:
    // @returns true to indicate the will to continue fighting
    bool isActive() override;
};

#endif