#ifndef ATTACK_HELICOPTER_UNIT_FACTORY_H
#define ATTACK_HELICOPTER_UNIT_FACTORY_H
#include "MilitaryFactory.h"
#include "AttackHelicopterUnit.h"

class AttackHelicopterUnitFactory : public MilitaryFactory{
public:
    ArmyUnit * createUnit() const override;
};


#endif
