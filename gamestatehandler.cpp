#include "gamestatehandler.h"

void GameStateHandler::SerializeGameState(vector<Tile> map, vector<Unit> units, int turn_number, int id_iterator) {
  ProtoHandler ph = ProtoHandler();
  ProtoGameState::Turn game_turn;
  ProtoGameState::Turn copy_turn;
  // Load the units
  for(Unit &u : units) {
    // Initialize proto classes
    ProtoGameState::Unit * proto_unit = game_turn.add_units();
    ProtoGameState::Mappable * proto_mappable(proto_unit->mutable_m());
    ProtoGameState::Coordinate * proto_coordinate(proto_mappable->mutable_c());

    // Set Coordinate
    proto_coordinate->set_x(u.x());
    proto_coordinate->set_y(u.y());

    // Set Mappable info
    proto_mappable->set_id(u.id());

    // Set unit info
    proto_unit->set_p_id(u.player_id());
  }

  // Load the map
  for(Tile &t : map) {
    // Initialize proto classes
    ProtoGameState::Tile * proto_tile = game_turn.add_tiles();
    ProtoGameState::Mappable * proto_mappable(proto_tile->mutable_m());
    ProtoGameState::Coordinate * proto_coordinate(proto_mappable->mutable_c());

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

  google::protobuf::ShutdownProtobufLibrary();

  return;
}