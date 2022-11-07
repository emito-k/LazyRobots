#ifndef ARMY_UNIT_H
#define ARMY_UNIT_H
#include "Node.h"
#include "Country.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

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
    ArmyUnit(double HP, double damagePoints, int travelSpeed, int range, std::string unitType, Country* country);
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
    /// !prints all the targets the army can attack
    void printTargets();
    /// !Sets the currentNode member
    void setNode(Node* node);
    /// @returns target
    ArmyUnit* getTarget(int index);
    bool isAlly(Country* country);
    /** Helper function, removes duplicates from the node vector
 * @param v is a vector containing nodes
 */
    void removeDuplicates(std::vector<Node*> &v);
    Node* getCurrentNode();
    Country* getCountry();
    std::vector<Node*> moveOptions();
    void setDamage(double damage);
    double getDamage() const;
    void setRange(int range);
    int getRange() const;
private:
    double _healthPoints;
    double _damagePoints;
    int _travelSpeed;
    int _range;
    std::string _unitType;
    Country* _country;
    Node* currentNode;
    std::vector<ArmyUnit*> targets;
};


#endif
