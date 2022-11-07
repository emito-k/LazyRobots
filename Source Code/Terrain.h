#ifndef TERRAIN_H
#define TERRAIN_H
#include "string"

class ArmyUnit;

class Terrain {
public:
    
    /**
    * This sets the #terrainType
    */
    Terrain(std::string terrainType);
    virtual void addEffects(ArmyUnit* armyUnit) = 0;
    virtual void removeEffects(ArmyUnit* armyUnit) = 0;
    void getTerrainType() const;
private:
    std::string _terrainType;
};


#endif
