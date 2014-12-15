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
	// std::vector<WZco> profile;
	Plane directionPlane;
	Corner *prev; // replace by vector ?
	Corner *next;

public:
	Edge();
	Edge(Corner *c1, Corner *c2 );
	// Edge( std::vector<WZco> _profile, Corner *c1, Corner *c2 );
	~Edge();

	Plane get_dir_plane() const ;
};

#endif