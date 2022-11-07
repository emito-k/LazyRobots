#include "WarEngine.h"
#include "Terrain.h"
#include "HumanPlayer.h"
#include <unistd.h>

WarEngine::WarEngine() {
    graph = new Graph();
}

void WarEngine::warStart() {
    createMap();
    createPlayers();

    int turn = -1;
    int index;
    Player* currentPlayer;

    do {
        turn++;
        index = turn%players.size();
        currentPlayer = players.at(index);
        currentPlayer->performTurn();
    }
    while(currentPlayer->getCountry()->isActive());

    std::cout << "The war lasted " << (turn + 1) << " turns. The country that raised the white flag is: ";
    std::cout << currentPlayer->getCountry()->getCountryName();
    std::cout << ". Game Over! Thank you for playing...\n\n";
}

void WarEngine::createPlayers() {
    // create player objects
    std::string name1, name2;
    std::cout << "Create two Players " << std::endl;
    std::cout << "Enter player 1 name: ";
    std::getline(std::cin, name1);
    std::cout << "Enter player 2 name: ";
    std::getline(std::cin, name2);

    players.push_back(new HumanPlayer(name1));
    players.push_back(new HumanPlayer(name2));

    system("clear");
    std::cout << "Creating players..." << std::endl;
    sleep(2);
    system("clear");

    players[0]->getCountry()->setCapitol(graph->getNode("6"));
    players[1]->getCountry()->setCapitol(graph->getNode("0"));
}

void WarEngine::createMap() {
    if(graph == NULL) {
        return;
    }

    const int NODES_ARRAY_SIZE = 12;
    Node** node = new Node*[NODES_ARRAY_SIZE];
    std::string val = "0";

    for(int index = 0; index < NODES_ARRAY_SIZE; index++) {
        node[index] = graph->createNode(val);
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

    delete [] node;
}