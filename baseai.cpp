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
vector<Tile> BaseAI::tiles = [] {
  vector<Tile> temp = vector<Tile>();
  for(int i = 0; i < kMapHeight; i++) {
    for (int j = 0; j < kMapWidth; j++) {
      temp.push_back(Tile(j, i));
    }
  }
  return temp;
} ();

// @public_static_variables
int BaseAI::m_turn_number = 0;

// @protected_functions
// @protected_getters
Unit BaseAI::GetUnitAt(int x, int y) {
  return units[m_unit_coordinate_index_map.find(Coordinate(x, y))->second];
}

Tile BaseAI::GetTileAt(int x, int y) {
  return tiles[(x + kMapHeight) + (y * kMapWidth)];
}

Unit BaseAI::GetUnitFromID(int x) {
  return units[m_unit_id_index_map.find(x)->second];
}

int BaseAI::MapHeight() {
  return kMapHeight;
}

int BaseAI::MapWidth() {
  return kMapWidth;
}