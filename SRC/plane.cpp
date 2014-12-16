/*****************************************************************************/
//
//									Plane
//
/*****************************************************************************/
#include <iostream>
#include <eigen3/Eigen/Dense>

#include "plane.h"

using namespace std;
using namespace Eigen;

/*************************************/
//			Constructors
/*************************************/
Plane::Plane() : n(), d(0), vertex()
{}

Plane::Plane(const Vector &normale, double _d, const Vector &coc1, const Vector &coc2, Vector prof1) : n(normale), d(_d), vertex({coc1, coc2, prof1})
{
	compute_plan(coc1, coc2, prof1);
}

/*************************************/
//			Destructors
/*************************************/
Plane::~Plane()
{}

/*************************************/
//			Public methods
/*************************************/
void Plane::compute_plan( const Vector &p, const Vector &q, const Vector &r  )
{
	this->n[0] = ( q[1] - p[1] ) * ( r[2] - p[2] ) - ( q[2] - p[2] ) * ( r[1] - p[1] );
	this->n[1] = ( q[2] - p[2] ) * ( r[0] - p[0] ) - ( q[0] - p[0] ) * ( r[2] - p[2] );
	this->n[2] = ( q[0] - p[0] ) * ( r[1] - p[1] ) - ( q[1] - p[1] ) * ( r[0] - p[0] );
	this->d = - ( this->n[0] * p[0] + this->n[1] * p[1] + this->n[2] * p[2] );
}

/*************************************/
//			Getters
/*************************************/
const Vector& Plane::get_norm() const { return n; }

const vector<Vector>& Plane::get_vert() const { return vertex; }

/*************************************/
//			Setters
/*************************************/


/*************************************/
//			Operators overloading
/*************************************/
// double& Plane::operator[] (int i) 
// {
// 	if      (i == 0) return n[0];
// 	else if (i == 1) return n[1];
// 	else if (i == 2) return n[2];
// 	else             return d;
// }

double Plane::operator[] (int i) const 
{
	if      (i == 0) return n[0];
	else if (i == 1) return n[1];
	else if (i == 2) return n[2];
	else             return d;
}

/*************************************/
//			Out-of-class functions
/*************************************/
int intersect_is_point( const Plane &p1, const Plane &p2, const Plane &p3 )
{
	MatrixXd m(3,3);
	MatrixXd maug(3,4);
	m << p1[0], p1[1], p1[2], p2[0], p2[1], p2[2], p3[0], p3[1], p3[2];
	maug << p1[0], p1[1], p1[2], p1[3], p2[0], p2[1], p2[2], p2[3], p3[0], p3[1], p3[2], p3[3];
	FullPivLU<MatrixXd> lum(m);
	FullPivLU<MatrixXd> lumaug(maug);
	return (lum.rank() == 3 && lumaug.rank() == 3);
}

Vector intersect_3_planes( const Plane &p1, const Plane &p2, const Plane &p3 )
{
	return (((dot(p1.get_vert()[0],  p1.get_norm())*(p2.get_norm()*p3.get_norm()))
		+   (dot(p2.get_vert()[0],  p2.get_norm())*(p1.get_norm()*p3.get_norm()))
		+   (dot(p3.get_vert()[0],  p3.get_norm())*(p1.get_norm()*p2.get_norm())))
		/ (det3(p1.get_norm(), p2.get_norm(), p3.get_norm())));
}