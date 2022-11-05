#include "TankUnitFactory.h"

ArmyUnit *TankUnitFactory::createUnit(Country* country) const {
    return new TankUnit(country);
}
