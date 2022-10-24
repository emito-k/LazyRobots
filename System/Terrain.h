#ifndef TERRAIN_H
#define TERRAIN_H

// #include <vector>
#include <string>

class Terrain {
    public:
        Terrain();
        virtual std::string getTerrainName() = 0;
        // virtual std::vector<Army*> allowedUnits();
};

class PlainTerrain : public Terrain {
    public:
        PlainTerrain();

        std::string getTerrainName() {
            return "Plain Terrain";
        }
};

#endif