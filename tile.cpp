#include "tile.h"

Tile::Tile(int x, int y, int type) {
	m_c.m_x = x;
	m_c.m_y = y;
	m_type = type;
	m_id = m_iterator;
	m_iterator++;
	m_char = '.';

	return;
}

int Tile::type() {
	return m_type;
}

void Tile::set_char(char c) {
	m_char = c;
}

char Tile::get_char() {
	return m_char;
}