#ifndef __HOUSE_H__
#define __HOUSE_H__

#include <vector>

#include "plan.h"

#define PI 3.14159265


class House
{
	std::vector<Plan*> level;

public:
	House();
	House(Plan *init);

	~House();
	
	void extrude(Plan*);
};

#endif