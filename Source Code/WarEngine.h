#ifndef WARENGINE_H
#define WARENGINE_H

#include <string>
#include <vector>
#include "Graph.h"
#include "Player.h"

class WarEngine {
    public:
        WarEngine();
        void warStart();
        void createMap();
        void createPlayers();

    private:
        Graph *graph;
        std::vector<Player*> players;
};

#endif