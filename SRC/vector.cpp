/*****************************************************************************/
//
//									Vector"
//
/*****************************************************************************/
#include <iostream>
#include "vector.h"

using namespace std;

/*************************************/
//			Constructors
/*************************************/
Vector::Vector() : x(0), y(0), z(0) 
{}

Vector::Vector(const double& a, const double& b, const double& c) 
{ 
	x=a; y=b; z=c; 
}

/*************************************/
//			Destructors
/*************************************/
Vector::~Vector()
{}

/*************************************/
//			Public methods
/*************************************/


/*************************************/
//			Operators overloading
/*************************************/
// Functions to access Vector class components
double& Vector::operator[] (int i) 
{
	if      (i == 0) return x;
	else if (i == 1) return y;
	else             return z;
}

const double Vector::operator[] (int i) const 
{
	if      (i == 0) return x;
	else if (i == 1) return y;
	else             return z;
}


// Unary operators
inline Vector Vector::operator+ () const
{
	return *this;
}

inline Vector Vector::operator- () const
{
	return Vector(-x,-y,-z);
}

// Assignment unary operators
inline Vector& Vector::operator+= (const Vector& u)
{
	x+=u.x; y+=u.y; z+=u.z;
	return *this;
}

inline Vector& Vector::operator-= (const Vector& u)
{
	x-=u.x; y-=u.y; z-=u.z;
	return *this;
}

inline Vector& Vector::operator*= (double a)
{
	x*=a; y*=a; z*=a;
	return *this;
}

inline Vector& Vector::operator/= (double a)
{
	x/=a; y/=a; z/=a;
	return *this;
}

inline Vector& Vector::operator*= (const Vector& u)
{
	x*=u.x; y*=u.y; z*=u.z;
	return *this;
}

inline Vector& Vector::operator/= (const Vector& u)
{
	x/=u.x; y/=u.y; z/=u.z;
	return *this;
}

void Vector::print(ostream &flux) const
{
	flux << "x = " << x << ", y = " << y << ", z = " << z ;
}

/*************************************/
//			Out-of-class functions
/*************************************/
double det2(const double a, const double b, const double c, const double d)
{
	return a * d - c * b;
}

double det3(const Vector &p1, const Vector &p2, const Vector &p3)
{
	return det2( p1[0], p2[0], p1[1], p2[1] )
		-  det2( p1[0], p3[0], p1[1], p3[1] )
		+  det2( p2[0], p3[0], p2[1], p3[1] ) ;
}

double dot(const Vector &u, const Vector &v)
{
	return ( u[0]*v[0] + u[1]*v[1] + u[2]*v[2] );
}

/*!
\brief Return a new vector with coordinates set to the minimum coordinates
of the two argument vectors.
*/
Vector min(const Vector& a, const Vector& b)
{
	return Vector(a[0]<b[0]?a[0]:b[0],a[1]<b[1]?a[1]:b[1],a[2]<b[2]?a[2]:b[2]);
}

/*!
\brief Return a new vector with coordinates set to the maximum coordinates
of the two argument vectors.
*/
Vector max(const Vector& a, const Vector& b)
{
	return Vector(a[0]>b[0]?a[0]:b[0],a[1]>b[1]?a[1]:b[1],a[2]>b[2]?a[2]:b[2]);
}


/*!
\brief Returns a new vector orthogonal to the argument vector.
*/
Vector orthogonal(const Vector& u)
{  
	Vector a=Vector(fabs(u[0]),fabs(u[1]),fabs(u[2]));
	int i=0;
	int j=1;
	if (a[0]>a[1])
	{
		if (a[2]>a[1])
		{
			j=2;
		}
	}
	else
	{
		i=1;
		j=2;
		if (a[0]>a[2])
		{
			j=0;
		}
	}
	a=Vector(0.0,0.0,0.0);
	a[i]=u[j];
	a[j]=-u[i];
	return a;
}


/*!
\brief Compute the Euclidean norm of a vector.
*/
double norm(const Vector& u)
{
	return sqrt(u[0]*u[0]+u[1]*u[1]+u[2]*u[2]);
}

ostream &operator<<( ostream &flux, const Vector &v)
{
	v.print(flux) ;
	return flux;
}