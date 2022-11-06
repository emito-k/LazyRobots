#ifndef TERRAIN_H
#define TERRAIN_H
#include "string"

class ArmyUnit;

class Terrain {
public:
    Terrain(std::string terrainType);
    virtual void addEffects(ArmyUnit* armyUnit) = 0;
    virtual void removeEffects(ArmyUnit* armyUnit) = 0;
private:
    std::string _terrainType;
};


#endif
