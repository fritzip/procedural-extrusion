#ifndef __PLANE_H__
#define __PLANE_H__

#include <vector>

#include "vector.h"
#include "profile.h"

class Plane
{
	Vector n;
	double d;
	std::vector<Vector*> vertex;

public:
	Plane();
	Plane(const Vector &p1, const Vector &p2, const RTco &pol);
	// Plane(const Vector &normale, double _d, const Vector &p1, const Vector &p2, Vector prof1);
	~Plane();

	double operator[] (int i) const ;

	const Vector& get_norm() const ;
	const std::vector<Vector*>& get_vert() const ;
	
	Vector* compute_dir_plane(Vector *p1, Vector *p2, RTco &pol);
	Vector* compute_3rd_point(Vector *p1, Vector *p2, RTco &pol);
	void compute_plan( const Vector &p, const Vector &q, const Vector &r  );
	friend Vector* intersect_3_planes( const Plane &p1, const Plane &p2, const Plane &p3 );

};

/*************************************/
//			Out-of-class functions
/*************************************/
int intersect_is_point( const Plane &p1, const Plane &p2, const Plane &p3 );

Vector* intersect_3_planes( const Plane &p1, const Plane &p2, const Plane &p3 );

#endif