// Vector  
// Changelog 02.02.07

#ifndef __Vector__
#define __Vector__

#include <math.h>

//! \class Vector vector.h
//! \brief Cette classe définit des vecteurs et des sommets dans l'espace.
class Vector
{
protected:
  double x,y,z;
public:
  Vector() { }
  Vector(const double& a, const double& b, const double& c) { x=a; y=b; z=c; }

  // Functions to access Vector class components
  double& operator[] (int i) {
    if (i == 0)    return x;
    else if (i == 1) return y;
    else	     return z;
  }

  const double operator[] (int i) const {
    if (i == 0)    return x;
    else if (i == 1) return y;
    else	     return z;
  }

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

  friend double operator* (const Vector&, const Vector&);

  friend Vector operator* (const Vector&, double);
  friend Vector operator* (double, const Vector&);
  friend Vector operator/ (const Vector&, double);

  friend Vector operator/ (const Vector&, const Vector&);

  // Boolean functions
  friend int operator==(const Vector&,const Vector&);
  friend int operator!=(const Vector&,const Vector&);
  friend int operator<(const Vector&,const Vector&);
  friend int operator>(const Vector&,const Vector&);
  friend Vector min(const Vector&,const Vector&);
  friend Vector max(const Vector&,const Vector&);

  friend Vector Orthogonal(const Vector&);

  // Norm
  friend double Norm(const Vector&);
};

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

// Binary operators
inline Vector operator+ (const Vector& u, const Vector& v)
{
  return Vector(u.x+v.x,u.y+v.y,u.z+v.z);
}

inline Vector operator- (const Vector& u, const Vector& v)
{
  return Vector(u.x-v.x,u.y-v.y,u.z-v.z);
}

// Scalar product
inline double operator* (const Vector& u, const Vector& v)
{
  return (u.x*v.x+u.y*v.y+u.z*v.z);
}

inline Vector operator* (const Vector& u,double a)
{
  return Vector(u.x*a,u.y*a,u.z*a);
}

inline Vector operator* (double a, const Vector& v)
{
  return v*a;
}

// Cross product
inline Vector operator/ (const Vector& u, const Vector& v)
{
  return Vector(u.y*v.z-u.z*v.y,u.z*v.x-u.x*v.z,u.x*v.y-u.y*v.x);
}

inline Vector operator/ (const Vector& u, double a)
{
  return Vector(u.x/a,u.y/a,u.z/a);
}

// Boolean functions
inline int operator== (const Vector& u,const Vector& v)
{
  return ((u.x==v.x)&&(u.y==v.y)&&(u.z==v.z));
}

inline int operator!= (const Vector& u,const Vector& v)
{
  return (!(u==v));
}

/*!
\brief Compute the Euclidean norm of a vector.
*/
inline double Norm(const Vector& u)
{
  return sqrt(u.x*u.x+u.y*u.y+u.z*u.z);
}


inline int operator<(const Vector& a,const Vector& b)
{
  return ((a.x<b.x)&&(a.y<b.y)&&(a.z<b.z));
}

inline int operator>(const Vector& a,const Vector& b)
{
  return ((a.x>b.x)&&(a.y>b.y)&&(a.z>b.z));
}

/*!
\brief Return a new vector with coordinates set to the minimum coordinates
of the two argument vectors.
*/
inline Vector min(const Vector& a,const Vector& b)
{
  return Vector(a[0]<b[0]?a[0]:b[0],a[1]<b[1]?a[1]:b[1],a[2]<b[2]?a[2]:b[2]);
}

/*!
\brief Return a new vector with coordinates set to the maximum coordinates
of the two argument vectors.
*/
inline Vector max(const Vector& a,const Vector& b)
{
  return Vector(a[0]>b[0]?a[0]:b[0],a[1]>b[1]?a[1]:b[1],a[2]>b[2]?a[2]:b[2]);
}


/*!
\brief Returns a new vector orthogonal to the argument vector.
*/
inline Vector Orthogonal(const Vector& u)
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
#endif

