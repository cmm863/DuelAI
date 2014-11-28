#ifndef BASEAI_H
#define BASEAI_H

// Standard library imports
#include <vector>

// Game imports
#include "gamemap.h"

class BaseAI {
protected:
	int m_player_id;
public:
	static vector<Unit> units;
	static GameMap board;
	static int m_turn_number;
	virtual void init() = 0;
	virtual bool run() = 0;
	virtual void end() = 0;
};


#endif