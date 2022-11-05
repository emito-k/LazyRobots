#include "SupplyUnitFactory.h"

ArmyUnit *SupplyUnitFactory::createUnit(Country* country) const {
    return new SupplyUnit(country);
}