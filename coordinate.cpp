#include "coordinate.h"

int Coordinate::x() {
  return m_x;
}

int Coordinate::y() {
  return m_y;
}

bool Coordinate::operator<(const Coordinate& c1) const {
  if(m_x == c1.m_x) {
    return m_y < c1.m_y;
  } else if (m_x < c1.m_x) {
    return true;
  } else {
      return m_x < c1.m_y;
  }
}