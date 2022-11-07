#include <iostream>
#include "Node.h"
#include <vector>
#include "Graph.h"
#include "WarEngine.h"
//#include "TankUnit.h"
//#include "InfantryUnit.h"
//#include "MilitaryFactory.h"
//#include "SupplyUnitFactory.h"
//#include "AttackHelicopterUnit.h"
//
////NODE CLASS
////Connecting and disconnecting nodes unit testing
//
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

//void testConnectingNodes(){
//    Node* node1 = new Node("node_1");
//    Node* node2 = new Node("node_2");
//    Node* node3 = new Node("node_3");
//    Node* node4 = new Node("node_4");
//
//    node1->connectNode(node2);
//    node1->connectNode(node3);
//    node1->connectNode(node4);
//
//    std::vector<Node*> expected = {node2, node3, node4};
//    std::vector<Node*> actual = node1->getNeighbours();
//
//    TEST(expected, actual, "TEST 1");
//}
//
//void testDisconnectingNodes(){
//    Node* node1 = new Node("node_1");
//    Node* node2 = new Node("node_2");
//    Node* node3 = new Node("node_3");
//    Node* node4 = new Node("node_4");
//
//    node1->connectNode(node2);
//    node1->connectNode(node3);
//    node1->connectNode(node4);
//
//    node1->disconnectNode(node3);
//
//    std::vector<Node*> expected = {node2, node4};
//    std::vector<Node*> actual = node1->getNeighbours();
//
//    TEST(expected, actual, "TEST 2");
//}
//GRAPH CLASS
//Testing if the getNode function in Graph class returns the correct Node

void TEST3(){
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

    TEST(expected, actual, "TEST 4");
}

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
    TEST2(node2, actual, "TEST 3");
}

//GRAPH CLASS : Connecting and Disconnecting Nodes unit test


//// UNIT_ARMY CLASS: testing the AttackEnemy function
//void testAttackEnemy(){
//    Country* country1 = new Country("South Africa");
//    Country* country2 = new Country("England");
//
//    ArmyUnit* unit1 = new AttackHelicopterUnit(country1);
//    ArmyUnit* unit2 = new AttackHelicopterUnit(country1);
//
//    std::cout << "Expected output : " << "Friendly fire not tolerated" << std::endl;
//    std::cout << "Actual output : ";
//    unit1->attackUnit(unit2);
//
//    unit2 = new AttackHelicopterUnit(country2);
//    std::cout << "Expected output : " << "England's AttackHelicopter unit has been dealt 50" << std::endl;
//    std::cout << "Actual output : ";
//    unit1->attackUnit(unit2);
//
//}
//
////ARMY_UNIT CLASS : Test the getTarget() function.
//
//void TEST4(ArmyUnit* expected, ArmyUnit* actual, std::string testName){
//    if(expected == actual)
//        std::cout << testName << " PASSED!!!" <<std::endl;
//    else
//        std::cout << testName << " FAILED!!!" << std::endl;
//}
//
//void testGetTarget(){
//    Graph* graph = new Graph();
//    Node* node0 = graph->createNode("Node 0");
//    Node* node1 = graph->createNode("Node 1");
//    Node* node2 = graph->createNode("Node 2");
//    Node* node3 = graph->createNode("Node 3");
//    Node* node4 = graph->createNode("Node 4");
//    //connect node0 and node 1, node 0 and node 2, node 1 and node3, node 2 and node 4.
//    graph->userConnectNodes();
//    graph->userConnectNodes();
//    graph->userConnectNodes();
//    graph->userConnectNodes();
//
//    Country* country1 = new Country("South Africa");
//    Country* country2 = new Country("England");
//    Country* country3 = new Country("Germany");
//    Country* country4 = new Country("Russia");
//    Country* country5 = new Country("USA");
//
//    ArmyUnit* unit1 = new AttackHelicopterUnit(country1);
//    ArmyUnit* unit2 = new AttackHelicopterUnit(country2);
//    ArmyUnit* unit3 = new InfantryUnit(country3);
//    ArmyUnit* unit4 = new TankUnit(country4);
//    ArmyUnit* unit5 = new SupplyUnit(country5);
//
//    node0->addArmy(unit1);
//    node1->addArmy(unit2);
//    node2->addArmy(unit3);
//    node3->addArmy(unit4);
//    node4->addArmy(unit5);
//
//    std::cout << std::endl;
//    unit1->printTargets();
//    std::cout << std::endl;
//    ArmyUnit* expected = unit4;
//    ArmyUnit* actual = unit1->getTarget(1);
//    TEST4(expected, actual, "TEST 5");
//}

int main() {

//    testConnectingNodes();
//    std::cout << std::endl;
//    testDisconnectingNodes();
//    std::cout << std::endl;
    //testReturnCorrectNode();
    std::cout << std::endl;
    WarEngine* engine = new WarEngine();
    engine->warStart();

    //TEST3();
//    std::cout << std::endl;
//    testAttackEnemy();
//    std::cout << std::endl;
//    testGetTarget();
//    std::cout << std::endl;

//    Node** node = new Node*[10];
//    for(int i = 0; i < 10; i++){
//        node[i] = new Node("node_"+ std::to_string(i));
//    }
//    node[0]->connectNode(node[2])->connectNode(node[5])->connectNode(node[4]);
//    node[2]->connectNode(node[4])->connectNode(node[3]);
//    node[5]->connectNode(node[4])->connectNode(node[1]);
//    node[4]->connectNode(node[7]);
//    node[3]->connectNode(node[9]);
//    node[1]->connectNode(node[8]);
//    node[7]->connectNode(node[9])->connectNode(node[8]);
//    node[8]->connectNode(node[6]);
//    node[9]->connectNode(node[6]);
//
//    for(int i = 0; i < 10; i++){
//        node[i]->printNodes();
//    }

    return 0;
}