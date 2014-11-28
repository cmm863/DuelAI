#ifndef MAPPABLE_H
#define MAPPABLE_H

class Mappable {
protected:
	int m_x, m_y, m_id;
public:
	static int m_iterator;
	int x();
	int y();
};

#endif