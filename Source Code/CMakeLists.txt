cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 23)

add_executable(Project main.cpp Node.cpp Node.h ArmyUnit.cpp ArmyUnit.h Country.cpp Country.h Graph.cpp Graph.h MilitaryFactory.cpp MilitaryFactory.h Terrain.cpp Terrain.h InfantryUnit.cpp InfantryUnit.h TankUnit.cpp TankUnit.h AttackHelicopterUnit.cpp AttackHelicopterUnit.h SupplyUnit.cpp SupplyUnit.h InfantryUnitFactory.cpp InfantryUnitFactory.h TankUnitFactory.cpp TankUnitFactory.h AttackHelicopterUnitFactory.cpp AttackHelicopterUnitFactory.h SupplyUnitFactory.cpp SupplyUnitFactory.h MountainTerrain.cpp MountainTerrain.h PlainTerrain.cpp PlainTerrain.h ForestTerrain.cpp ForestTerrain.h SwampTerrain.cpp SwampTerrain.h Flag.cpp Flag.h ArmyAttackCommand.cpp ArmyAttackCommand.h PlayerCommand.cpp PlayerCommand.h config.h CreateArmyCommand.cpp CreateArmyCommand.h MoveArmyCommand.cpp MoveArmyCommand.h ComputerPlayer.cpp ComputerPlayer.h Player.cpp Player.h SupplyArmyCommand.cpp SupplyArmyCommand.h SurrenderCommand.cpp SurrenderCommand.h FlagState.cpp FlagState.h WhiteFlagState.cpp WhiteFlagState.h HomeFlagState.cpp HomeFlagState.h HumanPlayer.cpp HumanPlayer.h WarEngine.cpp WarEngine.h)
