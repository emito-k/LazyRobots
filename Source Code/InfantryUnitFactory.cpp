#include "InfantryUnitFactory.h"

ArmyUnit *InfantryUnitFactory::createUnit(std::string nodeName, std::string countryName) const {
    return new InfantryUnit(nodeName, countryName);
}
