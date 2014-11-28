#include "baseai.h"

vector<Unit> BaseAI::units = vector<Unit>();

GameMap BaseAI::board = GameMap();

int BaseAI::m_turn_number = 0;

map<Coordinate, int> BaseAI::m_unit_index_map = map<Coordinate, int>();

Unit BaseAI::GetUnitAt(int x, int y) {
  return units[m_unit_index_map.find(Coordinate(x,y))->second];
}