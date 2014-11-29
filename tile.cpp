//////////////////////////////////////////////////////////////////////
/// @file tile.cpp
/// @author Connor McBride
/// @brief Contains definition information for the tile class.
//////////////////////////////////////////////////////////////////////

#include "tile.h"

// @public_functions
// @constructors
Tile::Tile(int x, int y, int type) {
  m_c.m_x = x;
  m_c.m_y = y;
  m_type = type;
  m_id = m_iterator;
  m_iterator++;
  m_char = '.';

  return;
}

// @getters
int Tile::type() const {
  return m_type;
}

char Tile::get_char() const {
  return m_char;
}