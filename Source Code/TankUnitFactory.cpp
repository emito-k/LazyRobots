#include "TankUnitFactory.h"

ArmyUnit *TankUnitFactory::createUnit(Country* country, Node* node) const {
    return new TankUnit(country, node);
}
