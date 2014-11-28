//////////////////////////////////////////////////////////////////////
/// @file ai.h
/// @author Connor McBride
/// @brief Contains header information for the AI class.
//////////////////////////////////////////////////////////////////////

#ifndef AI_H
#define AI_H

// Base class includes
#include "baseai.h"

//////////////////////////////////////////////////////////////////////
/// @class AI
/// @base_class BaseAI
/// @brief This class holds the information most available to the player.
///						This includes their programmable init(), run(), and end()
///						functions and their functions that allow them to access the
///						game state and objects in the game.
/// @variables
///		@base_variables
///			static map<Coordinate, int> m_unit_coordinate_index_map;
///			static vector<Unit> units;
///			static GameMap board;
///			static int m_turn_number;
//////////////////////////////////////////////////////////////////////

class AI : public BaseAI {
private:
	// @private_functions
	// @game_state_getters
	int PlayerID();
	int TurnNumber();

	// @game_state_booleans
	static bool Occupied(int x, int y);
	bool InMapBounds(int x, int y);

	// @game_unique
	void spawn(int x = kUndefined, int y = kUndefined, int type = kUndefined);
	bool move(Unit& u, int x, int y);
public:
	// @public_functions
	// @constructors
	AI(int player_id);

	// @game_runners
	void init();
	bool run();
	void end();

	// @static_game_unique
	static void PrintGameMap();
};



#endif