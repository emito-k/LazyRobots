#ifndef MILITARY_FACTORY_H
#define MILITARY_FACTORY_H
#include "ArmyUnit.h"
#include <string>

class ArmyUnit;

class MilitaryFactory {
public:
    /** Create an ArmyUnit object
     * @return an ArmyUnit object
     */
    virtual ArmyUnit* createUnit(std::string nodeName, std::string countryName) const = 0;
    virtual ~MilitaryFactory(){};
};

#endif
