#ifndef ATTACK_HELICOPTER_UNIT_H
#define ATTACK_HELICOPTER_UNIT_H
#include "ArmyUnit.h"

class AttackHelicopterUnit : public ArmyUnit{
public:
    /**
    * Sets #_country variable to be @param country and sets the type to be AttackHelicopter
    */
    AttackHelicopterUnit(Country* country);
};


#endif
