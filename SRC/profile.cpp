/*****************************************************************************/
//
//									Profile
//
/*****************************************************************************/
#include <iostream>
#include <vector>

#include "profile.h"

using namespace std;

/*************************************/
//			Constructors
/*************************************/
Profile::Profile()
{
	p.push_back(WZco{0,0});
}
//pair<int, double>
Profile::Profile( vector<WZco> _p )
{
	p = _p; // securiser plus ici
} 


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
Profile::~Profile()
{}

/*************************************/
//			Public methods
/*************************************/
// vector<Vector> to_cartesian(Corner *c1, Corner *c2)
// {

// }


/*************************************/
//			Getters
/*************************************/

/*************************************/
//			Setters
/*************************************/

/*************************************/
//			Operators overloading
/*************************************/