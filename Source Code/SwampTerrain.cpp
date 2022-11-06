#include "SwampTerrain.h"
#include "ArmyUnit.h"

SwampTerrain::SwampTerrain() : Terrain("SwampTerrain") {

}

void SwampTerrain::addEffects(ArmyUnit *armyUnit) {
    armyUnit->setDamage(armyUnit->getDamage() - (armyUnit->getDamage()* 0.3));
    armyUnit->setRange(armyUnit->getRange()-1);
}

void SwampTerrain::removeEffects(ArmyUnit *armyUnit) {
    armyUnit->setDamage(armyUnit->getDamage() + (armyUnit->getDamage()* 0.3));
    armyUnit->setRange(armyUnit->getRange()+1);
}
