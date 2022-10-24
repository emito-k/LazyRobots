#ifndef AREA_H
#define AREA_H

#include "Terrain.h"

class Area {
    public:
        Area(std::string areaName, Terrain* terrainType);
        virtual void attack() = 0; // important method to start fighting

        std::string getName() {
            return areaName;
        }

        Terrain* getTerrain() {
            return terrainType;
        }
    
    private:
        std::string areaName;
        Terrain* terrainType;
};

#endif