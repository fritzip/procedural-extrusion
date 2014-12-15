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

Edge::Edge(Corner *c1, Corner *c2 ) : prev(c1), next(c2)
{
	c1->next = this;
	c2->prev = this;
} 

// Edge::Edge( vector<WZco> _profile, Corner *c1, Corner *c2 )
// {
// 	prev = c1 ;
// 	next = c2 ;
// 	profile = _profile ;

// 	// if (_profile.size() >= 2)
// 	// {
// 	// 	Vector pt = wz_to_xyz(_profile[0], _profile[1], fabs( c1->get_co().y - c2->get_co().y ) / 2 );
// 	// 	directionPlane = Plane(c1->get_co(), c2->get_co(), pt);
// 	// }
// 	// else 
// 	// 	directionPlane = Plane();
// }

/*************************************/
//			Destructors
/*************************************/
Edge::~Edge()
{}


/*************************************/
//			Public methods
/*************************************/
Plane Edge::get_dir_plane() const { return directionPlane; }


/*************************************/
//			Getters
/*************************************/

/*************************************/
//			Setters
/*************************************/

/*************************************/
//			Operators overloading
/*************************************/