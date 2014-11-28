//////////////////////////////////////////////////////////////////////
/// @file baseai.h
/// @author Connor McBride
/// @brief Contains header information for the BaseAI class.
//////////////////////////////////////////////////////////////////////

#ifndef BASEAI_H
#define BASEAI_H

// Standard library imports
#include <vector>
#include <map>

// Game imports
#include "gamemap.h"

//////////////////////////////////////////////////////////////////////
/// @class BaseAI
/// @brief This class holds the base information for the AI class. This
///						includes the unit/index mappings, the game board, the vector
///						of units, and the player_id for that player's ai.
/// @variables
///		int m_player_id; This is the id of the player for this AI instance.
///		static map<Coordinate, int> m_unit_coordinate_index_map; This is a map from
///						each Coordinate to each unit's index in the units vector.
///		static map<int, int> m_unit_id_index_map; This is the map from a Unit's
///						id to it's index in the units vector.
///		static vector<Unit> units; This is the vector for all units in the game.
///						This persists across each player's AI to the other player's.
///		static GameMap board; This is the board. Persists across all AI's.
///						@TODO Make game board a vector if easier.
///		static int m_turn_number; Keeps track of the number of turns that the
///						game has been going on.
//////////////////////////////////////////////////////////////////////

class BaseAI {
protected:
  // @protected_variables
  int m_player_id;

  // @protected_static_variables
  static map<Coordinate, int> m_unit_coordinate_index_map;
  static map<int, int> m_unit_id_index_map;
  static vector<Unit> units;
  static GameMap board;

  // @protected_functions
  // @protected_getters
  static Unit GetUnitAt(int x, int y);

  Unit GetUnitFromID(int x);

public:
  // @public_variables
  // @public_static_variables
  static int m_turn_number;

  // @public_functions
  // @abstract_functions
  virtual void init() = 0;

  virtual bool run() = 0;

  virtual void end() = 0;
};


#endif