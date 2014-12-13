// Changelog 14.02.2001

#ifndef __X11_GL__
#define __X11_GL__

#include <GL/glew.h>
#include <GL/glut.h>

#include "vector.h"

inline void Vertex3D(const Vector& p) 
{
  glVertex3d(p[0],p[1],p[2]);
}
 
inline void Normal3D(const Vector& n)
{
  glNormal3d(n[0],n[1],n[2]);
}

void GlutShade(GLfloat r,GLfloat v,GLfloat b);

#endif
