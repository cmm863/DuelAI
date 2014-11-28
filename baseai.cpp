//////////////////////////////////////////////////////////////////////
/// @file baseai.cpp
/// @author Connor McBride
/// @brief Contains definition information for the BaseAI class.
//////////////////////////////////////////////////////////////////////

#include "baseai.h"

// @protected_static_variables
map<Coordinate, int> BaseAI::m_unit_coordinate_index_map = map<Coordinate, int>();
map<int, int> BaseAI::m_unit_id_index_map;
vector<Unit> BaseAI::units = vector<Unit>();
GameMap BaseAI::board = GameMap();

// @public_static_variables
int BaseAI::m_turn_number = 0;

// @protected_functions
// @protected_getters
Unit BaseAI::GetUnitAt(int x, int y) {
  return units[m_unit_coordinate_index_map.find(Coordinate(x, y))->second];
}

Unit BaseAI::GetUnitFromID(int x) {
  return units[m_unit_id_index_map.find(x)->second];
}