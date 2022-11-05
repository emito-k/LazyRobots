#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(double HP, double damagePoints, int travelSpeed, int range, std::string unitType, Country* country) {
    _healthPoints = HP;
    _damagePoints = damagePoints;
    _travelSpeed = travelSpeed;
    _range = range;
    _unitType = unitType;
    _country = country;
}

std::string ArmyUnit::getUnitType() {
    return _unitType;
}

void ArmyUnit::attackUnit(ArmyUnit *enemyUnit) {
    if(_country == enemyUnit->_country)
        std::cout << "Friendly fire not tolerated" << std::endl;
    else
        enemyUnit->getDamaged(_damagePoints);
}

void ArmyUnit::getDamaged(double damageInflicted) {
    if(_healthPoints-damageInflicted < 0)
        _healthPoints = 0;
    else
        _healthPoints -= damageInflicted;
    std::cout << _country->getCountryName() << "'s " << _unitType << " unit has been dealt " << damageInflicted << std::endl;
}

void ArmyUnit::supplyUnit(ArmyUnit *friendlyUnit) {
    if(_country == friendlyUnit->_country){
        friendlyUnit->_healthPoints = _healthPoints * 0.3;
        _healthPoints = _healthPoints - (_healthPoints*0.3);
    }
}

std::string ArmyUnit::getCurrentLocationName() {
    if(currentNode != nullptr)
        return currentNode->getNodeName();
    return "";
}

void ArmyUnit::printTargets() {
    if(currentNode != nullptr) {
        std::vector<Node *> nodes;
        if (_range == 1) {
            nodes = currentNode->getDistanceAt(1, nodes);
        } else {
            nodes = currentNode->getDistanceAt(2, nodes);
        }
        removeDuplicates(nodes);
        auto iter = nodes.begin();
        //Remove the current node from the list of targets
        for (iter; iter != nodes.end(); iter++) {
            if (*iter == currentNode) {
                iter = nodes.erase(iter);
                break;
            }
        }
        //Get the ArmyUnits occupying the nodes in range
        auto iter2 = nodes.begin();
        for(iter2; iter2 != nodes.end(); iter2++){
            if(*iter2 != NULL){
                std::vector<ArmyUnit*> occupants = (*iter2)->getOccupants();
                auto iter3 = occupants.begin();
                for(iter3; iter3 != occupants.end(); iter3++){
                    if(*iter3 != NULL && !(*iter3)->isAlly(_country)){
                        targets.push_back(*iter3);
                    }
                }
            }
        }

        //Print the targets
        int index = 0;
        std::cout << "List of Targets in range" << std::endl;
        auto iter4 = targets.begin();
        for(iter4; iter4 != targets.end(); iter4++){
            if(*iter4 != NULL)
                std::cout << (*iter4)->getUnitType() << " Unit at " << (*iter4)->currentNode->getNodeName() << " at index " << index++ << std::endl;
        }
    }
}

ArmyUnit *ArmyUnit::getTarget(int index) {
    if(index >= targets.size())
        return nullptr;
    return targets.at(index);
}

bool ArmyUnit::isAlly(Country *country) {
    if(_country == country)
        return true;
    return false;
}

void ArmyUnit::setNode(Node *node) {
    currentNode = node;
}
//Helper function
void ArmyUnit::removeDuplicates(std::vector<Node *> &v) {
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
    v.erase(end, v.end());
}
