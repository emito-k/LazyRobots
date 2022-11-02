#ifndef TANK_UNIT_FACTORY_H
#define TANK_UNIT_FACTORY_H
#include "MilitaryFactory.h"
#include "TankUnit.h"

class TankUnitFactory : public MilitaryFactory{
public:
    /** Create TankUnit object
     * @return TankUnit object
     */
    ArmyUnit * createUnit(std::string nodeName, std::string countryName) const override;
};

#endif
