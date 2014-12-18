/*****************************************************************************/
//
//									Event
//
/*****************************************************************************/
#include <iostream>
#include <vector>

#include "event.h"

using namespace std;

/*************************************/
//			Constructors
/*************************************/
Event::Event()
{}

Event::Event(Vector *pt, Corner *bilat, Corner *unilat, int evt_type ) : co(pt), type(evt_type), bilat(bilat), unilat(unilat)
{}

/*************************************/
//			Destructors
/*************************************/
Event::~Event()
{
	// cout << "Destroy Event" << endl;
}

/*************************************/
//			Public methods
/*************************************/
bool Event::is_gie()
{
	return (type == GIE);
}

bool Event::is_ede()
{
	return (type == EDE);
}

bool Event::are_adjacent()
{
	return (unilat == bilat->ge_next()->gc_next() || unilat == bilat->ge_prev()->gc_prev());
}

/*************************************/
//			Getters
/*************************************/
Vector* Event::get_co() const { return co; }
int Event::get_type() const { return type; }
Corner* Event::get_bilat() const { return bilat; }
Corner* Event::get_unilat() const { return unilat; }

/*************************************/
//			Setters
/*************************************/

/*************************************/
//			Operators overloading
/*************************************/
