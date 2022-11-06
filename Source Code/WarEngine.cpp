#include "WarEngine.h"
#include "Terrain"

WarEngine::WarEngine() {
    graph = new Graph();
}

WarEngine::warStart() {

}

void WarEngine::createMap() {
    if(graph == NULL) {
        return;
    }

    const int NODES_ARRAY_SIZE = 12;
    Node** nodes = new Node*[NODES_ARRAY_SIZE];
    std::string val = "0";

    for(int index = 0; index < NODES_ARRAY_SIZE; index++) {
        nodes[index] = graph->createNode(val);
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

    delete [] nodes;
}
