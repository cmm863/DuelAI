//////////////////////////////////////////////////////////////////////
/// @file coordinate.cpp
/// @author Connor McBride
/// @brief Contains definition information for the coordinate class.
//////////////////////////////////////////////////////////////////////

#include "coordinate.h"

// @public_functions
// @getters
int Coordinate::x() {
  return m_x;
}

int Coordinate::y() {
  return m_y;
}

// @overloads
bool Coordinate::operator<(const Coordinate &c1) const {
  if (m_x == c1.m_x) {
    return m_y < c1.m_y;
  }
  return m_x < c1.m_x;
}