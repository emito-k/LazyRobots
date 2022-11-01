#include "SupplyUnitFactory.h"

ArmyUnit *SupplyUnitFactory::createUnit() const {
    return new SupplyUnit();
}