#include <iostream>
#include <vector>
#include "Node.h"


int main() {

    Node** node = new Node*[10];
    for(int i = 0; i < 10; i++){
        node[i] = new Node("node_"+ std::to_string(i));
    }
    node[0]->connectNode(node[2])->connectNode(node[5])->connectNode(node[4]);
    node[2]->connectNode(node[4])->connectNode(node[3]);
    node[5]->connectNode(node[4])->connectNode(node[1]);
    node[4]->connectNode(node[7]);
    node[3]->connectNode(node[9]);
    node[1]->connectNode(node[8]);
    node[7]->connectNode(node[9])->connectNode(node[8]);
    node[8]->connectNode(node[6]);
    node[9]->connectNode(node[6]);

    for(int i = 0; i < 10; i++){
        node[i]->printNodes();
    }

    return 0;
}