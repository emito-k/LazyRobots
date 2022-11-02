#include "InfantryUnitFactory.h"

ArmyUnit *InfantryUnitFactory::createUnit(Country* country, Node* node) const {
    return new InfantryUnit(country, node);
}
