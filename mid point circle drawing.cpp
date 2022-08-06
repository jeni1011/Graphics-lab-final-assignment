#include<Windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int pntx1, pnty1, r;
void plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + pntx1, y + pnty1);
	glEnd();
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}
void midPointCircleAlgo()
{
	int x = 0, y = r;
	float decision = 1 - r;
	plot(x, y);
	while (y > x)
	{
		if (decision < 0)
		{
			x++;
			decision += 2 * x + 1;
		}
		else {
			y--;
			x++;
			decision += 2 * (x - y) + 1;
		}
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	midPointCircleAlgo();
	glFlush();
}
int main(int argc, char** argv)
{
	
	cout << "X-coordinates:"; cin >> pntx1;
	cout << "\ny_coordinates:"; cin >> pnty1;
	cout << "\nEnter radius:"; cin >> r;
	glutInit(&argc, argv);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Mid Point Circle drawing algorithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;

		
}