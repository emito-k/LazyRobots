#include "TankUnitFactory.h"

ArmyUnit *TankUnitFactory::createUnit(std::string nodeName, std::string countryName) const {
    return new TankUnit(nodeName, countryName);
}
