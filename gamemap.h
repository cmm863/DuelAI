#ifndef GAMEMAP_H
#define GAMEMAP_H

// Standard library imports
#include <iostream>

// Game imports
#include "tile.h"

// Namespaces
using namespace std;

class GameMap {
private:
	Tile** m_map;
	int m_width, m_height;
public:
	GameMap(const int width = kMapWidth, const int height = kMapHeight);
	~GameMap();
	void DebugString();
	int width();
	int height();
	Tile* GetTileAt(int x, int y);
};

#endif