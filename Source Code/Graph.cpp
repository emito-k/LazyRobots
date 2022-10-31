#include "Graph.h"

Graph::Graph() = default;

Node *Graph::createNode(std::string nodeName) {
    Node* newNode = new Node(nodeName);
    _nodes.push_back(newNode);
    return newNode;
}

void Graph::printNodes() {
    std::cout << "List of Nodes: " << std::endl;
    int index = 0;
    auto iter = _nodes.begin();
    for(iter; iter != _nodes.end(); iter++){
        std::cout << (*iter)->getNodeName() << " at index " << index++ << std::endl;
    }
}

bool Graph::connectNodes(int nodeA, int nodeB) {
    if(_nodes.at(nodeA)->connectNode(_nodes.at(nodeB)))
        return true;
    return false;
}

bool Graph::disconnectNodes(int nodeA, int nodeB) {
    if(_nodes.at(nodeA)->disconnectNode(_nodes.at(nodeB)))
        return true;
    return false;
}

void Graph::userConnectNodes() {
    printNodes();
    int index1, index2;
    std::cout << "Please enter the indices of nodes you want to connect " << std::endl;
    std::cout << "first index: ";
    std::cin >> index1;
    while (index1 >= _nodes.size()){
        std::cout << "Invalid index, please enter valid index: ";
        std::cin >> index1;
    }
    std::cout << "second index: ";
    std::cin >> index2;
    while (index2 >= _nodes.size()){
        std::cout << "Invalid index, please enter valid index: ";
        std::cin >> index2;
    }
    connectNodes(index1, index2);
}

void Graph::userDisconnectNodes() {
    printNodes();
    int index1, index2;
    std::cout << "Please enter the indices of nodes you want to disconnect " << std::endl;
    std::cout << "first index: ";
    std::cin >> index1;
    while (index1 >= _nodes.size()){
        std::cout << "Invalid index, please enter valid index: ";
        std::cin >> index1;
    }
    std::cout << "second index: ";
    std::cin >> index2;
    while (index2 >= _nodes.size()){
        std::cout << "Invalid index, please enter valid index: ";
        std::cin >> index2;
    }
    disconnectNodes(index1, index2);
}

Node* Graph::getNode(std::string nodeName) {
    auto iter = _nodes.begin();
    for(iter; iter != _nodes.end(); iter++){
        if((*iter)->getNodeName() == nodeName) {
            return *iter;
        }
    }
    return nullptr;
}
