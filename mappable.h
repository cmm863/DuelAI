#ifndef MAPPABLE_H
#define MAPPABLE_H

#include "coordinate.h"

class Mappable {
protected:
	Coordinate m_c;
	int m_id;
public:
	static int m_iterator;
	int x();
	int y();
};

#endif