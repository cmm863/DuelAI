//////////////////////////////////////////////////////////////////////
/// @file gamemap.h
/// @author Connor McBride
/// @brief Contains header information for the GameMap class.
//////////////////////////////////////////////////////////////////////

#ifndef GAMEMAP_H
#define GAMEMAP_H

// Standard library imports
#include <iostream>

// Game imports
#include "tile.h"

// Namespaces
using namespace std;

//////////////////////////////////////////////////////////////////////
/// @class GameMap
/// @brief This class holds the map information (height/width) and all
///						of the tiles.
/// @variables
///		Tile** m_map; Currently the game map itself. The multidimensional
///						array of all of the tiles accessible by its x and y
///						m_map[x][y].
///		int m_width; Width of the map.
///		int m_height; Height of the map.
//////////////////////////////////////////////////////////////////////

class GameMap {
private:
	// @private_variables
	Tile** m_map;
	int m_width, m_height;
public:
	// @public_functions
	// @constructors
	GameMap(const int width = kMapWidth, const int height = kMapHeight);
	~GameMap();

	// @getters
	int width();
	int height();
	Tile* GetTileAt(int x, int y);
};

#endif