//////////////////////////////////////////////////////////////////////
/// @file main.cpp
/// @author Connor McBride
/// @brief Runs the game.
//////////////////////////////////////////////////////////////////////

// Standard library imports
#include <iostream>
#include <vector>

// Game imports
#include "ai.h"
#include "coordinate.h"

using namespace std;

int main() {
	// Declare the players
	vector<AI> players;

	// Initialize all that are playing
	players.push_back(AI(1));
	players.push_back(AI(2));

	// For each player, init()
	for(AI &p : players) {
		p.init();
	}

	// For x turns for each player, run()
	for(int i = 0; i < 5; i++) {
		for(AI &p : players) {
			p.run();
			BaseAI::m_turn_number++;
		}
		AI::PrintGameMap();
	}
	// For each player, end()
	for(AI &p : players) {
		p.end();
	}

	return 0;
}