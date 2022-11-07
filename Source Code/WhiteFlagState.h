#ifndef WHITEFLAGSTATE_H
#define WHITEFLAGSTATE_H

#include "FlagState.h"

class WhiteFlagState : public FlagState {
public:
    // @returns false to indicate the will to nolonger fight
    bool isActive() override;
};

#endif
