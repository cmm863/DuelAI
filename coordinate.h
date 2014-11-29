//////////////////////////////////////////////////////////////////////
/// @file coordinate.h
/// @author Connor McBride
/// @brief Contains header information for the coordinate class.
//////////////////////////////////////////////////////////////////////

#ifndef COORDINATE_H
#define COORDINATE_H

//////////////////////////////////////////////////////////////////////
/// @class Coordinate
/// @brief This is a coordinate class or a Point class that keeps an
///           x and a y position.
/// @variables
///   int m_x; The integer x position
///   int m_y; The integer y position
//////////////////////////////////////////////////////////////////////

class Coordinate {
public:
  // @public_variables
  int m_x;
  int m_y;

  // @public_functions
  // @constructors
  Coordinate() : m_x(0), m_y(0) {
  }

  Coordinate(int x, int y) : m_x(x), m_y(y) {
  }

  // @getters
  int x() const;

  int y() const;

  // @overloads
  bool operator<(const Coordinate &c1) const;
};

#endif