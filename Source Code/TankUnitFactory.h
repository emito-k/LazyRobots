#ifndef TANK_UNIT_FACTORY_H
#define TANK_UNIT_FACTORY_H
#include "MilitaryFactory.h"
#include "TankUnit.h"

class TankUnitFactory : public MilitaryFactory{
public:
    ArmyUnit * createUnit() const override;
};


#endif
