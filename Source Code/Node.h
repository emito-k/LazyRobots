#ifndef NODE_H
#define NODE_H
#include "ArmyUnit.h"
#include "MilitaryFactory.h"
#include "Terrain.h"
#include <vector>
#include <string>
#include <iostream>

class ArmyUnit;

class Node {
public:
    Node(std::string nodeName);
    Node* setFactory(MilitaryFactory* factory);
    Node* setTerrain(Terrain* terrain);
    Node* connectNode(Node* newNode);
    Node* disconnectNode(Node* newNode);
    std::string getNodeName();
    void addNode(Node* newNode);
    void removeNode(Node* node);
private:
    std::string _nodeName;
    std::vector<Node*> neighbours;
    std::vector<ArmyUnit*> occupants;
    MilitaryFactory* _factory;
    Terrain* _terrain;
};

#endif
