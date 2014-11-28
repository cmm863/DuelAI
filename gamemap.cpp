#include "gamemap.h"

GameMap::GameMap(const int width, const int height) {
	m_width = width;
	m_height = height;

	// Allocate the memory
	m_map = new Tile*[width];
	for(int i = 0; i < width; i++) {
		m_map[i] = new Tile[height];
	}

	// Set the tile information
	for(int x = 0; x < width; x++) {
		for(int y = 0; y < height; y++) {
			m_map[x][y] = Tile(x, y);
		}
	}

	return;
}

GameMap::~GameMap() {
	for(int i = 0; i < m_width; i++) {
		delete [] m_map[i];
	}
	delete [] m_map;
}

void GameMap::DebugString() {
	for(int y = m_height-1; y >= 0; y--) {
		for(int x = 0; x < m_width; x++) {
			cout << " .";
		}
		cout << endl;
	}

	return;
}

Tile* GameMap::GetTileAt(int x, int y) {
	return &m_map[x][y];
}

int GameMap::width() {
	return m_width;
}

int GameMap::height() {
	return m_height;
}