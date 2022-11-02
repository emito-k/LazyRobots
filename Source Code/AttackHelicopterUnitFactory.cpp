#include "AttackHelicopterUnitFactory.h"

ArmyUnit *AttackHelicopterUnitFactory::createUnit(std::string nodeName, std::string countryName) const {
    return new AttackHelicopterUnit(nodeName, countryName);
}
