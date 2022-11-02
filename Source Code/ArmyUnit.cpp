#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(double HP, double damagePoints, int travelSpeed, int range, std::string unitType, Country* country, Node* node) {
    _healthPoints = HP;
    _damagePoints = damagePoints;
    _travelSpeed = travelSpeed;
    _range = range;
    _unitType = unitType;
    _country = country;
    currentNode = node;

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
    return currentNode->getNodeName();
}
