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
      // Move them to the right one
      if (!Occupied(u.x() + 1, u.y())) {
        move(u, u.x() + 1, u.y());
      }
    }
  }
  return true;
}

void AI::end() {
  for (Unit &u : units) {
    if (PlayerID() == u.player_id())
      std::cout << u.DebugString() << std::endl;
  }
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
bool AI::InMapBounds(int x, int y) {
  return (x >= 0 && x < kMapWidth && y >= 0 && y < kMapHeight);
}

bool AI::Occupied(int x, int y) {
  if (m_unit_coordinate_index_map.find(Coordinate(x, y)) != m_unit_coordinate_index_map.end()) {
    return true;
  }

  return false;
}

// @game_unique
void AI::spawn(int x, int y, int type) {
  if (InMapBounds(x, y)) {
    if (!Occupied(x, y)) {
      Unit u = Unit(x, y, type, AI::m_player_id);
      units.push_back(u);
      m_unit_id_index_map[u.id()] = units.size() - 1;
      m_unit_coordinate_index_map[u.coordinate()] = units.size() - 1;
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
        std::cout << ' ' << 'x';
      }
    }
    std::cout << std::endl;
  }
  for (int j = 0; j < board.width(); j++) {
    std::cout << "==";
  }
  std::cout << std::endl;
}