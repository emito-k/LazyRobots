#include <iostream>
#include "Node.h"
#include <vector>
#include "Graph.h"

void TEST(std::vector<Node*> expected, std::vector<Node*> actual, std::string testName){
    if(expected.size() == actual.size()){
        auto iter = expected.begin();
        auto iter2 = actual.begin();
        for(iter, iter2; iter != expected.end(); iter++, iter2++){
            if((*iter) != (*iter2)){
                std::cout << testName << " FAILED!!!" << std::endl;
                std::cout << "Expected " << (*iter)->getNodeName() << " but was " << (*iter2)->getNodeName() << std::endl;
                return;
            }
        }
        std::cout << testName << " PASSED!!!" << std::endl;
    }
    else{
        std::cout << testName << " FAILED!!!" << std::endl;
        std::cout << "Have different size. " << "Expected size " << expected.size() << " but was " << actual.size();
    }
}

//GRAPH CLASS
//Testing if the userConnectNodes connect the nodes correctly

void testUserConnectNodes(){
    Graph* graph = new Graph();
    Node* node0 = graph->createNode("Node 0");
    Node* node1 = graph->createNode("Node 1");
    Node* node2 = graph->createNode("Node 2");
    Node* node3 = graph->createNode("Node 3");
    Node* node4 = graph->createNode("Node 4");
    //connect node0 and node 1, node 0 and node 2, node 1 and node3, node 2 and node 4.
    graph->userConnectNodes();
    graph->userConnectNodes();
    graph->userConnectNodes();
    graph->userConnectNodes();
    std::vector<Node*> expected = {node1, node2};
    std::vector<Node*> actual = node0->getNeighbours();

    TEST(expected, actual, "TEST 2");
}

//GRAPH CLASS
//Testing if the getNode function in Graph class returns the correct Node

void TEST2(Node* expected, Node* actual, std::string testName){
    if(expected == actual)
        std::cout << testName << " PASSED!!!" <<std::endl;
    else{
        std::cout << testName << " FAILED!!! ( Expected " << expected->getNodeName() << " but was " << actual->getNodeName() << std::endl;
    }
}

void testReturnCorrectNode(){
    auto* graph = new Graph();
    Node* node0 = graph->createNode("Node 0");
    Node* node1 = graph->createNode("Node 1");
    Node* node2 = graph->createNode("Node 2");
    Node* node3 = graph->createNode("Node 3");
    Node* node4 = graph->createNode("Node 4");

    Node* actual = graph->getNode("Node 2");
    TEST2(node2, actual, "TEST 1");
}

int main() {


    testReturnCorrectNode();
    std::cout << std::endl;
    testUserConnectNodes();

    return 0;
}