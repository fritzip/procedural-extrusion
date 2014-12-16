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
	cout << "in append : " << *c << endl;
	if (plan.empty()) 
	{
		c->se_prev(NULL);
	}
	else 
	{
		c->se_prev(plan.back()->ge_next());
		c->ge_prev()->sc_next(c);
	}
	c->se_next(e);
	e->sc_prev(c);

	plan.push_back(c);
}

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