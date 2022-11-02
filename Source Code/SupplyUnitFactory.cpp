#include "SupplyUnitFactory.h"

ArmyUnit *SupplyUnitFactory::createUnit(Country* country, Node* node) const {
    return new SupplyUnit(country, node);
}