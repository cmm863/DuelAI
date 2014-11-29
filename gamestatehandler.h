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

#endif