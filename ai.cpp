//////////////////////////////////////////////////////////////////////
/// @file ai.cpp
/// @author Connor McBride
/// @brief Contains definition information for the AI class.
//////////////////////////////////////////////////////////////////////

#include "ai.h"

// @public_functions
// @constructors
AI::AI(int player_id) {
  m_player_id = player_id;

  return;
}

// @game_runners
void AI::init() {

  return;
}

bool AI::run() {
  // Spawn something
  if (!Occupied(1, 1)) {
    spawn(1, 1);
  }

  // Cycle through units
  for (Unit &u : units) {
    // If they're ours
    if (u.player_id() == PlayerID()) {
      // Create a vector with each direction for the unit
      vector<Coordinate> each_direction;
      each_direction.push_back(Coordinate(u.x() + 1, u.y())); // East
      each_direction.push_back(Coordinate(u.x() - 1, u.y())); // West
      each_direction.push_back(Coordinate(u.x(), u.y() + 1)); // North
      each_direction.push_back(Coordinate(u.x(), u.y() - 1)); // South

      // Move them to the right one
      for(Coordinate c : each_direction) {
        if(!Occupied(c) && InMapBounds(c)) {
          move(u, c);
          break;
        }
      }
    }
  }
  return true;
}

void AI::end() {

  return;
}

// @game_state_getters
int AI::PlayerID() {
  return m_player_id;
}

int AI::TurnNumber() {
  return BaseAI::m_turn_number;
}

// @game_state_booleans
bool AI::Occupied(int x, int y) {
  if (m_unit_coordinate_index_map.find(Coordinate(x, y)) != m_unit_coordinate_index_map.end()) {
    return true;
  }

  return false;
}

bool AI::Occupied(Coordinate c) {
  return Occupied(c.x(), c.y());
}

bool AI::InMapBounds(int x, int y) {
  return (x >= 0 && x < kMapWidth && y >= 0 && y < kMapHeight);
}

bool AI::InMapBounds(Coordinate c) {
  return InMapBounds(c.x(), c.y());
}

// @game_unique
void AI::spawn(int x, int y, int type) {
  if (InMapBounds(x, y)) {
    if (!Occupied(x, y)) {
      Unit u = Unit(x, y, type, AI::m_player_id);
      units.push_back(u);
      m_unit_id_index_map[u.id()] = static_cast<int>(units.size()) - 1;
      m_unit_coordinate_index_map[u.coordinate()] = static_cast<int>(units.size()) - 1;
    } else {
      std::cout << "--Spawn denied at X: " << x << ", Y: " << y << " (Occupied)" << std::endl;
    }
  } else {
    std::cout << "-- Spawn denied at X: " << x << ", Y: " << y << " (Out of Map)" << std::endl;
  }
  return;
}


bool AI::move(Unit &u, int x, int y) {
  if (!Occupied(x, y)) {
    Coordinate temp_coordinate = u.coordinate();
    int index = m_unit_coordinate_index_map[temp_coordinate];
    m_unit_coordinate_index_map.erase(temp_coordinate);
    u.move(x, y);
    m_unit_coordinate_index_map[u.coordinate()] = index;
    return true;
  }
  std::cout << "--Move denied X: " << x << ", Y: " << y << " (Occupied)." << std::endl;
  return false;
}

bool AI::move(Unit &u, Coordinate c) {
  return move(u, c.x(), c.y());
}

// @static_game_unique
void AI::PrintGameMap() {
  for (int j = 0; j < board.width(); j++) {
    std::cout << "==";
  }
  std::cout << std::endl;
  for (int y = board.height() - 1; y >= 0; y--) {
    for (int x = 0; x < board.width(); x++) {
      if (!Occupied(x, y)) {
        std::cout << ' ' << board.GetTileAt(x, y)->get_char();
      } else {
        Unit temp_unit = GetUnitAt(x, y);
        std::cout << ' ' << temp_unit.player_id();
      }
    }
    std::cout << std::endl;
  }
  for (int j = 0; j < board.width(); j++) {
    std::cout << "==";
  }
  std::cout << std::endl;
}