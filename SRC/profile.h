#ifndef __PROFILE_H__
#define __PROFILE_H__

#include <iostream>
#include <vector>
#include <utility>

#include "vector.h"

class Corner;

struct RTco
{
	double r, theta;
};

class Profile
{
	std::vector<RTco> p;
	int valid;

public:
	Profile();
	Profile( std::vector<RTco> );
	
	~Profile();

	const std::vector<RTco> & get_p() const;
	int is_valid() const ;
	void print(std::ostream &flux) const ;
	std::vector<Vector> to_cartesian(Corner *c1, Corner *c2);
};

std::ostream &operator<<( std::ostream &flux, const Profile &co);
std::ostream &operator<<( std::ostream &flux, const RTco &co);

int operator==(const RTco&, const RTco&);
int operator!=(const RTco&, const RTco&);
// int operator< (const RTco&, const RTco&);
// int operator> (const RTco&, const RTco&);

#endif