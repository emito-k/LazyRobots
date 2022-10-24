#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include "Army.h"
#include "Country.h"
#include "Area.h"

// forward declaration
class Army;

// This is a territory that can be claimed by any country
class Node : public Area
{
    public:
        Node(std::string areaName, Terrain* terrainType);
        void attack() override;


        ~Node();
        
    private:
        /* data */

};

#endif