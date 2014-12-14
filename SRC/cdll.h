#ifndef __HOUSE_H__
#define __HOUSE_H__

#include <stdio.h>
#include <math.h>
#include <vector>
#include <list>
#include <queue>

#define PI 3.14159265

struct XYZco
{
	double x, y, z;
};

void print_co(XYZco co);

struct WZco
{
	double w, z;
};

XYZco wz_to_xyz(const WZco &p1, const WZco &p2, double y);

class Plane
{
	double a, b, c, d;
	std::vector<XYZco> vertex;

public:
	Plane() : a(0), b(0), c(0), d(0), vertex()
	{}

	Plane(const XYZco &coc1, const XYZco &coc2, XYZco prof1) : a(0), b(0), c(0), d(0), vertex({coc1, coc2, prof1})
	{
		compute_plan(coc1, coc2, prof1);
	}

	~Plane()
	{}

	double get_a() const { return a; }
	double get_b() const { return b; }
	double get_c() const { return c; }
	double get_d() const { return d; }

	void compute_plan( const XYZco &p, const XYZco &q, const XYZco &r  );
};

int intersect_is_point( const Plane &p1, const Plane &p2, const Plane &p3 );

XYZco intersect_3_planes(const Plane &p1, const Plane &p2, const Plane &p3);


class Corner
{
	XYZco co;

public:
	Corner() : co{0, 0, 0}
	{}

	Corner(double x, double y, double z) : co{x, y, z}
	{}

	~Corner()
	{}

	XYZco get_co() const { return co; }

};

class Edge
{
	Corner *prev;
	Corner *next;
	std::vector<WZco> profile;
	Plane directionPlane;

public:
	Edge()
	{}

	Edge(Corner *c1, Corner *c2, std::vector<WZco> _profile)
	{
		prev = c1 ;
		next = c2 ;
		profile = _profile ;

		if (_profile.size() >= 2)
		{
			XYZco pt = wz_to_xyz(_profile[0], _profile[1], fabs( c1->get_co().y - c2->get_co().y ) / 2 );
			directionPlane = Plane(c1->get_co(), c2->get_co(), pt);
		}
		// else 
		// 	directionPlane = Plane();
	}

	~Edge()
	{}

	Plane get_dir_plane() const { return directionPlane; }
};



// class Corndge
// {
// 	Corner c;
// 	Edge e;

// public:
// 	Corndge()
// 	{}

// 	~Corndge()
// 	{}

// 	Edge get_edge() const { return e; }
// 	Corner get_corner() const { return c; }
// };


// class Plan
// {
// 	friend class House;

// 	std::list<Corndge> ce;

// public:
// 	Plan() : ce()
// 	{}

// 	Plan(const std::list<Corndge> &corndge_list) : ce(1, corndge_list)
// 	{}

// 	~Plan()
// 	{}
// };

typedef std::list<Edge> Plan;

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
	XYZco co;
public:
	Event();
	~Event();

	XYZco get_co() const { return co; }
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
		if (reverse) return (a.get_co().z > b.get_co().z);
		else return (a.get_co().z < b.get_co().z);
	}
};

typedef std::priority_queue<Event,std::vector<Event>,EventComparaison> PriorityQ;

#endif