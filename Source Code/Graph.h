#ifndef GRAPH_H
#define GRAPH_H
#include "Node.h"
#include <iostream>

class Graph {
public:
    Graph();
    /**Creates new node
     * @param nodeName is used to create the new Node
     * @returns the new node created
     */
    Node* createNode(std::string nodeName);
    /// ! Print out the list of nodes along with their indices
    void printNodes();
    /// ! Ask the user which two indices it wants to connect
    void userConnectNodes();
    /// ! Ask the user which two indices it wants to disconnect
    void userDisconnectNodes();
    /** Connect two nodes
     * @param nodeA is the index of the first node
     * @param nodeB is the index of the second node
     * @returs the either true or false depending on whether the nodes were connected or not
     */
    bool connectNodes(int nodeA, int nodeB);
    /** Disconnect two nodes
     * @param nodeA is the index of the first node
     * @param nodeB is the index of the second node
     * @returs the either true or false depending on whether the nodes were disconnected or not
     */
    bool disconnectNodes(int nodeA, int nodeB);
    /**
     * @param nodeName is a string name of the node we want to return
     * @returns a node with the name
     */
    Node* getNode(std::string nodeName);

private:
    /// ! This is the list of Nodes
    std::vector<Node*> _nodes;
    std::vector<Terrain*> _terrains;
};

#endif
