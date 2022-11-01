#include "AttackHelicopterUnitFactory.h"

ArmyUnit *AttackHelicopterUnitFactory::createUnit() const {
    return new AttackHelicopterUnit();
}
