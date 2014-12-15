/*****************************************************************************/
//
//									Plan
//
/*****************************************************************************/
#include <iostream>
#include <vector>
#include <list>

#include "plan.h"

using namespace std;

/*************************************/
//			Constructors
/*************************************/
Plan::Plan() : plan()
{}

// Plan::Plan(Corner *c) : plan(c)
// {}
/*************************************/
//			Destructors
/*************************************/
Plan::~Plan()
{}


/*************************************/
//			Public methods
/*************************************/
void Plan::append(const double &x, const double &y, const double &z, const /*std::vector<WZco>*/ int &profile )
{
	Corner *c = new Corner(x, y, z);
	Edge *e = new Edge(profile);
	plan.push_back(c);
	c->se_next(e);
	e->sc_prev(c);

}

// void Plan::append(double x, double y, std::vector<WZco> profile )
// {
// 	Corner *c = new Corner(x, y, 0);
// 	plan.push_back(c);
// }

void Plan::finish()
{
	plan.back()->ge_next()->sc_next(plan.front());
	plan.front()->se_prev(plan.back()->ge_next());
}

/*************************************/
//			Getters
/*************************************/
list<Corner*> const& Plan::get_plan() const { return plan ; }

/*************************************/
//			Setters
/*************************************/

/*************************************/
//			Operators overloading
/*************************************/