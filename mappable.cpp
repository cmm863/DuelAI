#include "mappable.h"

int Mappable::m_iterator = 0;

int Mappable::x() {
	return m_c.x();
}

int Mappable::y() {
	return m_c.y();
}