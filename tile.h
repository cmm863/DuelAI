#ifndef TILE_H
#define TILE_H

// Base class imports
#include "mappable.h"

// Game imports
#include "gameconstants.h"
#include "unit.h"

class Tile : public Mappable {
private:
	int m_type;
public:
	Tile(int x = kUndefined, int y = kUndefined, int type = kUndefined);
	int type();
};

#endif