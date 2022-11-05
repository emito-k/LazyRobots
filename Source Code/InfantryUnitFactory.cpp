#include "InfantryUnitFactory.h"

ArmyUnit *InfantryUnitFactory::createUnit(Country* country) const {
    return new InfantryUnit(country);
}
