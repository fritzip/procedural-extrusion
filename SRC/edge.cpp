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

Edge::Edge( Profile *_profile )
{
	valid = _profile->is_valid();
	profile = _profile;
	directionPlane = new Plane();
	prev = NULL;
	next = NULL;
	next_ede = NULL;
}


/*************************************/
//			Destructors
/*************************************/
Edge::~Edge()
{
	cout << "Destroy Edge" << endl;
	// delete directionPlane;
	// delete profile;
}

/*************************************/
//			Public methods
/*************************************/
void Edge::compute_dir_plane()
{
	// cout << prev->get_co() << endl;
	next_ede = directionPlane->compute_dir_plane(prev->get_co(), next->get_co(), profile->get_p().front());	
}

/*************************************/
//			Getters
/*************************************/
Plane* Edge::get_dir_plane() const { return directionPlane; }
int Edge::is_valid() const { return valid ;}
Corner* Edge::gc_prev() const { return prev; }
Corner* Edge::gc_next() const { return next; }
Vector* Edge::get_next_ede() const { return next_ede; }

/*************************************/
//			Setters
/*************************************/
void Edge::sc_prev(Corner *c) { prev = c; }
void Edge::sc_next(Corner *c) { next = c; }

/*************************************/
//			Operators overloading
/*************************************/