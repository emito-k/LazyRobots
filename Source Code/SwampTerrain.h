#ifndef SWAMP_TERRAIN_H
#define SWAMP_TERRAIN_H
#include "Terrain.h"

class SwampTerrain : public Terrain{
public:SwampTerrain();
    void addEffects(ArmyUnit *armyUnit) override;
    void removeEffects(ArmyUnit *armyUnit) override;
};


#endif
