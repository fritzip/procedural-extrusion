#ifndef __EVENT_H__
#define __EVENT_H__

#include <iostream>
#include <algorithm>
#include <queue>
#include "vector.h"
#include "corner.h"

enum type { GIE, EDE };

class Event
{
	Vector *co;
	int type;
	Corner *bilat;
	Corner *unilat;

public:
	Event();
	Event(Vector *pt, Corner *bilat, Corner *unilat, int evt_type );
	~Event();

	bool is_gie();
	bool is_ede();
	bool are_adjacent();

	Vector* get_co() const;
	int get_type() const;
	Corner* get_bilat() const;
	Corner* get_unilat() const;
};

class Cluster
{
	std::vector<Event> v;
	Vector *bary;
	int type;
	std::vector<Edge*> ed;

public:
	Cluster() 
	{}

	Cluster(std::vector<Event> v, Vector *co, int type) : v(v), bary(co), type(type)
	{}

	~Cluster()
	{}

	std::vector<Event>& get_clust() { return v; } 
	Vector* get_bary() const { return bary; }
	int get_type() const { return type; }

	void compute_nb_of_diff_planes()
	{
		Edge *current;
		for (size_t i = 0; i < v.size(); ++i)
		{
			for (size_t j = 0; j < 3; ++j)
			{
				switch (j) {
					case 0: current = v[i].get_bilat()->ge_next();
						break;
					case 1: current = v[i].get_bilat()->ge_prev();
						break;
					case 2: current = v[i].get_unilat()->ge_next();
						break;
					default: break;			
				}

				if( !(std::find(ed.begin(), ed.end(), current) != ed.end()) )
				    ed.push_back(current);
			}
		}
	}
};

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