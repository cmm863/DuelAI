//////////////////////////////////////////////////////////////////////
/// @file tile.h
/// @author Connor McBride
/// @brief Contains header information for the tile class.
//////////////////////////////////////////////////////////////////////

#ifndef TILE_H
#define TILE_H

// Base class imports
#include "mappable.h"

// Game imports
#include "gameconstants.h"
#include "unit.h"

//////////////////////////////////////////////////////////////////////
/// @class Tile
/// @base_class Mappable
/// @brief This class represents one tile on the game board.
/// @variables
///		int m_type; This is the type of tile. @TODO Implement Tile types
///		char m_char; This is the char of the tile when printed for map and
///						debugging purposes. Changes with the type.
/// 					@TODO Change char with type
//////////////////////////////////////////////////////////////////////

class Tile : public Mappable {
private:
  // @private_variables
  int m_type;
  char m_char;
public:
  // @public_functions
  // @constructors
  Tile(int x = kUndefined, int y = kUndefined, int type = kUndefined);

  // @getters
  int type();

  char get_char();
};

#endif