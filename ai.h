#ifndef AI_H
#define AI_H

// Base class includes
#include "baseai.h"

class AI : public BaseAI {
private:
	int m_player_id;
	void spawn(int x = kUndefined, int y = kUndefined, int type = kUndefined);
	int PlayerID();
public:
	AI(int player_id);
	void init();
	bool run();
	void end();
};



#endif