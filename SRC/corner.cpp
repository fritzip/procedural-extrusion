/*****************************************************************************/
//
//									Corner
//
/*****************************************************************************/
#include <iostream>

#include "corner.h"

using namespace std;

/*************************************/
//			Constructors
/*************************************/
Corner::Corner() : co(), prev(NULL), next(NULL)
{}

Corner::Corner(const double &x, const double &y, const double &z)
{
	co = new Vector(x,y,z);
	prev = NULL;
	next = NULL;
}

// Corner::Corner(const double &x, const double &y, const double &z, Edge *e1, Edge *e2 ) : co(x, y, z), prev(e1), next(e2)
// {
// 	e1->next = this;
// 	e2->prev = this;
// }

/*************************************/
//			Destructors
/*************************************/
Corner::~Corner()
{
	cout << "Destroy Corner" << endl;
	// delete co;
}

/*************************************/
//			Public methods
/*************************************/
void Corner::print(ostream &flux) const
{
	co->print(flux);
}

/*************************************/
//			Getters
/*************************************/
Vector* Corner::get_co() const { return co; }
// int Corner::is_valid() const { return valid ; }
Edge* Corner::ge_prev() const { return prev ; }
Edge* Corner::ge_next() const { return next ; }

/*************************************/
//			Setters
/*************************************/
void Corner::se_prev(Edge *e) { prev = e ; }
void Corner::se_next(Edge *e) { next = e ; }

/*************************************/
//			Operators overloading
/*************************************/
ostream &operator<<( ostream &flux, const Corner &c)
{
	c.print(flux) ;
	return flux;
}
