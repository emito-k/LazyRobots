#ifndef NODE_H
#define NODE_H
#include "ArmyUnit.h"
#include "MilitaryFactory.h"
#include "Terrain.h"
#include <vector>
#include <string>
#include <iostream>

class ArmyUnit;
class MilitaryFactory;

class Node {
public:
    /// @param nodeName is the node's name
    Node(std::string nodeName);
    /**set the factory member
     * @param factory
     * @returns current Node
     */
    Node* setFactory(MilitaryFactory* factory);
    /**set the terrain member
     * @param terrain
     * @returns current Node
     */
    Node* setTerrain(Terrain* terrain);
    /** Connect nodes
     * @param newNode is the node that connects with the current node
     * @returns current Node
     */
    Node* connectNode(Node* newNode);
    /** Disconnect nodes
     * @param newNode is the node that disconnect with the current node
     * @returns current Node
     */
    Node* disconnectNode(Node* newNode);
    /// @returns nodeName
    std::string getNodeName();
    /// ! Print nodes
    void printNodes();
    /** Adds the newNode to the list of Nodes
     * @param newNode is the node that is added to the list of nodes
     */
    void addNode(Node* newNode);
    /** Removes the new Node from the list of Nodes
     * @param node is the node that is removed from the list of nodes
     */
    void removeNode(Node* node);
    /// !add an army
    void addArmy(ArmyUnit* armyUnit);
    /// !removes army
    void removeArmy(ArmyUnit* armyUnit);
    /// ! Helper function for getDistanceAt function
    std::vector<Node*> addNeighbours(std::vector<Node*> nodes);
    /**return all the nodes that is a certain distance away from the starting node.
     * @param distance is a certain distance away from the starting node
     * @param nodes is a vector containing the nodes that are a certain distance away from the starting node
     * @returns a vector containing the nodes
     */
    std::vector<Node*> getDistanceAt(int distance, std::vector<Node*> nodes);
    /// @returns occupants
    std::vector<ArmyUnit*> getOccupants();
    /// @returns neighbours
    std::vector<Node*> getNeighbours();
private:
    std::string _nodeName;
    std::vector<Node*> neighbours;
    std::vector<ArmyUnit*> occupants;
    MilitaryFactory* _factory;
    Terrain* _terrain;
};

#endif
