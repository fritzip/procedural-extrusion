#ifndef __EVENT_H__
#define __EVENT_H__

#include <iostream>
#include <queue>
#include "vector.h"
#include "corner.h"

enum { GIE, EDE };

class Event
{
	Vector *co;
	int type;
public:
	Event();
	Event(Vector *pt, Corner *bilat, Corner *unilat, int evt_type );
	~Event();

	Vector* get_co() const;
};

// class EventComparaison
// {
// 	bool reverse;
// public:
// 	EventComparaison();
// 	EventComparaison(const bool &revparam=false) ;
// 	~EventComparaison();

// 	bool operator() (const Event &a, const Event &b) const
// 	{
// 		if (reverse) return ((*(a.get_co()))[2] > (*(b.get_co()))[2]);
// 		else return ((*(a.get_co()))[2] < (*(b.get_co()))[2]);
// 	}
// };

struct LessThanByZ
{
	bool operator()(const Event& lhs, const Event& rhs) const
	{
		return (*(lhs.get_co()))[2] > (*(rhs.get_co()))[2];
	}
};

// bool operator<(const Event& lhs, const Event& rhs); 

typedef std::priority_queue<Event, std::vector<Event>, LessThanByZ> PriorityQ;

#endif