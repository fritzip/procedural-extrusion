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

Plan::Plan(const double &z) : plan(), z(z)
{}

Plan::Plan(const list<Corner*> &plan, const double &zinit) : plan(plan), z(zinit)
{}

// Plan::Plan(Corner *c) : plan(c)
// {}
/*************************************/
//			Destructors
/*************************************/
Plan::~Plan()
{
	cout << "Destroy Plan" << endl;
	// delete plan.front() n fois
}


/*************************************/
//			Public methods
/*************************************/
int Plan::append(const double &x, const double &y, const double &z, Profile *profile )
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

int Plan::append(Corner *c, Profile *profile )
{
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
	cout << "FINISH" << endl;
	plan.back()->ge_next()->sc_next(plan.front());
	plan.front()->se_prev(plan.back()->ge_next());
	if (plan.size() > 2)
	{
		for (std::list<Corner*>::iterator it=plan.begin(); it != plan.end(); ++it)
		{
			cout << "C1 : " << *(*it) << endl;
			cout << "C2 : " << *((*it)->ge_next()->gc_next()) << endl;
			(*it)->ge_next()->compute_dir_plane();
		}
	}
	cout << "END FINISH" << endl;
}

/*************************************/
//			Getters
/*************************************/
list<Corner*>& Plan::get_plan() { return plan ; }

/*************************************/
//			Setters
/*************************************/

/*************************************/
//			Operators overloading
/*************************************/