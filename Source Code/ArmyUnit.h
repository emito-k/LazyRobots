#ifndef ARMY_UNIT_H
#define ARMY_UNIT_H
#include "Node.h"
#include "Country.h"
#include <string>

class Node;
class Country;

class ArmyUnit {
public:
    ArmyUnit(double HP, double damagePoints, int travelSpeed, int range, std::string unitType);
    std::string getUnitType();
    void attackUnit(ArmyUnit* enemyUnit);
    void supplyUnit(ArmyUnit* friendlyUnit);
    void getDamaged(double damageInflicted);
private:
    double _healthPoints;
    double _damagePoints;
    int _travelSpeed;
    int _range;
    std::string _unitType;
    Country* country;
    Node* currentNode;
};


#endif
