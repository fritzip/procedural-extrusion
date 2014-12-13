
#include <GL/glew.h>
#include <GL/glut.h>									
#include <GL/glu.h>
#include <GL/gl.h>	

#include <iostream>

#include "shape.h"

#include "vector.h"
#include "main.h"

const double Pi=3.14159265358979323846;

Cylinder::Cylinder(const Vector& a,const Vector& b,const double& r,int n)
{
  Cylinder::a=a;
  Cylinder::b=b;
  Cylinder::r=r;
  Cylinder::n=n;

  box=Box(a,b);
  //CreateVBO();
}
                
void Cylinder::Render()
{
  GlutShade(0.8,0.9,0.6);

  Vector u = b-a ;
  Vector axis=u*(1.0/Norm(u));

  // MayaFrame
  Vector x=Orthogonal(axis);
  Vector y=axis/x;

  x = x*(1.0/Norm(x));
  y = y*(1.0/Norm(y));

  glBegin(GL_QUADS);

  // Vertices and normals
  for (int i=0;i<n;i++) 
  {
    double t1=2.0*Pi*double(i)/double(n);
    Vector u1=x*cos(t1)+y*sin(t1);

    glNormal3f( u1[0], u1[1],u1[2]);
    glVertex3f( (a+r*u1)[0],(a+r*u1)[1],(a+r*u1)[2]);
    glVertex3f( (b+r*u1)[0],(b+r*u1)[1],(b+r*u1)[2]);
    
    double t2=2.0*Pi*double(i+1)/double(n);
    Vector u2=x*cos(t2)+y*sin(t2);

    glNormal3f( u2[0], u2[1],u2[2]);
    glVertex3f( (b+r*u2)[0],(b+r*u2)[1],(b+r*u2)[2]);
    glVertex3f( (a+r*u2)[0],(a+r*u2)[1],(a+r*u2)[2]);
  }

  glEnd();

  glBegin(GL_TRIANGLES);

  // Vertices and normals
  for (int i=0;i<n;i++) 
  {
    double t1=2.0*Pi*double(i)/double(n);
    Vector u1=x*cos(t1)+y*sin(t1);

    glNormal3f( u1[0], u1[1],u1[2]);
    glVertex3f( (a+r*u1)[0],(a+r*u1)[1],(a+r*u1)[2]);
    glVertex3f( (b+r*u1)[0],(b+r*u1)[1],(b+r*u1)[2]);
    
    double t2=2.0*Pi*double(i+1)/double(n);
    Vector u2=x*cos(t2)+y*sin(t2);

    glNormal3f( u2[0], u2[1],u2[2]);
    glVertex3f( (b+r*u2)[0],(b+r*u2)[1],(b+r*u2)[2]);
    glVertex3f( (a+r*u2)[0],(a+r*u2)[1],(a+r*u2)[2]);
  }

  glEnd();
}

