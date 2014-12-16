#ifndef __EDGE_H__
#define __EDGE_H__

#include "plane.h"
#include "corner.h"
#include "profile.h"

class Corner;

class Edge
{
	friend class Corner;

	Profile profile;
	Plane directionPlane;
	Corner *prev;
	Corner *next;

public:
	Edge();
	// Edge(Corner *c1, Corner *c2 );
	Edge( const Profile &_profile ) ;
	~Edge();

	Plane get_dir_plane() const ;
	Corner* gc_prev() const ;
	Corner* gc_next() const ;
	void sc_prev(Corner*) ;
	void sc_next(Corner*) ;
};

#endif