#include "gamestatehandler.h"

void GameStateHandler::SerializeGameState(const vector<Tile> map, const vector<Unit> units, int turn_number, int id_iterator) {
  ProtoHandler ph = ProtoHandler();
  ProtoGameState::Turn game_turn;
  ProtoGameState::Unit * proto_unit = nullptr;
  ProtoGameState::Mappable * proto_mappable = nullptr;
  ProtoGameState::Coordinate * proto_coordinate = nullptr;
  ProtoGameState::Tile * proto_tile = nullptr;

  // Load the units
  for(const Unit &u : units) {
    // Initialize proto classes
    proto_unit = game_turn.add_units();
    proto_mappable = proto_unit->mutable_m();
    proto_coordinate = proto_mappable->mutable_c();

    // Set Coordinate
    proto_coordinate->set_x(u.x());
    proto_coordinate->set_y(u.y());

    // Set Mappable info
    proto_mappable->set_id(u.id());

    // Set unit info
    proto_unit->set_p_id(u.player_id());
  }

  // Load the map
  for(const Tile &t : map) {
    // Initialize proto classes
    proto_tile = game_turn.add_tiles();
    proto_mappable = proto_tile->mutable_m();
    proto_coordinate = proto_mappable->mutable_c();

    // Set Coordinate
    proto_coordinate->set_x(t.x());
    proto_coordinate->set_y(t.y());

    // Set Mappable info
    proto_mappable->set_id(t.id());

    // Set Tile info
    proto_tile->set_c(to_string(t.get_char()));
    proto_tile->set_type(t.type());
  }

  // Set the global static variables
  game_turn.set_turn_number(turn_number);
  game_turn.set_id_iterator(id_iterator);

  // Write to file
  ph.AddFileOutput("current_turn.dat");
  ph.OverwriteOutputs(game_turn);

  std::cout << game_turn.DebugString() << std::endl;

  return;
}