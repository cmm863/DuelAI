#include "unit.h"

Unit::Unit(int x, int y, int type, int player_id) {
	m_x = x;
	m_y = y;
	m_type = type;
	m_player_id = player_id;
	m_id = Mappable::m_iterator;
	Mappable::m_iterator++;
	
	return;
}

bool Unit::Move(int x, int y) {
	m_x = x;
	m_y = y;

	return true;
}

int Unit::type() {
	return m_type;
}

int Unit::moves_left() {
	return m_moves_left;
}

int Unit::player_id() {
	return m_player_id;
}

string Unit::DebugString() {
	string response = "Unit {\n";
	response += "\tPlayer: " + to_string(m_player_id) + '\n';
	response += "\tID: " + to_string(m_id) + '\n';
	response += "\tx: " + to_string(m_x) + '\n';
	response += "\ty: " + to_string(m_y) + '\n';
	response += "\ttype: " + to_string(m_type) + '\n';
	response += "\tmoves_left: " + to_string(m_moves_left) + '\n';
	response += '}';
	return response;

}