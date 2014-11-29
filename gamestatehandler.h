#ifndef GAMESTATEHANDLER_H
#define GAMESTATEHANDLER_H

// Standard Library includes
#include <fstream>

// Local includes
#include "ai.h"
#include "protohandler.h"

class GameStateHandler {
public:
  static void SerializeGameState(const vector<Tile> map, const vector<Unit> units, int turn_number, int id_iterator);
  static void ClearGameStateFiles();
};

#endif