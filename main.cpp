//////////////////////////////////////////////////////////////////////
/// @file main.cpp
/// @author Connor McBride
/// @brief Runs the game.
//////////////////////////////////////////////////////////////////////

// Standard library imports
#include <iostream>
#include <vector>

// Game imports
#include "gamestatehandler.h"

using namespace std;

int main() {
  // Clear Gamelogs
  GameStateHandler::ClearGameStateFiles();
  // Set Up Timer
  clock_t begin = clock();
  // Declare the players
  vector<AI> players;

  // Initialize all that are playing
  players.push_back(AI(1));
  players.push_back(AI(2));

  // For each player, init()
  for (AI &p : players) {
    p.init();
  }

  // For x turns for each player, run()
  for (int i = 0; i < kHalfTurnNumbers; i++) {
    for (AI &p : players) {
      p.run();
      BaseAI::m_turn_number++;
      GameStateHandler::SerializeGameState(BaseAI::tiles, BaseAI::units, BaseAI::m_turn_number, Mappable::m_iterator);
    }
  }
  // For each player, end()
  for (AI &p : players) {
    p.end();
  }

  // End clock & output
  clock_t end = clock();
  std::cout << "Time: " << double(end - begin) / CLOCKS_PER_SEC << std::endl;

  return 0;
}