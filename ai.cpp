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
	spawn(1, 1);

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
	for(Unit &u : units) {
		if(PlayerID() == u.player_id())
			std::cout << u.DebugString() << std::endl;
	}
	return;
}

void AI::spawn(int x, int y, int type) {
	if(InMapBounds(x, y)) {
		if(!Occupied(x, y)) {
			Unit u = Unit(x, y, type, AI::m_player_id);
			units.push_back(u);
		} else {
			std::cerr << "--Spawn denied at X: " << x << ", Y: " << y << " (Occupied)" << std::endl;
		}
	} else {
		std::cerr << "-- Spawn denied at X: " << x << ", Y: " << y << " (Out of Map)" << std::endl;
	}
	return;
}

int AI::PlayerID() {
	return m_player_id;
}

int AI::TurnNumber() {
	return BaseAI::m_turn_number;
}

bool AI::InMapBounds(int x, int y) {
	return (x >= 0 && x < kMapWidth && y >= 0 && y < kMapHeight);
}

bool AI::Occupied(int x, int y) {
	for(Unit &u : units) {
		if(u.x() == x && u.y() == y) {
			return true;
		}
	}

	return false;
}