// Standard library imports
#include <iostream>
#include <vector>

// Game imports
#include "ai.h"

using namespace std;

int main() {
	// CURRENTLY TESTING OUT THE SPAWN.
	AI player_one = AI(1);
	AI player_two = AI(2);

	// Init()
	player_one.init();
	player_two.init();
	for(int i = 0; i < 10; i++) {
		// Player one has his turn
		player_one.run();
		BaseAI::turn_number++;

		// Player two has his turn
		player_two.run();
		BaseAI::turn_number++;
	}

	// End()
	player_one.end();
	player_two.end();
	return 0;
}