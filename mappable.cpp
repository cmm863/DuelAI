//////////////////////////////////////////////////////////////////////
/// @file mappable.cpp
/// @author Connor McBride
/// @brief Contains definition information for the mappable class.
//////////////////////////////////////////////////////////////////////

#include "mappable.h"

// @static_variables
int Mappable::m_iterator = 0;

// @public_functions
// @getters
int Mappable::x() {
  return m_c.x();
}

int Mappable::y() {
  return m_c.y();
}

int Mappable::id() {
  return m_id;
}

Coordinate Mappable::coordinate() {
  return m_c;
}