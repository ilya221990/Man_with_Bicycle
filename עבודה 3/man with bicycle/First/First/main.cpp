#include "GLUT.h"
#include <math.h>
double offset = 0;
double  PI  = 3.14;
double roadFunc = 0, angle = 0;
void init()
{
	glClearColor(0, 0, 0.5, 0); // background color

	// set main axes
	glOrtho(-1,1,-1,1,-1,1);
}

void drawRoad()
{
	double x, y;
	glColor3d(1, 1, 1);
	glLineWidth(1);
	glBegin(GL_LINE_STRIP);// GL_LINE_STRIP);
	for (x = -2; x <= 2; x += 0.001)
	{
		y = 0.1*cos(2 * x + offset);
		//y = 0.2*sin(5 * x + offset);
		glVertex2d(x, y);
	}
	glEnd();

}

void drawWheel()
{

	double alpha, x, y, r = 1, delta = PI / 18;

	glLineWidth(1);
	glColor3d(1, 1, 1);
	glBegin(GL_LINE_STRIP);

	for (alpha = 0; alpha <= 2 * PI; alpha += delta)
	{
		x = r*cos(alpha);
		y = r*sin(alpha);
		glVertex2d(x, y);
	}
	glEnd();

	for (alpha = 0; alpha < 2 * PI; alpha += 3 * delta)
	{
		glBegin(GL_LINES);
		x = r*cos(alpha);
		y = r*sin(alpha);
		glVertex2d(x, y);
		glVertex2d(0, 0);
		glEnd();
	}
}

void drawBicycle()
{
	glColor3d(0, 1, 0);
	glLineWidth(5);
	glBegin(GL_LINES);     //handlebars
	glVertex2d(0.05, 0.2);
	glVertex2d(0,0);
	glEnd();

	glBegin(GL_LINES);     //handlebars
	glVertex2d(0.05, 0.2);
	glVertex2d(0, 0.2);
	glEnd();

	glBegin(GL_LINES);     //connections
	glVertex2d(0.2, 0);
	glVertex2d(0.03, 0.15);
	glEnd();

	glBegin(GL_LINES);     //connections
	glVertex2d(0.2, 0);
	glVertex2d(0.4, 0);
	glEnd();


	glBegin(GL_LINES);     //seat
	glVertex2d(0.2, 0);
	glVertex2d(0.3, 0.15);
	glEnd();



	glBegin(GL_LINES);     //seat
	glVertex2d(0.23, 0.15);
	glVertex2d(0.32, 0.15);
	glEnd();


	glBegin(GL_LINES);     //connections
	glVertex2d(0.27, 0.11);
	glVertex2d(0.4, 0);
	glEnd();


	glBegin(GL_LINES);     //connections
	glVertex2d(0.27, 0.11);
	glVertex2d(0.03,0.14);
	glEnd();





}

void drawHuman()
{
	glColor3d(1, 1, 0);
	glLineWidth(5);
	glBegin(GL_LINES);     //hands
	glVertex2d(0, 0.21);
	glVertex2d(0.13, 0.22);
	glEnd();


	glBegin(GL_LINES);     //neck
	glVertex2d(0.12, 0.32);
	glVertex2d(0.13, 0.22);
	glEnd();

	glBegin(GL_LINES);     //back
	glVertex2d(0.12, 0.32);
	glVertex2d(0.29, 0.17);
	glEnd();

	glPushMatrix();
	glRotated(100 * -offset, 0.29, 0.17,0);
	glBegin(GL_LINES);     //high leg
	glVertex2d(0.29, 0.17);
	glVertex2d(0.16, 0.15);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	//glRotated(100 * -offset, 0.16, 0.15, 0.1);

	//glTranslated(0.20, 0.06, 0); // 3
	//glRotated(100 * -offset,0 , 0,0.5);  // 2 
	//glTranslated(-0.2, -0.06, 0); // 1

	glBegin(GL_LINE_STRIP);     //high leg
	
	glvertex2d(0.16, 0.15);
	glvertex2d(0.20, 0.06);
	glEnd();
	glPopMatrix();

	glBegin(GL_LINES); //high leg
	
	glvertex2d(0.20, 0.06);
	glVertex2d(0.15, 0.06);
	//glRotated(100 * -offset, 0, 0, 1);
	glEnd();

	glBegin(GL_LINES);     //low leg
	glVertex2d(0.29, 0.17);
	glVertex2d(0.22, 0.08);
	glEnd();

	glBegin(GL_LINES);     //low leg
	glVertex2d(0.22, 0.08);
	glVertex2d(0.2, -0.05);
	glEnd();

	glBegin(GL_LINES);     //low leg
	glVertex2d(0.21, -0.05);
	glVertex2d(0.16, -0.05);
	glEnd();

	
}
void drawHead() 
{
	double alpha, x, y, r = 1, delta = PI / 18;

	glLineWidth(3);
	glColor3d(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (alpha = 0; alpha <= 2 * PI; alpha += delta)
	{
		x = r*cos(alpha);
		y = r*sin(alpha);
		glVertex2d(x, y);
	}
	glEnd();

	glColor3d(1, 1, 1);
	glBegin(GL_POLYGON);
	for (alpha = 0; alpha <= 2 * PI; alpha += delta)
	{
		x = (r-0.1)*cos(alpha);
		y = (r - 0.1)*sin(alpha);
		glVertex2d(x, y);
	}
	glEnd();

}

void drawAll()
{
	//first wheel
	glPushMatrix();
	glTranslated(-0.2, 0, 0);
	glRotated(100 * -offset, 0, 0, 1);
	glScaled(0.12, 0.12, 0.12);
		drawWheel();
	glPopMatrix();

	//second wheel
	glPushMatrix();
	glTranslated(0.2, 0, 0);
	glRotated(100 * -offset, 0, 0, 1);
	glScaled(0.12, 0.12, 0.12);

		drawWheel();
	glPopMatrix();

	//small third wheel
	glPushMatrix();
		glTranslated(0, 0, 0);
	glRotated(100 * -offset, 0, 0, 1);
	glScaled(0.04, 0.04, 0.04);
		drawWheel();
	glPopMatrix();

	//draw handlebar
	glPushMatrix();
		glTranslated(-0.2, 0, 0);
		drawBicycle();
	glPopMatrix();

	// draw human body 
	glPushMatrix();
		glTranslated(-0.2, 0, 0);
		drawHuman(); 
	glPopMatrix();

	// draw human Head
	glPushMatrix();
		glScaled(0.05, 0.05, 0);
		glTranslated(-2, 7, 0);
		drawHead();
	glPopMatrix();





}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);// fills frame buffer with background color
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
		glTranslated(-1, 0, 0);
		drawRoad();
	glPopMatrix();

	glPushMatrix();
		glRotated(angle * 180 / PI, 0, 0, 1);
		glTranslated(0, roadFunc + 0.12, 0);
		drawAll();
	glPopMatrix();

	
	glutSwapBuffers(); // show what was drawn for double buffer
}

void idle()
{
	
	offset -= 0.0005;
	for (double x = -1; x <= 1; x += 0.001)
	{
		roadFunc =  0.1*cos(2 * x + offset);//0.2*sin(5 * x + offset);
		angle =sin(2 * x + offset) / -5; //cos(5 * x + offset) / 5;
	}
	glutPostRedisplay();
}



void main(int argc, char* argv[])
{
	glutInit(&argc, argv); // initializes OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//GLUT_SINGLE );
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("First example");

	glutDisplayFunc(display); // window refresh 
	glutIdleFunc(idle);
	init();
	
	glutMainLoop();
}