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

	void append(const double &x, const double &y, const double &z, const /*std::vector<WZco>*/ int &profile );

	// void append(double x, double y, std::vector<WZco> profile );

	void finish();

	std::list<Corner*> const& get_plan() const;
};

#endif