#ifndef __PLAN_H__
#define __PLAN_H__

#include "corner.h"
#include "edge.h"
#include "plane.h"


class Plan : public std::list<Corner*>
{

	std::list<Corner*> plan;

public:
	Plan();
	~Plan();

	void append(const double &x, const double &y, const double &z, const Profile &profile );

	void finish();

	const std::list<Corner*> & get_plan() const;
};

#endif