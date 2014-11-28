#include "ai.h"

AI::AI(int player_id) {
	m_player_id = player_id;

	return;
}

void AI::init() {

	return;
}

bool AI::run() {
	// Spawn something
	spawn();

	// Cycle through units
	for(Unit &u : units) {
		// If they're ours
		if(u.player_id() == PlayerID()) {
			// Move them to the right one
			u.move(u.x() + 1, u.y());
		}
	}
	return true;
}

void AI::end() {
	if(PlayerID() == 1) {
		for(Unit &u : units) {
			std::cout << u.DebugString() << std::endl;
		}
	}
	return;
}

void AI::spawn(int x, int y, int type) {
	Unit u = Unit(x, y, type, AI::m_player_id);
	units.push_back(u);

	return;
}

int AI::PlayerID() {
	return m_player_id;
}

int AI::TurnNumber() {
	return BaseAI::m_turn_number;
}