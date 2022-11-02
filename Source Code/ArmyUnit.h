#ifndef ARMY_UNIT_H
#define ARMY_UNIT_H
#include "Node.h"
#include "Country.h"
#include <string>

class Node;
class Country;

class ArmyUnit {
public:
    /** @param HP is the healthPoints for the ArmyUnit
    * @param damagePoints is the damage the armyUnit inflicts
    * @param travelSpeed is the number of nodes the unit can move per turn
    * @param range is how many nodes away the unit can attack
     * @param unitType is the type of unit
    */
    ArmyUnit(double HP, double damagePoints, int travelSpeed, int range, std::string unitType, Country* country, Node* node);
    /// @returns the unitType
    std::string getUnitType();
    /** The current army attack the passed in armyUnit, lowering their health points
     * @param enemyUnit is the armyUnit that the current army attack
     */
    void attackUnit(ArmyUnit* enemyUnit);
    /**Is one army giving some of its health to the passed in army
     * @param friendlyUnit is the army that the current army gives its health to
     */
    void supplyUnit(ArmyUnit* friendlyUnit);
    /** Decreases the army's health by the passed in damage amount
     * @param damageInflicted is the damage inflicted by the enemy
     */
    void getDamaged(double damageInflicted);
    /// @returns currentNode's location
    std::string getCurrentLocationName();
private:
    double _healthPoints;
    double _damagePoints;
    int _travelSpeed;
    int _range;
    std::string _unitType;
    Country* _country;
    Node* currentNode;
};


#endif
