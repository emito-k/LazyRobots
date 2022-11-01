#ifndef MILITARY_FACTORY_H
#define MILITARY_FACTORY_H
#include "ArmyUnit.h"

class ArmyUnit;

class MilitaryFactory {
public:
    virtual ArmyUnit* createUnit() const = 0;
    virtual ~MilitaryFactory(){};
};

#endif
