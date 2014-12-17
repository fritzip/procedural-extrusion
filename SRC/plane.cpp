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

// Plane::Plane(const Vector &p1, const Vector &p2, const RTco &pol)
// {}

// Plane::Plane(const Vector &normale, double _d, const Vector &p1, const Vector &p2, Vector prof1) : n(normale), d(_d), vertex({p1, p2, prof1})
// {
// 	compute_plan(p1, p2, prof1);
// }

/*************************************/
//			Destructors
/*************************************/
Plane::~Plane()
{
	cout << "Destroy Plane" << endl;
	// for(size_t i = 0; i < vertex.size(); ++i)
	// 	delete vertex[i];
}

/*************************************/
//			Public methods
/*************************************/
void Plane::compute_dir_plane(Vector *p1, Vector *p2, RTco &pol)
{
	// cout << p1 << endl;

	vertex.reserve(10);
	Vector *v1 = p1; // new Vector(p1);
	Vector *v2 = p2; //new Vector(p2);
	Vector *v3 = compute_3rd_point(p1, p2, pol);
	vertex.push_back(v1);
	vertex.push_back(v2);
	vertex.push_back(v3);
	
	compute_plan(*v1, *v2, *v3);
	cout << "n = " << n << ", d = " << d << endl;
	// vertex.push_back(third);
}

Vector* Plane::compute_3rd_point(Vector *p1, Vector *p2, RTco &pol)
{
	Vector p12((*p2)-(*p1));
	double phi = atan2(p12[1], p12[0]);
	// cout << "angle = " << phi*180 / PI << endl;

	// Vector p3(p1[0]*4, p2[1], p1[2]);
	// Vector p21(p2-p1), p13(p1-p3), p23(p2-p3) ;
	Vector med12(((*p1) + (*p2)) / 2);
	// cout << "p1 : " << p1 << endl;
	// cout << "p2 : " << p2 << endl;
	// cout << "p3 : " << p3 << endl;
	// // cout << "xyzi : " << xyzi << endl;
	// cout << "p21 : " << p21 << ", p13 : " << p13 << ", p23 : " << p23 << endl;
	// double phi = acos( ( norm(p21)*norm(p21) + norm(p23)*norm(p23) - norm(p13)*norm(p13) )  
	// 				/ (2 * norm(p21) * norm(p23) ) );

	double theta = (90 - pol.theta) * PI / 180 ;
	// cout << "theta = " << theta*180/PI << ", phi = " << phi*180/PI << endl;
	double xm = -pol.r * sin(phi) * cos(theta) + med12[0];
	double ym =  pol.r * cos(theta) * cos(phi) + med12[1];
	double zm =  pol.r * sin(theta) + med12[2]; 

	Vector *out = new Vector(xm, ym, zm);
	cout << "OUT : " << *out << endl;
	return out;
}

void Plane::compute_plan( const Vector &p, const Vector &q, const Vector &r  )
{
	// n[0] = ( q[1] - p[1] ) * ( r[2] - p[2] ) - ( q[2] - p[2] ) * ( r[1] - p[1] );
	// n[1] = ( q[2] - p[2] ) * ( r[0] - p[0] ) - ( q[0] - p[0] ) * ( r[2] - p[2] );
	// n[2] = ( q[0] - p[0] ) * ( r[1] - p[1] ) - ( q[1] - p[1] ) * ( r[0] - p[0] );

	n = normalize(cross(p-q, p-r));
	d = ( n[0] * p[0] + n[1] * p[1] + n[2] * p[2] );
	// double dq = ( n[0] * q[0] + n[1] * q[1] + n[2] * q[2] );
	// double dr = ( n[0] * r[0] + n[1] * r[1] + n[2] * r[2] );
	// cout << dot(n, p-q-r) << endl;
	// cout << dot(n, q-r+p) << endl;
	// cout << dot(n, r-p-p) << endl;
	// cout << "les d : " << dp << " " << dq << " " << dr << endl;
	// d = dp;
}



/*************************************/
//			Getters
/*************************************/
const Vector& Plane::get_norm() const { return n; }

const vector<Vector*>& Plane::get_vert() const { return vertex; }

/*************************************/
//			Setters
/*************************************/


/*************************************/
//			Operators overloading
/*************************************/
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
	lum.setThreshold(1e-5);	
	lumaug.setThreshold(1e-5);
	// cout << "rank mat : " << lum.rank() << ", rank augm mat : " << lumaug.rank() << endl;
	return (lum.rank() == 3 && lumaug.rank() == 3);
}

Vector* intersect_3_planes( const Plane &p1, const Plane &p2, const Plane &p3 )
{
	// Vector *intersect = new Vector(
	// 	 ( (     dot( *(p1.vertex[0]),  p1.n ) * cross( p2.n , p3.n ) ) 
	// 	+      ( dot( *(p2.vertex[0]),  p2.n ) * cross( p3.n , p1.n ) ) 
	// 	+      ( dot( *(p3.vertex[0]),  p3.n ) * cross( p1.n , p2.n ) ) )
	// 	/ ( det3( p1.n, p2.n, p3.n ) ) );
	// return intersect;
	// Vector *intersect = new Vector( (-p1.d*cross(p2.n, p3.n) - p2.d*cross(p1.n, p3.n) - p3.d*cross(p1.n, p2.n) )
	 // / dot(p1.n, cross(p2.n, p3.n)) );
	// return intersect;


    float denom = dot(p1.n, cross(p2.n, p3.n));
 
    if(fabsf(denom) < 0.0001)
		cout << "YAIIIIII ATTENTION" << endl;

    Vector *intersect = new Vector(( dot(*(p1.vertex[1]), p1.n) * cross(p2.n, p3.n)
                + dot(*(p2.vertex[1]), p2.n) * cross(p3.n, p1.n)
                + dot(*(p3.vertex[1]), p3.n) * cross(p1.n, p2.n) ) / denom);
 
    return intersect;


}