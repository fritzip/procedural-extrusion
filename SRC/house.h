#ifndef __HOUSE_H__
#define __HOUSE_H__

#include <stdio.h>
#include <math.h>
#include <vector>
#include <list>
#include <queue>

#include "vector.h"
#include "edge.h"
#include "corner.h"

#define PI 3.14159265


// void print_co(XYZco co);

// XYZco wz_to_xyz(const WZco &p1, const WZco &p2, double y); 
// reflechir orientation (perpendicalaire à la direction p1 - p2)




// class Plan
// {
// 	friend class House;

// 	std::list<Corner> ce;

// public:
// 	Plan() : ce()
// 	{}

// 	Plan(const std::list<Corndge> &corndge_list) : ce(1, corndge_list)
// 	{}

// 	~Plan()
// 	{}
// };

typedef std::list<Corner*> Plan;

class House
{

	std::vector<Plan> level;

public:
	House() : level()
	{}

	House(const Plan &init ) : level(1, init)
	{}

	~House()
	{}
	
	void extrude();
};


class Event
{
	enum type { GIE, EDE, POE };
	Vector co;
public:
	Event();
	~Event();

	Vector get_co() const { return co; }
};

class EventComparaison
{
	bool reverse;
public:
	EventComparaison(const bool &revparam=false) 
		: reverse(revparam)
		{}

	bool operator() (const Event &a, const Event &b) const
	{
		if (reverse) return (a.get_co()[2] > b.get_co()[2]);
		else return (a.get_co()[2] < b.get_co()[2]);
	}
};

typedef std::priority_queue<Event,std::vector<Event>,EventComparaison> PriorityQ;

#endif