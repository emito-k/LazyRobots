#include "ForestTerrain.h"
#include "ArmyUnit.h"

ForestTerrain::ForestTerrain() : Terrain("ForestTerrain") {

}

void ForestTerrain::addEffects(ArmyUnit *armyUnit) {
    armyUnit->setDamage(armyUnit->getDamage() - (armyUnit->getDamage()* 0.2));
    armyUnit->setRange(armyUnit->getRange()-1);
}

void ForestTerrain::removeEffects(ArmyUnit *armyUnit) {
    armyUnit->setDamage(armyUnit->getDamage() + (armyUnit->getDamage()* 0.2));
    armyUnit->setRange(armyUnit->getRange()+1);
}
