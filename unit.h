//////////////////////////////////////////////////////////////////////
/// @file unit.h
/// @author Connor McBride
/// @brief Contains header information for the Unit class.
//////////////////////////////////////////////////////////////////////

#ifndef UNIT_H
#define UNIT_H

// Standard library imports
#include <iostream>

// Base class imports
#include "mappable.h"
#include "gameconstants.h"

// Namespaces
using namespace std;

//////////////////////////////////////////////////////////////////////
/// @class Unit
/// @base_class Mappable
/// @brief This class holds the Unit object which keeps track of a unit's
///						position, moves, owning player id, and has a movement function.
/// @variables
///		int m_type; The type of unit. @TODO Make use of unit type.
///		int m_moves_left; The amount of moves left for a unit. @TODO Use m_moves_left & set
///		int m_player_id; The id of the player that controls this Unit.
///		@from_base
///			Coordinate m_c;
///			int m_id;
///
/// @functions
///		bool move(int x, int y); Currently just moves to the location mentioned.
///						@TODO Make move() check distance moved & moves_left
///		string DebugString(); Currently submits a string with all variables as tags
///						and values of the variables.
//////////////////////////////////////////////////////////////////////

class Unit : public Mappable {
private:
	// @private_variables
	int m_type;
	int m_moves_left;
	int m_player_id;

public:
	// @public_functions
	// @constructors
	Unit(int x = kUndefined, int y = kUndefined, int type = kUndefined, int player_id = kUndefined);

	// @getters
	int type();
	int moves_left();
	int player_id();

	// @unique
	string DebugString();
	bool move(int x, int y);
};

#endif