#include "Node.h"

Node::Node(std::string nodeName) {
    _nodeName = nodeName;
}

Node *Node::setFactory(MilitaryFactory *factory) {
    _factory = factory;
    return this;
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

std::string Node::getNodeName() {
    return _nodeName;
}
