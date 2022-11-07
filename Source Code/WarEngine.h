#ifndef WARENGINE_H
#define WARENGINE_H

#include <string>
#include <vector>
#include "Graph.h"
#include "Player.h"

class WarEngine {
public:
    /**
    * Instantiates the #graph variable
    */
    WarEngine();
    /**
    * This is the main war loop for the program
    */
    void warStart();
    /**
    * This creates a series of connect nodes to make a graph which is the map
    */
    void createMap();
    
    /**
    * This function creates the Player objects that wiil be playing the game
    */
    void createPlayers();

private:
    Graph *graph;
    std::vector<Player*> players;
};

#endif
