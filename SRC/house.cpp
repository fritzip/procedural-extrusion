/*****************************************************************************/
//
//									House
//
/*****************************************************************************/
#include <iterator>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <list>
#include <queue>

#include "event.h"
#include "house.h"
 
using namespace std;

/*************************************/
//			Constructors
/*************************************/
House::House() : level()
{}

House::House(Plan *init)
{
	cout << "Constructor House" << endl;
	level.reserve(100);
	level.push_back(init);
}

/*************************************/
//			Destructors
/*************************************/
House::~House()
{
	cout << "Destroy House" << endl;
	for (size_t i = 0; i < level.size(); ++i)
	{
		delete level[i];
	}
}
	
	
/*************************************/
//			Public methods
/*************************************/
void House::extrude()
{
	PriorityQ Q;
	Plan* active_plan = level.back();
	Plane *p1, *p2, *p3;
	vector<Cluster> clustering;

	for (list<Corner*>::iterator itc=active_plan->get_plan().begin(); itc != active_plan->get_plan().end(); ++itc)
	{
		for (list<Corner*>::iterator ite=active_plan->get_plan().begin(); ite != active_plan->get_plan().end(); ++ite)
		{
			// cout << "somthing her" << endl;
			p1 = (*ite)->ge_next()->get_dir_plane();
			p2 = (*itc)->ge_next()->get_dir_plane();
			p3 = (*itc)->ge_prev()->get_dir_plane();

			if (!(p1 == p2 || p1 == p3 || p2 == p3) && intersect_is_point(*p1, *p2, *p3) )
			{
				// cout << *((*p1).get_vert().back()) << endl << *((*p2).get_vert().back()) << endl << *((*p3).get_vert().back()) << endl;
				// cout << "intersect : " << intersect_is_point(*p1, *p2, *p3) << endl;
				cout << "pt intersect : " << *(intersect_3_planes((*p1), (*p2), (*p3))) << endl;
				Vector* pt_intersect = intersect_3_planes((*p1), (*p2), (*p3));
				Event event(pt_intersect, (*itc), (*ite), GIE);
				Q.push(event);
				// cout << dot(*(intersect_3_planes((*p1), (*p2), (*p3))), (*p1).get_norm()) << endl;
				// cout << dot(*(intersect_3_planes((*p1), (*p2), (*p3))), (*p2).get_norm()) << endl;
				// cout << dot(*(intersect_3_planes((*p1), (*p2), (*p3))), (*p3).get_norm()) << endl;
			}
		}	
	}
	double zinit = (*(Q.top().get_co()))[2];
	bool ADD_TO_CLUST;
	Event current = Q.top();
	// clustering.push_back(Cluster({current}, current.get_co(), current.get_type()));
	while (!Q.empty())
	{
		current = Q.top();
		ADD_TO_CLUST = 0;
		if ( ( (*(current.get_co()))[2] - zinit) < 0.0001)
		{
			cout << "current = " << (*(current.get_co())) << endl;
			for (size_t i = 0; i < clustering.size(); ++i)
			{
				if( norm((*(clustering[i].get_bary())) - (*(current.get_co()))) < 0.000001 && current.get_type() == clustering[i].get_type() )
				{
					cout << "add to cluster n°" << i << endl;
					clustering[i].get_clust().push_back(current);
					*(clustering[i].get_bary()) = ((*(clustering[i].get_bary()))*clustering[i].get_clust().size() + (*(current.get_co()))) / (clustering[i].get_clust().size() + 1);
					ADD_TO_CLUST = 1;
					break;
				}

			}
			if (! ADD_TO_CLUST)
			{
				cout << "create new cluster" << endl;
				clustering.push_back( Cluster( {current}, current.get_co(), current.get_type() ) );
			}
			Q.pop();
		}
		else
		{
			while (!Q.empty()) 
				Q.pop();
		}
	}

	for (size_t i = 0; i < clustering.size(); ++i)
	{
		cout << "cluster n°" << i << ", type : " << clustering[i].get_type() << endl;
		cout << "cluster type : " << clustering[i].get_type() << endl;
		for (size_t j = 0; j < clustering[i].get_clust().size(); ++j)
		{
			 cout << "pt : " << *(clustering[i].get_clust()[j].get_co()) << endl;
		}
		cout << "barycentre : " << *(clustering[i].get_bary()) << endl;
	}
}


/*************************************/
//			Getters
/*************************************/

/*************************************/
//			Setters
/*************************************/

/*************************************/
//			Operators overloading
/*************************************/