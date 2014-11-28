#include "ai.h"

AI::AI(int player_id) {
	m_player_id = player_id;

	return;
}

void AI::init() {

	return;
}

bool AI::run() {
	spawn();

	return true;
}

void AI::end() {
	for(Unit u : units) {
		std::cout << u.DebugString() << std::endl;
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