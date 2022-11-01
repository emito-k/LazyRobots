#include "TankUnitFactory.h"

ArmyUnit *TankUnitFactory::createUnit() const {
    return new TankUnit();
}
