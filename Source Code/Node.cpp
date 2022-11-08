#include "Node.h"
#include "InfantryUnitFactory.h"
#include "TankUnitFactory.h"
#include "AttackHelicopterUnitFactory.h"
#include "SupplyUnitFactory.h"

Node::Node(std::string nodeName) {
    _nodeName = nodeName;
}

Node *Node::setFactories() {
    _factories.push_back(new InfantryUnitFactory());
    _factories.push_back(new TankUnitFactory());
    _factories.push_back(new AttackHelicopterUnitFactory());
    _factories.push_back(new SupplyUnitFactory());
    return this;
}

MilitaryFactory *Node::getFactory(int index) {
    if(index >= _factories.size())
        return nullptr;
    return _factories.at(index);
}

Node *Node::setTerrain(Terrain *terrain) {
    _terrain = terrain;
    return this;
}

Node *Node::connectNode(Node *newNode) {
    this->addNode(newNode);
    newNode->addNode(this);
    return this;
}

Node *Node::disconnectNode(Node *newNode) {
    this->removeNode(newNode);
    newNode->removeNode(this);
    return this;
}

void Node::addArmy(ArmyUnit *armyUnit) {
    if(armyUnit->getCurrentNode() != nullptr)
        armyUnit->getCurrentNode()->removeArmy(armyUnit);

    occupants.push_back(armyUnit);

    armyUnit->setNode(this);

    double damage = armyUnit->getDamage();

    _terrain->addEffects(armyUnit);

    if(_terrain->getTerrainType() == "PlainTerrain") {
        std::cout << _terrain->getTerrainType() << " doesn't affect the army" << std::endl;
        return;
    }
    std::cout << armyUnit->getCountry()->getCountryName() << " " << armyUnit->getUnitType() << " has entered "
    << getNodeName() << " and the " << _terrain->getTerrainType() << " has decreased their damage from " << damage
    << " to " << armyUnit->getDamage() << std::endl;
}

void Node::removeArmy(ArmyUnit *armyUnit) {
    _terrain->removeEffects(armyUnit);
    auto iter = occupants.begin();
    for(iter; iter != occupants.end(); iter++){
        if(*iter == armyUnit) {
            iter = occupants.erase(iter);
            break;
        }
    }
    armyUnit->setNode(nullptr);
}

std::string Node::getNodeName() {
    return _nodeName;
}

void Node::printNodes() {
    std::cout << "List of neighbours for " << getNodeName() << std::endl;
    auto iter = neighbours.begin();
    for(iter; iter != neighbours.end(); iter++){
        if(*iter != NULL) {
            std::cout << (*iter)->getNodeName() << std::endl;
        }
    }
}

void Node::addNode(Node *newNode) {
    neighbours.push_back(newNode);
}

void Node::removeNode(Node* node){
    auto iter = neighbours.begin();
    for(iter; iter != neighbours.end(); iter++){
        if(*iter == node) {
            iter = neighbours.erase(iter);
            break;
        }
    }
}

std::vector<Node*> Node::getNodesAtDistance(int distance, std::vector<Node*> nodes) {
    if(distance == 1){
        std::vector<Node*> temp = addNeighbours(nodes);
        auto iter = temp.begin();
        for(iter; iter != temp.end(); iter++){
            if(*iter != NULL) {
                nodes.push_back((*iter));
            }
        }
    }
    else{
        auto iter = neighbours.begin();
        std::vector<Node*> temp = addNeighbours(nodes);
        auto iter2 = temp.begin();
        for(iter2; iter2 != temp.end(); iter2++){
            if(*iter2 != NULL) {
                nodes.push_back((*iter2));
            }
        }
        for(iter; iter != neighbours.end(); iter++){
            if(*iter != NULL) {
                std::vector<Node*> t;
                std::vector<Node*> temp2 = (*iter)->getNodesAtDistance(1, t);
                auto iter3 = temp2.begin();
                for(iter3; iter3 != temp2.end(); iter3++){
                    if(*iter3 != NULL) {
                        nodes.push_back((*iter3));
                    }
                }
            }
        }
    }
    return nodes;
}

std::vector<ArmyUnit *> Node::getOccupants() {
    return occupants;
}

std::vector<Node *> Node::getNeighbours() {
    return neighbours;
}

//Helper function
std::vector<Node*> Node::addNeighbours(std::vector<Node*> nodes){
    auto iter = neighbours.begin();
    for(iter; iter != neighbours.end(); iter++){
        if(*iter != NULL) {
            nodes.push_back((*iter));
        }
    }
    return nodes;
}
