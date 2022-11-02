#include "ArmyUnit.h"

ArmyUnit::ArmyUnit(double HP, double damagePoints, int travelSpeed, int range, std::string unitType, std::string nodeName, std::string countryName) {
    _healthPoints = HP;
    _damagePoints = damagePoints;
    _travelSpeed = travelSpeed;
    _range = range;
    _unitType = unitType;
    country = new Country(countryName);
    currentNode = new Node(nodeName);

}

std::string ArmyUnit::getUnitType() {
    return _unitType;
}

void ArmyUnit::attackUnit(ArmyUnit *enemyUnit) {
    if(country == enemyUnit->country)
        std::cout << "Friendly fire not tolerated" << std::endl;
    else
        enemyUnit->getDamaged(_damagePoints);
}

void ArmyUnit::getDamaged(double damageInflicted) {
    if(_healthPoints-damageInflicted < 0)
        _healthPoints = 0;
    else
        _healthPoints -= damageInflicted;
    std::cout << country->getCountryName() << "'s " << _unitType << "has been dealt " << damageInflicted << std::endl;
}

void ArmyUnit::supplyUnit(ArmyUnit *friendlyUnit) {
    if(country == friendlyUnit->country){
        friendlyUnit->_healthPoints = _healthPoints * 0.3;
        _healthPoints = _healthPoints - (_healthPoints*0.3);
    }
}
