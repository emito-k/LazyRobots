#include "ArmyUnit.h"
#include <unistd.h>

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

bool ArmyUnit::printTargets() {
    targets = {};
    if(currentNode != nullptr) {
        std::vector<Node *> nodes;
        if(_range == 0){
            nodes.push_back(currentNode);
        }
        else if (_range == 1) {
            nodes = currentNode->getNodesAtDistance(1, nodes);
        }
        else {
            nodes = currentNode->getNodesAtDistance(2, nodes);
        }
        removeDuplicates(nodes);
        //Get the ArmyUnits occupying the nodes in range
        auto iter2 = nodes.begin();
        for(iter2; iter2 != nodes.end(); iter2++){
            if(*iter2 != NULL){
                std::vector<ArmyUnit*> occupants = (*iter2)->getOccupants();
                auto iter3 = occupants.begin();
                for(iter3; iter3 != occupants.end(); iter3++){
                    if(*iter3 != NULL && !(*iter3)->isAlly(_country) && (*iter3) != this){
                        targets.push_back(*iter3);
                    }
                }
            }
        }

        //Print the targets
        if(targets.empty()) {
            system("clear");
            std::cout << "No targets " << std::endl;
            sleep(2);
            system("clear");
            return false;
        }
        else{
            std::vector<int> options;
            int index = 0;
            std::cout << "Select the army you'd like to attack: " << std::endl;
            std::cout << "Target indices" << std::endl;
            auto iter4 = targets.begin();
            for(iter4; iter4 != targets.end(); iter4++){
                if(*iter4 != NULL && *iter4 != this) {
                    options.push_back(index);
                    std::cout << index++ << ". " << (*iter4)->getUnitType() << std::endl;
                }
            }
            std::cout << ">";
            _country->getPlayer()->getResponse(options);
        }
    }
    return true;
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

Node *ArmyUnit::getCurrentNode() {
    return currentNode;
}

Country *ArmyUnit::getCountry() {
    return _country;
}

std::vector<Node *> ArmyUnit::moveOptions() {
    std::vector<Node *> nodes;

    if(currentNode != nullptr) {
       if (_travelSpeed == 1) {
            nodes = currentNode->getNodesAtDistance(1, nodes);
        }
       else {
            nodes = currentNode->getNodesAtDistance(2, nodes);
        }
        removeDuplicates(nodes);
        auto iter = nodes.begin();
        //Remove the current node from the list of Locations
        for (iter; iter != nodes.end(); iter++) {
            if (*iter == currentNode) {
                iter = nodes.erase(iter);
                break;
            }
        }
    }

    return nodes;
}

void ArmyUnit::setDamage(double damage) {
    _damagePoints = damage;
}

double ArmyUnit::getDamage() const {
    return _damagePoints;
}

void ArmyUnit::setRange(int range) {
    _range = range;
}

int ArmyUnit::getRange() const {
    return _range;
}
//Helper function
void ArmyUnit::removeDuplicates(std::vector<Node *> &v) {
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }
    v.erase(end, v.end());
}