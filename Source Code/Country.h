#ifndef COUNTRY_H
#define COUNTRY_H
#include "Node.h"
#include <string>
#include <vector>
#include "ArmyUnit.h"

class ArmyUnit;
class Node;

class Country {
private:
    Node* capital;
    std::vector<ArmyUnit*> armies;
    std::string countryName;
    int money;
};

#endif
