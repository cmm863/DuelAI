//////////////////////////////////////////////////////////////////////
/// @file unit.cpp
/// @author Connor McBride
/// @brief Contains definition information for the Unit class.
//////////////////////////////////////////////////////////////////////

#include "unit.h"

// @public_functions
// @constructors
Unit::Unit(int x, int y, int type, int player_id) {
  m_c.m_x = x;
  m_c.m_y = y;
  m_type = type;
  m_player_id = player_id;
  m_moves_left = 0;
  m_id = Mappable::m_iterator;
  Mappable::m_iterator++;

  return;
}

// @getters
int Unit::type() {
  return m_type;
}

int Unit::moves_left() {
  return m_moves_left;
}

int Unit::player_id() const {
  return m_player_id;
}

// @unique
string Unit::DebugString() {
  // Initialize response
  string response = "Unit {\n";

  // Build the string
  response += "\tPlayer: " + to_string(m_player_id) + '\n';
  response += "\tID: " + to_string(m_id) + '\n';
  response += "\tx: " + to_string(m_c.m_x) + '\n';
  response += "\ty: " + to_string(m_c.m_y) + '\n';
  response += "\ttype: " + to_string(m_type) + '\n';
  response += "\tmoves_left: " + to_string(m_moves_left) + '\n';
  response += '}';

  return response;
}

bool Unit::move(int x, int y) {
  m_c = Coordinate(x, y);

  return true;
}
