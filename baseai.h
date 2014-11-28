#ifndef BASEAI_H
#define BASEAI_H

// Standard library imports
#include <vector>
#include <map>

// Game imports
#include "gamemap.h"

class BaseAI {
protected:
	int m_player_id;
	static map<Coordinate, int> m_unit_index_map;
	static vector<Unit> units;
	static GameMap board;
	Unit GetUnitAt(int x, int y);
public:
	static int m_turn_number;
	virtual void init() = 0;
	virtual bool run() = 0;
	virtual void end() = 0;
};


#endif