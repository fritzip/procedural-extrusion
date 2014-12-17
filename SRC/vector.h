/*****************************************************************************/
//
//									Vector
//
/*****************************************************************************/
#ifndef __Vector__
#define __Vector__

#include <math.h>
#include <iostream>

//! \class Vector vector.h
//! \brief Cette classe définit des vecteurs et des sommets dans l'espace.
class Vector
{
	protected:
		double x,y,z;
	public:
		Vector() ;
		Vector(Vector const& other);
		Vector(const double& a, const double& b, const double& c) ;

		~Vector();

		// Functions to access Vector class components
		double& operator[] (int i) ;
		const double operator[] (int i) const;

		void print(std::ostream &flux) const;

		// Unary operators
		Vector operator+ () const;
		Vector operator- () const;

		// Assignment operators
		Vector& operator+= (const Vector&);
		Vector& operator-= (const Vector&);
		Vector& operator*= (const Vector&);
		Vector& operator/= (const Vector&);
		Vector& operator*= (double);
		Vector& operator/= (double);

		// Binary operators
		friend Vector operator+ (const Vector&, const Vector&);
		friend Vector operator- (const Vector&, const Vector&);
		friend Vector operator* (const Vector&, const Vector&);
		friend Vector operator* (const Vector&, double);
		friend Vector operator* (double, const Vector&);
		friend Vector operator/ (const Vector&, double);
		friend Vector operator/ (const Vector&, const Vector&);

		// Boolean functions
		friend int operator==(const Vector&,const Vector&);
		friend int operator!=(const Vector&,const Vector&);
		friend int operator<(const Vector&,const Vector&);
		friend int operator>(const Vector&,const Vector&);
};

// Scalar product
double dot(const Vector&, const Vector&);
Vector cross(const Vector&, const Vector&);

// Determinant
double det2(const double a, const double b, const double c, const double d);
double det3(const Vector &p1, const Vector &p2, const Vector &p3);

Vector min(const Vector&,const Vector&);
Vector max(const Vector&,const Vector&);
Vector orthogonal(const Vector&);
// Norm
double norm(const Vector&);

Vector normalize(const Vector&);

std::ostream &operator<<( std::ostream &flux, const Vector &v);

// Binary operators
inline Vector operator+ (const Vector &u, const Vector &v)
{
	return Vector(u[0]+v[0],u[1]+v[1],u[2]+v[2]);
}

inline Vector operator- (const Vector &u, const Vector &v)
{
	return Vector(u[0]-v[0],u[1]-v[1],u[2]-v[2]);
}

// Term to term *
inline Vector operator* (const Vector &u, const Vector &v)
{
	return Vector(u[0]*v[0], u[1]*v[1], u[2]*v[2]);
}

inline Vector operator* (const Vector &u, double a)
{
	return Vector(u[0]*a,u[1]*a,u[2]*a);
}

inline Vector operator* (double a, const Vector &v)
{
	return v*a;
}

// Cross product
inline Vector operator/ (const Vector& u, const Vector& v)
{
	return Vector(u[1]*v[2]-u[2]*v[1],u[2]*v[0]-u[0]*v[2],u[0]*v[1]-u[1]*v[0]);
}

inline Vector operator/ (const Vector& u, double a)
{
	return Vector(u[0]/a,u[1]/a,u[2]/a);
}

// Boolean functions
inline int operator== (const Vector& u,const Vector& v)
{
	return ((u[0]==v[0])&&(u[1]==v[1])&&(u[2]==v[2]));
}

inline int operator!= (const Vector& u,const Vector& v)
{
	return (!(u==v));
}

inline int operator<(const Vector& a,const Vector& b)
{
	return ((a[0]<b[0])&&(a[1]<b[1])&&(a[2]<b[2]));
}

inline int operator>(const Vector& a,const Vector& b)
{
	return ((a[0]>b[0])&&(a[1]>b[1])&&(a[2]>b[2]));
}


#endif