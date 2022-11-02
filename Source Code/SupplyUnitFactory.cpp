#include "SupplyUnitFactory.h"

ArmyUnit *SupplyUnitFactory::createUnit(std::string nodeName, std::string countryName) const {
    return new SupplyUnit(nodeName, countryName);
}