#ifndef INFANTRY_UNIT_FACTORY_H
#define INFANTRY_UNIT_FACTORY_H
#include "MilitaryFactory.h"
#include "InfantryUnit.h"

class InfantryUnitFactory : public MilitaryFactory {
public:
    /** Create InfantryUnit object
     * @return InfantryUnit object
     */
    ArmyUnit * createUnit(Country* country, Node* node) const override;
};


#endif
