#ifndef __EDGE_H__
#define __EDGE_H__

#include "corner.h"
#include "plane.h"

struct WZco
{
	double w, z;
};

class Corner;

class Edge
{
	friend class Corner;

	/*std::vector<WZco>*/ int profile;
	Plane directionPlane;
	Corner *prev; // replace by vector ?
	Corner *next;

public:
	Edge();
	// Edge(Corner *c1, Corner *c2 );
	Edge( const /*std::vector<WZco>*/ int &_profile ) ;
	~Edge();

	Plane get_dir_plane() const ;
	Corner* gc_prev() const ;
	Corner* gc_next() const ;
	void sc_prev(Corner*) ;
	void sc_next(Corner*) ;
};

#endif