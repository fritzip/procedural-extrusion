// Affichage OpenGL

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>										
#include <GL/glu.h>

#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>


#include "vector.h"
#include "shape.h"
// #include "profile.h"
#include "house.h"

using namespace std;

// Identifiant de la racine de la scene
Node *scene=NULL;

// Angle de rotation des objects
float alpha=0.0f;

int Mousekey=0,Mousex,Mousey;

int light=1;
int rotate=1;

// Identifiant de fenetre
int window;






// angle of rotation for the camera direction
float angle = 0.0f;

// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=0.0f, z=5.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;






// Gestion du clavier.
void Keyboard(unsigned char key, int x, int y)
{
	// Si ESC
	if (key==27)
	{
		glutDestroyWindow(window); 
		exit(0);
	}
	// Gestion des lumieres
	if ((key=='l') || (key=='L'))
	{
		light = 1-light;
		if (!light) 
		{
			glDisable(GL_LIGHTING);
		} 
		else 
		{
			glEnable(GL_LIGHTING);
		}
	}
	if ((key=='r') || (key=='R'))
	{
		rotate = 1-rotate;
	}
	glutPostRedisplay();
}

void Resize(int width, int height)
{
	// Evite de divisser par 0 en cas de changement de taille
	if (height==0)				
	{
		height=1;
	}
	// Fenetrage
	glViewport (0, 0, width, height);

	// Definition de la matrice de vue
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();  

	// Camera
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	// Rebascule dans le repere du modele
	glMatrixMode(GL_MODELVIEW);
}

// Permet de definir une matiere a partir d'une couleur
void GlutShade(GLfloat r,GLfloat v,GLfloat b)
{
	// Couleur sans lumieres
	glColor3f(0.8,0.9,0.6);

	// Couleur avec lumieres
	GLfloat color[4];

	// La couleur diffuse sera egale a 25% de la couleur
	color[0]=0.75f*r;
	color[1]=0.75f*v;
	color[2]=0.75f*b;
	color[3]=1.0;

	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);

	// La couleur ambiante sera egale a 25% de la couleur
	color[0]=0.25f*r;
	color[1]=0.25f*v;
	color[2]=0.25f*b;
	color[3]=1.0;

	glMaterialfv(GL_FRONT, GL_AMBIENT, color); // GL_AMBIENT_AND_DIFFUSE

	color[0]=1.0f;
	color[1]=0.0f;
	color[2]=0.0f;
	color[3]=1.0;

	glMaterialfv(GL_BACK, GL_AMBIENT_AND_DIFFUSE, color);
}

void computePos(float deltaMove)
{
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

// Affichage
void GlutRendering()
{

	if (deltaMove)
		computePos(deltaMove);
	
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode (GL_MODELVIEW);
	// glLoadIdentity ();

	// glRotatef(alpha,1.0f,1.0f,1.0f);

		// Reset transformations
	glLoadIdentity();
	// Set the camera
	glTranslatef(0.0f,0.0f,-10.0f);	
	gluLookAt(  x+lx, 1.0f, z+lz,
			x, 1.0f,  z,
			0.0f, 1.0f,  0.0f);


	scene->Render();

	glutSwapBuffers();
}

void MouseMove(int x, int y)
{
	Mousex = x;
	Mousey = y;
}

void MousePush(int button, int state, int x, int y)
{
}

void mouseMove(int x, int y) 
{  
	// this will only be true when the left button is down
	if (xOrigin >= 0) 
	{
		// update deltaAngle
		deltaAngle = ( xOrigin - x ) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
	 if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

// Rafraichissement
void GlutIdle(void)
{
	if (rotate)
	{
		alpha+=0.25;
	}
	GlutRendering();
}

//!Initialise OpenGL
void InitGlut(int width,int height)
{  
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA | GLUT_DEPTH);

	// Fenetre initiale
	glutInitWindowSize(512, 512);  
	glutInitWindowPosition(0, 0);  
	window=glutCreateWindow("Real Time Rendering");

	glutDisplayFunc(GlutRendering);
	//glutFullScreen();

	// Rafraichissement
	glutIdleFunc(&GlutIdle);

	// Changement de taille
	glutReshapeFunc(Resize);

	// Clavier
	glutKeyboardFunc(Keyboard);
	//glutSpecialFunc(&SpecialKeyboard);

	// Souris
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// Initialise les parametres de rendu
	glClearColor (0.3f, 0.4f, 0.6f, 1.0);

	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glShadeModel(GL_SMOOTH);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();				// Reset The Projection Matrix

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

	// Placement des lumieres dans l'espace du modele
	glMatrixMode(GL_MODELVIEW);

	GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_position[] = { 0.0,0.0, 10.0,0.0 };

	glLightfv (GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv (GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv (GL_LIGHT1, GL_POSITION, light_position);
	glEnable(GL_LIGHT0); 

	glEnable(GL_LIGHTING);

	// Elimination des facettes arriere
	//glCullFace(GL_BACK);
	//glEnable(GL_CULL_FACE);
}


int main(int argc, char **argv)
{
	// glutInit(&argc, argv);
	// InitGlut(512,512);
	// glewInit();

	// scene=new Cube(Vector(-1,-1,-2),Vector(2,3,1));
	// scene=new Cylinder(Vector(0,0,0),Vector(0,0,1),0.5,30);

	Corner *c1 = new Corner(0.0,  0.0,  0.0);
	Corner *c2 = new Corner(10.0, 0.0,  0.0);
	Corner *c3 = new Corner(10.0, 10.0, 0.0);
	Corner *c4 = new Corner(0.0,  10.0, 0.0);
	Profile *pr1 = new Profile({ RTco{15,45} });
	Profile *pr2 = new Profile({ RTco{15,45} });
	Profile *pr3 = new Profile({ RTco{15,45} });
	Profile *pr4 = new Profile({ RTco{15,45} });

	Plan *input_plan = new Plan(0);
	input_plan->append( c1, pr1 );
	input_plan->append( c2, pr2 );
	input_plan->append( c3, pr3 );
	input_plan->append( c4, pr4 );
	input_plan->finish();

	House *ma_maison = new House();
	ma_maison->extrude(input_plan);

	// glutMainLoop();
	return 0;
}