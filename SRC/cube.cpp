
#include <GL/glew.h>
#include <GL/glut.h>									
#include <GL/glu.h>
#include <GL/gl.h>	

#include <iostream>

#include "shape.h"

#include "vector.h"
#include "main.h"



Cube::Cube(const Vector& a,const Vector& b)
{
  Cube::a=a;
  Cube::b=b;
  box=Box(a,b);
  //CreateVBO();
}
                
void Cube::Render()
{
  GlutShade(0.8,0.9,0.6);
    glBegin(GL_QUADS);

  // Face z=-1
  glNormal3f( 0.0f, 0.0f,-1.0f);
  glVertex3f(-1.0f,-1.0f,-1.0f);
  glVertex3f(-1.0f, 1.0f,-1.0f);
  glVertex3f( 1.0f, 1.0f,-1.0f);
  glVertex3f( 1.0f,-1.0f,-1.0f);

  // Face z=+1
  glNormal3f( 0.0f, 0.0f, 1.0f);
  glVertex3f(-1.0f,-1.0f, 1.0f);
  glVertex3f( 1.0f,-1.0f, 1.0f);
  glVertex3f( 1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);

  // Face x=-1
  glNormal3f(-1.0f,0.0f,0.0f);
  glVertex3f(-1.0f,-1.0f,-1.0f);
  glVertex3f(-1.0f, 1.0f,-1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f(-1.0f,-1.0f, 1.0f);

  // Face x=+1
  glNormal3f( 1.0f, 0.0f, 0.0f);
  glVertex3f( 1.0f,-1.0f,-1.0f);
  glVertex3f( 1.0f, 1.0f,-1.0f);
  glVertex3f( 1.0f, 1.0f, 1.0f);
  glVertex3f( 1.0f,-1.0f, 1.0f);

  // Face y=-1
  glNormal3f( 0.0f,-1.0f, 0.0f);
  glVertex3f(-1.0f,-1.0f,-1.0f);
  glVertex3f( 1.0f,-1.0f,-1.0f);
  glVertex3f( 1.0f,-1.0f, 1.0f);
  glVertex3f(-1.0f,-1.0f, 1.0f);

  // Face y=+1
  glNormal3f( 0.0f, 1.0f, 0.0f);
  glVertex3f(-1.0f, 1.0f,-1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);
  glVertex3f( 1.0f, 1.0f, 1.0f);
  glVertex3f( 1.0f, 1.0f,-1.0f);

  glEnd();
}
