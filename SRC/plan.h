#ifndef __PLAN_H__
#define __PLAN_H__

#include <list>

#include "corner.h"
#include "edge.h"
#include "plane.h"


class Plan//: public std::list<Corner*>
{

	std::list<Corner*> plan;
	double z;

public:
	Plan();
	Plan(const double &z);
	Plan(const std::list<Corner*> &plan, const double &z);
	~Plan();

	int append(const double &x, const double &y, const double &z, Profile *profile );
	int append(Corner *c, Profile *profile );

	void finish();

	std::list<Corner*>& get_plan();
};

#endif