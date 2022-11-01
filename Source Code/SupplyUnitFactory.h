#ifndef SUPPLY_UNIT_FACTORY_H
#define SUPPLY_UNIT_FACTORY_H
#include "MilitaryFactory.h"
#include "SupplyUnit.h"

class SupplyUnitFactory : public MilitaryFactory{
public:
    /** Create SupplyUnit object
     * @return SupplyUnit object
     */
    ArmyUnit * createUnit() const override;
};

#endif
