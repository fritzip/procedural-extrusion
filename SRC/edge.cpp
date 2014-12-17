/*****************************************************************************/
//
//									Edge
//
/*****************************************************************************/
#include <iostream>
#include <vector>

#include "edge.h"

using namespace std;

/*************************************/
//			Constructors
/*************************************/
Edge::Edge()
{}

Edge::Edge( const Profile &_profile ) : profile(_profile), directionPlane(), prev(NULL), next(NULL), valid(0)
{
	valid = profile.is_valid();
}


/*************************************/
//			Destructors
/*************************************/
Edge::~Edge()
{}

/*************************************/
//			Public methods
/*************************************/
void Edge::compute_dir_plane()
{
	// cout << prev->get_co() << endl;
	directionPlane = Plane(prev->get_co(), next->get_co(), profile.get_p().front());	
}

/*************************************/
//			Getters
/*************************************/
Plane Edge::get_dir_plane() const { return directionPlane; }
int Edge::is_valid() const { return valid ;}
Corner* Edge::gc_prev() const { return prev; }
Corner* Edge::gc_next() const { return next; }

/*************************************/
//			Setters
/*************************************/
void Edge::sc_prev(Corner *c) { prev = c; }
void Edge::sc_next(Corner *c) { next = c; }

/*************************************/
//			Operators overloading
/*************************************/