#ifndef SUPPLY_UNIT_H
#define SUPPLY_UNIT_H
#include "ArmyUnit.h"

class SupplyUnit : public ArmyUnit{
public:
    SupplyUnit(std::string nodeName, std::string countryName);
};

#endif
