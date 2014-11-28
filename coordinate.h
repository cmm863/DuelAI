#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
public:
  int m_x;
  int m_y;
  // Functions
  Coordinate() : m_x(0), m_y(0) {}
  Coordinate(int x, int y) : m_x(x), m_y(y) {}
  int x();
  int y();
  bool operator<(const Coordinate& c1) const;
};

#endif