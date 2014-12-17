
#include <GL/glew.h>
#include <GL/glut.h>

#include <iostream>

#include "shape.h"

#include "vector.h"
#include "main.h"

Union::Union(Node* a,Node* b)
{
  Union::a=a;
  Union::b=b;

  box=Box(a->GetBox(),b->GetBox());
}

Union::~Union()
{
  // delete a;
  // delete b;
}

void Union::Render()
{
 a->Render();
 b->Render();
}
