#ifndef PLAIN_TERRAIN_H
#define PLAIN_TERRAIN_H
#include "Terrain.h"

class PlainTerrain : public Terrain{
public:
    PlainTerrain();
    void addEffects(ArmyUnit *armyUnit) override;
    void removeEffects(ArmyUnit *armyUnit) override;
};


#endif
