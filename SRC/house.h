#ifndef __HOUSE_H__
#define __HOUSE_H__

#include <stdio.h>
#include <math.h>
#include <vector>
#include <list>
#include <queue>

#include "plan.h"

#define PI 3.14159265


class House
{

	std::vector<Plan*> level;

public:
	House() : level()
	{}

	House(Plan *init)
	{
		std::cout << "Constructor House" << std::endl;
		level.reserve(100);
		level.push_back(init);
	}

	~House()
	{
		std::cout << "Destroy House" << std::endl;
		for (size_t i = 0; i < level.size(); ++i)
		{
			delete level[i];
		}
	}
	
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