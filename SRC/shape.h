// Changelog 14.02.2001

#ifndef __Shape__ 
#define __Shape__

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>										
#include <GL/glu.h>

#include <iostream>

#include "vector.h"
#include "box.h"

GLuint GenerateCube();

class Node {
protected:
  Box box;
public:
  virtual void Render()=0;
  Box GetBox() { return box; } 
};

class Union:public Node {
protected:
  Node* a;
  Node* b;
public:
  Union(Node*,Node*);
  ~Union();
  virtual void Render();
};

class Cube:public Node {
protected:
  Vector a;
  Vector b;

public:
  Cube(const Vector&,const Vector&);
  virtual void Render();

};

class Cylinder:public Node {
protected:
  Vector a;
  Vector b;
  double r;
  int n;

public:
  Cylinder(const Vector&,const Vector&,const double&,int);
  virtual void Render();

};

#endif
