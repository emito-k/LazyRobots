#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include <iostream>

class Graph {
public:
    Graph();
    Node* createNode(std::string nodeName);
    void printNodes();
    void userConnectNodes();
    void userDisconnectNodes();
    bool connectNodes(int nodeA, int nodeB);
    bool disconnectNodes(int nodeA, int nodeB);
    Node* getNode(std::string nodeName);

private:
    std::vector<Node*> _nodes;
    std::vector<Terrain*> _terrains;
};

#endif
