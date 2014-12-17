/*****************************************************************************/
//
//									Plane
//
/*****************************************************************************/
#include <iostream>
#include <math.h>
#include <eigen3/Eigen/Dense>

#include "plane.h"

#define PI 3.14159265

using namespace std;
using namespace Eigen;

/*************************************/
//			Constructors
/*************************************/
Plane::Plane() : n(), d(0), vertex()
{}

Plane::Plane(const Vector &p1, const Vector &p2, const RTco &pol)
{
	// cout << p1 << endl;
	Vector third(compute_3rd_point(p1, p2, pol));
	compute_plan(p1, p2, third);
	cout << "n = " << n << ", d = " << d << endl;
	vertex.push_back(p1);
	vertex.push_back(p2);
	vertex.push_back(third);
}

Plane::Plane(const Vector &normale, double _d, const Vector &p1, const Vector &p2, Vector prof1) : n(normale), d(_d), vertex({p1, p2, prof1})
{
	compute_plan(p1, p2, prof1);
}

/*************************************/
//			Destructors
/*************************************/
Plane::~Plane()
{}

/*************************************/
//			Public methods
/*************************************/
Vector Plane::compute_3rd_point(const Vector &p1, const Vector &p2, const RTco &pol)
{
	Vector p12(p2-p1);
	double phi = atan2(p12[1], p12[0]);
	// cout << "angle = " << phi*180 / PI << endl;

	// Vector p3(p1[0]*4, p2[1], p1[2]);
	// Vector p21(p2-p1), p13(p1-p3), p23(p2-p3) ;
	Vector med12((p1 + p2) / 2);
	// cout << "p1 : " << p1 << endl;
	// cout << "p2 : " << p2 << endl;
	// cout << "p3 : " << p3 << endl;
	// // cout << "xyzi : " << xyzi << endl;
	// cout << "p21 : " << p21 << ", p13 : " << p13 << ", p23 : " << p23 << endl;
	// double phi = acos( ( norm(p21)*norm(p21) + norm(p23)*norm(p23) - norm(p13)*norm(p13) )  
	// 				/ (2 * norm(p21) * norm(p23) ) );

	double theta = (90 - pol.theta) * PI / 180 ;
	cout << "theta = " << theta*180/PI << ", phi = " << phi*180/PI << endl;
	double xm = -pol.r * sin(phi) * cos(theta) + med12[0];
	double ym = pol.r * cos(theta) * cos(phi) + med12[1];
	double zm = pol.r * sin(theta) + med12[2]; 

	Vector out(xm, ym, zm);
	cout << "OUT : " << out << endl;
	return out;
}

void Plane::compute_plan( const Vector &p, const Vector &q, const Vector &r  )
{
	n[0] = ( q[1] - p[1] ) * ( r[2] - p[2] ) - ( q[2] - p[2] ) * ( r[1] - p[1] );
	n[1] = ( q[2] - p[2] ) * ( r[0] - p[0] ) - ( q[0] - p[0] ) * ( r[2] - p[2] );
	n[2] = ( q[0] - p[0] ) * ( r[1] - p[1] ) - ( q[1] - p[1] ) * ( r[0] - p[0] );
	d = - ( n[0] * p[0] + n[1] * p[1] + n[2] * p[2] );
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