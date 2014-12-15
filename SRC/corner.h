#ifndef __CORNER_H__
#define __CORNER_H__

#include "edge.h"
#include "vector.h"

class Edge;

class Corner
{
	friend class Edge;

	Vector co;
	Edge *prev;
	Edge *next;	

public:
	Corner();
	Corner(const double &x, const double &y, const double &z);
	Corner(const double &x, const double &y, const double &z, Edge *e1, Edge *e2 ) ;
	~Corner();
	// Vector get_co() const { return co; }

};

#endif