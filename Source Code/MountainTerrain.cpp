#include "MountainTerrain.h"
#include "ArmyUnit.h"

MountainTerrain::MountainTerrain() : Terrain("MountainTerrain") {

}

void MountainTerrain::addEffects(ArmyUnit *armyUnit) {
    armyUnit->setDamage(armyUnit->getDamage() - (armyUnit->getDamage()* 0.1));
}

void MountainTerrain::removeEffects(ArmyUnit *armyUnit) {
    armyUnit->setDamage(armyUnit->getDamage() + (armyUnit->getDamage()* 0.1));
}
