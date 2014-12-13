#include <iterator>

#include "cdll.h"
 
using namespace std;


XYZco intersect3planes(const Plane &p1, const Plane &p2, const Plane &p3)
{
	//
	return XYZco();
}


void House::extrude()
{
	PriorityQ Q();
	Plan active(level.back());
	Plane p1, p2, p3;
	for (list<Corndge>::iterator itc=active.ce.begin(); itc != active.ce.end(); ++itc)
	{
		for (list<Corndge>::iterator ite=active.ce.begin(); ite != active.ce.end(); ++ite)
		{
			p1 = (*ite).getEdge().getDirPlane();
			p2 = (*itc).getEdge().getDirPlane();
			if (itc == active.ce.begin())
				p3 = active.ce.back().getEdge().getDirPlane();
			else
				p3 = (*next(itc)).getEdge().getDirPlane();

			// intersect3planes(p1,p2,p3);
			// event = ;

			// Q.push(event);
		}	
	}
}


