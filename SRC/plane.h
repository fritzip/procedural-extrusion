#ifndef __PLANE_H__
#define __PLANE_H__

#include <vector>

#include "vector.h"

class Plane
{
	Vector n;
	double d;
	std::vector<Vector> vertex;

public:
	Plane();
	Plane(const Vector &normale, double _d, const Vector &coc1, const Vector &coc2, Vector prof1);
	~Plane();

	// double& operator[] (int i) ;
	double operator[] (int i) const ;

	const Vector& get_norm() const ;

	const std::vector<Vector>& get_vert() const ;
	
	void compute_plan( const Vector &p, const Vector &q, const Vector &r  );

};

/*************************************/
//			Out-of-class functions
/*************************************/
int intersect_is_point( const Plane &p1, const Plane &p2, const Plane &p3 );

Vector intersect_3_planes( const Plane &p1, const Plane &p2, const Plane &p3 );

#endif