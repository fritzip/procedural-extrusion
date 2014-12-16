#ifndef __PROFILE_H__
#define __PROFILE_H__

#include <iostream>
#include <vector>
#include <utility>

#include "vector.h"

class Corner;

struct WZco
{
	double w, z;
};

class Profile
{

	std::vector<WZco> p;

public:
	Profile();
	// std::pair<int, double>
	Profile( std::vector<WZco> );
	
	~Profile();

	std::vector<Vector> to_cartesian(Corner *c1, Corner *c2);
};

#endif