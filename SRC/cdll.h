
#include <stdio.h>
#include <vector>
#include <list>
#include <queue>

struct XYZco
{
	double x, y, z;
};

struct WZco
{
	double w, z;
};


class Plane
{
	double a, b, c;
	std::vector<XYZco> vertex;

public:
	Plane()
	{}

	~Plane()
	{}

};

XYZco intersect3planes(const Plane &p1, const Plane &p2, const Plane &p3);

class Edge
{
	std::vector<WZco> profile;
	Plane directionPlane;

public:
	Edge()
	{}

	~Edge()
	{}

	Plane getDirPlane() const 
	{
		return directionPlane;
	}
};


class Corner
{
	XYZco co;

public:
	Corner() : co{0, 0, 0}
	{}

	Corner(double _x, double _y, double _z) : co{_x, _y, _z}
	{}

	~Corner()
	{}

	XYZco getCo() const
	{
		return co;
	}

};


class Corndge
{
	Corner c;
	Edge e;

public:
	Corndge()
	{}

	~Corndge()
	{}

	Edge getEdge() const
	{
		return e;
	}

	Corner getCorner() const
	{
		return c;
	}
};


class Plan
{
	friend class House;

	std::list<Corndge> ce;

public:
	Plan()
	{}

	~Plan()
	{}

};


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
	XYZco getCo() const
	{
		return co;
	}
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
		if (reverse) return (a.getCo().z > b.getCo().z);
		else return (a.getCo().z < b.getCo().z);
	}
};

typedef std::priority_queue<Event,std::vector<Event>,EventComparaison> PriorityQ;
