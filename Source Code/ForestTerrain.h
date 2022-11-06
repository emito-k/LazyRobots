#ifndef FOREST_TERRAIN_H
#define FOREST_TERRAIN_H
#include "Terrain.h"

class ForestTerrain : public Terrain{
public:
    ForestTerrain();
    void addEffects(ArmyUnit *armyUnit) override;
    void removeEffects(ArmyUnit *armyUnit) override;
};


#endif
