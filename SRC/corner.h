#ifndef __CORNER_H__
#define __CORNER_H__

#include <iostream>

#include "edge.h"
#include "vector.h"

class Edge;

class Corner
{
	friend class Edge;

	Vector *co;
	Edge *prev;
	Edge *next;	
	// int valid;

public:
	Corner();
	Corner(const double &x, const double &y, const double &z);
	// Corner(const double &x, const double &y, const double &z, Edge *e1, Edge *e2 ) ;
	~Corner();
	
	Vector* get_co() const;

	void print(std::ostream &flux) const ;

	// int is_valid() const ;
	Edge* ge_prev() const ;
	Edge* ge_next() const ;

	void se_prev(Edge *e) ;
	void se_next(Edge *e) ;

};

std::ostream &operator<<( std::ostream &flux, const Corner &c);

#endif