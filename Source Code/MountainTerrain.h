#ifndef MOUNTAIN_TERRAIN_H
#define MOUNTAIN_TERRAIN_H
#include "Terrain.h"

class MountainTerrain : public Terrain{
public:
    MountainTerrain();
    void addEffects(ArmyUnit *armyUnit) override;
    void removeEffects(ArmyUnit *armyUnit) override;
};


#endif
