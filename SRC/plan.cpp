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
int Plan::append(const double &x, const double &y, const double &z, const Profile &profile )
{
	Corner *c = new Corner(x, y, z);
	// if (!c->is_valid()) 
	// {
	// 	cout << "Unvalid corner" << endl;
	// 	return 1;
	// }
	Edge *e = new Edge(profile);
	if (!e->is_valid()) 
	{
		cout << "Unvalid edge" << endl;
		return 1;
	}
	// cout << profile << endl;
	// cout << "new corner added : " << *c << endl;
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
	return 0;
}

void Plan::finish()
{
	plan.back()->ge_next()->sc_next(plan.front());
	plan.front()->se_prev(plan.back()->ge_next());
	if (plan.size() > 2)
	{
		for (std::list<Corner*>::iterator it=plan.begin(); it != plan.end(); ++it)
		{
			(*it)->ge_next()->compute_dir_plane();
		}
	}
}

/*************************************/
//			Getters
/*************************************/
const list<Corner*> & Plan::get_plan() const { return plan ; }

/*************************************/
//			Setters
/*************************************/

/*************************************/
//			Operators overloading
/*************************************/