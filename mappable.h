//////////////////////////////////////////////////////////////////////
/// @file mappable.h
/// @author Connor McBride
/// @brief Contains header information for the mappable class.
//////////////////////////////////////////////////////////////////////

#ifndef MAPPABLE_H
#define MAPPABLE_H

#include "coordinate.h"

//////////////////////////////////////////////////////////////////////
/// @class Mappable
/// @brief This class is the base class of all mappable objects in the AI.
/// @variables
/// 	Coordinate m_c; This is the coordinate in x, y form of the object in game
/// 	int m_id; This is the id of the the object in the game; UNIQUE to all other mappables
// 		m_iterator; This keeps track of the current id #'s for new mappable objects.
//          			When a new mappable is made, the iterator is increased and the
//    						mappable is given the iterator's current value as an ID.
//////////////////////////////////////////////////////////////////////

class Mappable {
protected:
  // @protected_variables
  Coordinate m_c;
  int m_id;
public:
  // @public_variables
  // @static_variables
  static int m_iterator;

  // @public_functions
  // @getters
  int x() const;

  int y() const;

  int id() const;

  Coordinate coordinate();
};

#endif