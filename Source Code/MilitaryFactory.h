#ifndef MILITARY_FACTORY_H
#define MILITARY_FACTORY_H
#include "ArmyUnit.h"
#include "Country.h"
#include "Node.h"
#include <string>

class ArmyUnit;

class MilitaryFactory {
public:
    /** Create an ArmyUnit object
     * @return an ArmyUnit object
     */
    virtual ArmyUnit* createUnit(Country* country) const = 0;
    virtual ~MilitaryFactory(){};
};

#endif
