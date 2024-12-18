﻿#include<GL/glut.h>
#include<math.h>

float tx = -1, jx = tx + 1.5, ry = -0.7; 

void time(int)
{
	glutPostRedisplay();
	glutTimerFunc(3, time, 0);
	float speed = 0.001;
	tx += speed;
	if (tx>1.0f)
	{
		tx -= 2.5;
		speed = 0.001;
	}
	jx = tx+1.5;
	
}



void beginGL_POLYGON(float d1,float d, float r) {
	float x, y, angle;
	glBegin(GL_POLYGON);
	for (angle = 0; angle < 2 * 3.14159; angle += 0.01) {
		x = d1 + r * cos(angle);
		y = d + r * sin(angle);
		glVertex2f(x + jx, y + ry);
	}
	glEnd();
}
void beginGL_POLYGONScy(float d1, float d, float r) {
	float x, y, angle;
	glBegin(GL_POLYGON);
	for (angle = 0; angle <  3.14159; angle += 0.01) {
		x = d1 + r * cos(angle);
		y = d + r * sin(angle);
		glVertex2f(x , y );
	}
	glEnd();
}
void drawBackground() {
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.565, 0.024);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glColor3f(0.5f, 0.8f, 0.9f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();
	glColor3f(1, 1, 1);
	beginGL_POLYGONScy(-0.65, 0.8, 0.1);
	beginGL_POLYGONScy(0.6, 0.8, 0.1);
	beginGL_POLYGONScy(-0.2, 0.7, 0.1);
	beginGL_POLYGONScy(0.3, 0.7, 0.1);
	beginGL_POLYGONScy(0.0, 0.9, 0.1);
	glColor3f(1, 1, 0.1);
	beginGL_POLYGONScy(0.92, 0.9, 0.1);

	glBegin(GL_QUADS);
	//glColor3f(0.8, 0.4, 0.2);
	glColor3f(41.0 / 255, 138.0 / 255, 109.0 / 255);
	glVertex2f(-1, -1);
	glVertex2f(0, -1);
	glVertex2f(0, 0.3);
	glVertex2f(-1, 0.3);
	glColor3f(0.7, 0.3, 0.2);
	glVertex2f(-0.7, -1);
	glVertex2f(-0.3, -1);
	glVertex2f(-0.3, -0.3);
	glVertex2f(-0.7, -0.3);

	glVertex2f(-0.9, -0.1);
	glVertex2f(-0.8, -0.2);
	glVertex2f(-0.8, -0.1);
	glVertex2f(-0.9, -0.2);

	glVertex2f(-0.1, -0.1);
	glVertex2f(-0.2, -0.2);
	glVertex2f(-0.2, -0.1);
	glVertex2f(-0.1, -0.2);


	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.9, 0, 0.6);
	glVertex3f(-1 , 0.3 , 0);
	glVertex3f(0 , 0.3, 0);
	glVertex3f(-0.5 , 0.6 , 0);
	glEnd();
}

void drawJerry() {
	//head
	glColor3f(0.6, 0.3216, 0.0235);
	beginGL_POLYGON(-0.5, 0.26, 0.1);
	//body
	beginGL_POLYGON(-0.5, 0.0, 0.2);
	glColor3f(1.0, 1.0, 1.0);
	beginGL_POLYGON(-0.5, -0.02, 0.08);
	// Ears
	glColor3f(0.6, 0.3216, 0.0235);
	
	beginGL_POLYGON(-0.45, 0.38, 0.05);
	beginGL_POLYGON(-0.57,0.38,0.05);
	// Eyes
	glColor3f(0.0, 0.0, 0.0);
	beginGL_POLYGON(-0.47, 0.3, 0.01);
	beginGL_POLYGON(-0.55, 0.3, 0.01);
	//Nose
	glColor3f(1.0, 0.753, 0.796);
	beginGL_POLYGON(-0.5, 0.27, 0.018);
	
	// Feet
	glColor3f(0.6, 0.3216, 0.0235);
	beginGL_POLYGON(-0.6, -0.2, 0.03); 
	beginGL_POLYGON(-0.4, -0.2, 0.03); 
}
void Bodycolor() {
	//The square in the middle of the body
	glColor3f(0.827, 0.827, 0.827);
	glVertex2f(-0.1+tx, -0.1 + ry);
	glVertex2f(0.1+tx, -0.1 + ry);
	glVertex2f(0.1 + tx , .4 + ry);
	glVertex2f(-0.1 + tx, .4 + ry);
}
void drawTom() {
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.5, 0.6);
	glVertex3f(-.2 + tx, -0.2 + ry, 0 );
	glVertex3f(.2 + tx, -0.2 + ry, 0 );
	glVertex3f(0.2 + tx, .5 + ry, 0 );
	glVertex3f(-.2 + tx, .5 + ry, 0 );

	glVertex3f(-.05 + tx, 0.6 + ry, 0);
	glVertex3f(.05 + tx, 0.6 + ry, 0);
	glVertex3f(0.2 + tx, .5 + ry, 0);
	glVertex3f(-.2 + tx, .5 + ry, 0);

	Bodycolor();

	glColor3f(0.4, 0.5, 0.6);
	glVertex3f(-.05 + tx, 0.6 + ry, 0);
	glVertex3f(.05 + tx, 0.6 + ry, 0);
	glVertex3f(0.2 + tx, .7 + ry, 0);
	glVertex3f(-.2 + tx, .7 + ry, 0);

	glVertex3f(0.2 + tx, .7 + ry, 0);
	glVertex3f(0.2 + tx, .9 + ry, 0);
	glVertex3f(-.2 + tx, .9 + ry, 0);
	glVertex3f(-.2 + tx, .7 + ry, 0);
	// الزيل
	glVertex3f(0.2 + tx, -.2 + ry, 0);
	glVertex3f(0.2 + tx, -.15 + ry, 0);
	glVertex3f(0.6 + tx, -.15 + ry, 0);
	glVertex3f(0.6 + tx, -.2 + ry, 0);

	glVertex3f(0.6 + tx, -.2 + ry, 0);
	glVertex3f(0.64 + tx, -.2 + ry, 0);
	glVertex3f(0.64 + tx, -0.1 + ry, 0);
	glVertex3f(0.6 + tx, -0.01 + ry, 0);


	//mouse
	glColor3f(1.0 , 0.753, 0.796);
	glVertex3f(0.08 + tx, 0.7 + ry, 0);
	glVertex3f(-0.08 + tx, 0.7 + ry, 0);
	glVertex3f(-0.1 + tx, 0.72 + ry, 0);
	glVertex3f(0.1 + tx, 0.72 + ry, 0);

	glEnd();

	glPointSize(5.0);  
	// ears
	glBegin(GL_TRIANGLES);
	glColor3f(0.4, 0.5, 0.6);
	glVertex3f(0.2 + tx, .9 + ry, 0);
	glColor3f(1.0, 0.7, 0.8);
	glVertex3f(0.15 + tx, .9 + ry, 0);
	glVertex3f(0.15 + tx, 1 + ry, 0);

	glColor3f(0.4, 0.5, 0.6);
	glVertex3f(-.2 + tx, .9 + ry, 0);
	glVertex3f(-0.15 + tx, .9 + ry, 0);
	glColor3f(1.0, 0.7, 0.8);
	glVertex3f(-0.15 + tx, 1 + ry, 0);
	glEnd();
	// To draw eyes 
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	float x, y, i, x2, y2, i2;
	float centerX = 0.1; 
	float centerY = 0.8;
	float radius = 0.015;  
	double centerX2 = -0.1; 
	double centerY2 = 0.8;
	double radius2 = 0.015;  
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.9, 0.2);
	for (i2 = 0; i2 <= 2 * 3.14; i2 += 0.01)
	{
		x2 = centerX2 + radius2 * cos(i2); 
		y2 = centerY2 + radius2 * sin(i2);
		glVertex2f(x2 + tx, y2 + ry);

		x = centerX + radius * cos(i2); 
		y = centerY + radius * sin(i2);
		glVertex2f(x + tx, y + ry);
	}
	glEnd();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawBackground();
	drawTom();
	drawJerry();
	glFlush();


}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(500, 200);
	glutCreateWindow("Cat");
	glutDisplayFunc(display);
	glutTimerFunc(0, time, 0);
	glutMainLoop();

	return 0;
}