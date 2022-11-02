#ifndef TANK_UNIT_H
#define TANK_UNIT_H
#include "ArmyUnit.h"

class TankUnit : public ArmyUnit {
public:
    TankUnit(std::string nodeName, std::string countryName);
};


#endif
