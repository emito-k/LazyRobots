#ifndef INFANTRY_UNIT_FACTORY_H
#define INFANTRY_UNIT_FACTORY_H
#include "MilitaryFactory.h"
#include "InfantryUnit.h"

class InfantryUnitFactory : public MilitaryFactory {
public:
    ArmyUnit * createUnit() const override;
};


#endif
