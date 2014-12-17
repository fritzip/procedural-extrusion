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
	int valid;

public:
	Edge();
	Edge( const Profile &_profile ) ;
	~Edge();

	void compute_dir_plane();

	Plane get_dir_plane() const ;
	int is_valid() const ;
	Corner* gc_prev() const ;
	Corner* gc_next() const ;
	void sc_prev(Corner*) ;
	void sc_next(Corner*) ;
};

#endif