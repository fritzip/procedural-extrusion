#include <iostream>
// #include <vector>

#include "plane.h"

using namespace std;

/********** Plane **********/

Plane::Plane() : n(), d(0), vertex()
{}

Plane::Plane(const Vector &normale, double _d, const Vector &coc1, const Vector &coc2, Vector prof1) : n(normale), d(_d), vertex({coc1, coc2, prof1})
{
	compute_plan(coc1, coc2, prof1);
}

Plane::~Plane()
{}

double& Plane::operator[] (int i) 
{
	if      (i == 0) return n[0];
	else if (i == 1) return n[1];
	else if (i == 2) return n[2];
	else             return n[3];
}

const double Plane::operator[] (int i) const 
{
	if      (i == 0) return n[0];
	else if (i == 1) return n[1];
	else if (i == 2) return n[2];
	else             return n[3];
}

Vector Plane::get_norm() const { return n; }

vector<Vector> Plane::get_vert() const { return vertex; }

void Plane::compute_plan( const Vector &p, const Vector &q, const Vector &r  )
{
	this->n[0] = ( q[1] - p[1] ) * ( r[2] - p[2] ) - ( q[2] - p[2] ) * ( r[1] - p[1] );
	this->n[1] = ( q[2] - p[2] ) * ( r[0] - p[0] ) - ( q[0] - p[0] ) * ( r[2] - p[2] );
	this->n[2] = ( q[0] - p[0] ) * ( r[1] - p[1] ) - ( q[1] - p[1] ) * ( r[0] - p[0] );
	this->d = - ( this->n[0] * p[0] + this->n[1] * p[1] + this->n[2] * p[2] );
}
