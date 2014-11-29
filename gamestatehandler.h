#ifndef GAMESTATEHANDLER_H
#define GAMESTATEHANDLER_H

// Standard Library includes
#include <fstream>

// Local includes
#include "ai.h"
#include "protohandler.h"

class GameStateHandler {
public:
  static void SerializeGameState(vector<Tile> map, vector<Unit> units, int turn_number, int id_iterator);
};

template <typename T>
void ProtoHandler::OverwriteOutputs(const T &proto) {
  fstream output(file_output, ios::out | ios::trunc | ios::binary);
  proto.SerializeToOstream(&output);
  return;
}

template <typename T>
void ProtoHandler::AppendToOutputs(const T &proto) {
  fstream output(file_output, ios::out | ios::ate | ios::binary);
  proto.SerializeToOstream(&output);
  return;
}

template <typename T>
void ProtoHandler::LoadInputTo(T &proto) {
  fstream input(file_input, ios::in | ios::binary);
  proto.ParseFromIstream(&input);
}

#endif