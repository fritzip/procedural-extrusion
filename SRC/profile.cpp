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
	// p.push_back(RTco{0,0});
}
//pair<int, double>
Profile::Profile( vector<RTco> p_in )
{
	valid = 1;
	// p.push_back(RTco{0,0});
	for(vector<RTco>::iterator it = p_in.begin(); it != p_in.end(); ++it) 
	{
		if ( (*it).theta <= 90 && (*it).theta >= -90 )
		{
			// (*it).theta != p.back().theta &&
			p.push_back(*it);
			// cout << "OKAY : "  << *it << endl;
		}
		else
		{
			// cout << "WRONG : " << *it << endl;
			valid = 0;
			break;
		}
	}
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
{
	cout << "Destroy Profile" << endl;
}

/*************************************/
//			Public methods
/*************************************/
// vector<Vector> to_cartesian(Corner *c1, Corner *c2)
// {

// }

vector<RTco>& Profile::get_p() {return p;}


int Profile::is_valid() const { return valid; }

void Profile::print(ostream &flux) const
{
	for(vector<int>::size_type i = 0; i != p.size(); i++) 
	{
		flux << p[i];
	}
}

/*************************************/
//			Getters
/*************************************/

/*************************************/
//			Setters
/*************************************/

/*************************************/
//			Operators overloading
/*************************************/

ostream &operator<<( ostream &flux, const RTco &co)
{
	flux << "r = " << co.r << ", theta = " << co.theta ;
	return flux;
}

int operator== (const RTco& u, const RTco& v) 
{
	return ( (u.theta==v.theta ) && ( u.r==v.r ) );
}

int operator!= (const RTco& u, const RTco& v) 
{
	return ( !(u==v) );
}

ostream &operator<<( ostream &flux, const Profile &prof)
{
	prof.print(flux) ;
	return flux;
}
