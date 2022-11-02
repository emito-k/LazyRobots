#include "AttackHelicopterUnitFactory.h"

ArmyUnit *AttackHelicopterUnitFactory::createUnit(Country* country, Node* node) const {
    return new AttackHelicopterUnit(country, node);
}
