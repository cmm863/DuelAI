#include "tile.h"

Tile::Tile(int x, int y, int type) {
	m_c.m_x = x;
	m_c.m_y = y;
	m_type = type;
	m_id = m_iterator;
	m_iterator++;

	return;
}

int Tile::type() {
	return m_type;
}

