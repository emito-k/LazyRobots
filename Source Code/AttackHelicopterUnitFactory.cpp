#include "AttackHelicopterUnitFactory.h"

ArmyUnit *AttackHelicopterUnitFactory::createUnit(Country* country) const {
    return new AttackHelicopterUnit(country);
}
