// Standard library imports
#include <iostream>
#include <vector>

// Game imports
#include "ai.h"
#include "coordinate.h"

using namespace std;

int main() {
	vector<AI> players;

	players.push_back(AI(1));
	players.push_back(AI(2));

	// Init()
	for(AI &p : players) {
		p.init();
	}
	// Turns (run())
	for(int i = 0; i < 5; i++) {
		for(AI &p : players) {
			p.run();
			BaseAI::m_turn_number++;
		}
		AI::PrintGameMap();
	}
	// End()
	for(AI &p : players) {
		p.end();
	}

	return 0;
}