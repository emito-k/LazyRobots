#include "WarEngine.h"
#include "Terrain.h"

WarEngine::WarEngine() {
    graph = new Graph();
}

WarEngine::warStart() {
    createMap();
    createPlayers();

    int turn = -1;
    int index;
    Player* currentPlayer = NULL;

    do {
        turn++;
        index = turn%players.size();
        currentPlayer = players.at(index)->performTurn();
    }
    while(currentPlayer()->getCountry()->isActive());

    std::cout << "The war lasted " << (turn + 1) << " turns. The country that raised the white flag is: ";
    std::cout << currentPlayer()->getCountry()->getCountryName();
    std::cout << "Game Over! Thank you for playing...\n\n";
}

void WarEngine::createPlayers() {
    // create player objects 
}

void WarEngine::createMap() {
    if(graph == NULL) {
        return;
    }
    
    const int NODES_ARRAY_SIZE = 12;
    Node** nodes = new Node*[NODES_ARRAY_SIZE];
    std::string val = "0";

    for(int index = 0; index < NODES_ARRAY_SIZE; index++) {
        nodes[index] = graph->createNode(val);
        val[0]++;
    }

    // Draw example graph 1
    node[0]->connectNode(node[2])->connectNode(node[5])->connectNode(node[4]);
    node[2]->connectNode(node[4])->connectNode(node[3]);
    node[5]->connectNode(node[4])->connectNode(node[1]);
    node[4]->connectNode(node[7]);
    node[3]->connectNode(node[9]);
    node[1]->connectNode(node[8]);
    node[7]->connectNode(node[9])->connectNode(node[8]);
    node[8]->connectNode(node[6]);
    node[9]->connectNode(node[6]);

    node[0]->setFactories(); // factory established
    node[6]->setFactories(); // factory established

    delete [] nodes;
}
