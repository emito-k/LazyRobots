#ifndef MILITARY_FACTORY_H
#define MILITARY_FACTORY_H
#include "ArmyUnit.h"

class ArmyUnit;

class MilitaryFactory {
public:
    /** Create an ArmyUnit object
     * @return an ArmyUnit object
     */
    virtual ArmyUnit* createUnit() const = 0;
    virtual ~MilitaryFactory(){};
};

#endif
