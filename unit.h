#ifndef UNIT_H
#define UNIT_H

// Standard library imports
#include <iostream>

// Base class imports
#include "mappable.h"
#include "gameconstants.h"

using namespace std;

class Unit : public Mappable {
private:
	int m_type;
	int m_moves_left;
	int m_player_id;

public:
	Unit(int x = kUndefined, int y = kUndefined, int type = kUndefined, int player_id = kUndefined);
	bool Move(int x, int y);
	int type();
	int moves_left();
	int player_id();
	string DebugString();
};

#endif