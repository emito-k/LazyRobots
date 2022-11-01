#include "InfantryUnitFactory.h"

ArmyUnit *InfantryUnitFactory::createUnit() const {
    return new InfantryUnit();
}
