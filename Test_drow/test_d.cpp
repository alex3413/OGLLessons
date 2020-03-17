#include <iostream>
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <GL/freeglut.h>

using namespace std;
void Hide(){
  HWND Hide;
  AllocConsole(); 
  Hide = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Hide,0);
}

void render();
void timer(int i=0){
	render();
	glutTimerFunc(10,timer,0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH| GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(250,250);
	glutInitWindowSize(500,500);
	glutCreateWindow("Clock");
	glClearColor(0.0,0.0,0.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-400.0,400.0,-400.0,400.0,-400.0,400.0);
	glutDisplayFunc(render);
	timer();
	Hide();
	glutMainLoop();
	return 0;
}

void render(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	
	glColor3f(0.123,1.750,0.300);
	for(int i=0;i<60;i++){
		float x = sin(2*M_PI/60*i);
		float y = cos(2*M_PI/60*i);
		glVertex2f(350*x,350*y);
		glVertex2f(340*x,340*y);
	}
	
	glColor3f(1.200,0.100,0.150);
	for(int i=0; i<12;i++){
		float x = sin(2*M_PI/12*i);
		float y = cos(2*M_PI/12*i);
		glVertex2f(365*x,365*y);
		glVertex2f(340*x,340*y);
	}
	
	time_t t= time(0);
	tm *lt = localtime(&t);
	int h = lt->tm_hour;
	int m = lt->tm_min;
	int s = lt->tm_sec;
	
	glColor3f(1.0,1.0,1.0);
	float x = sin(2*M_PI*(h*60+m) /12 /60);
	float y = cos(2*M_PI*(h*60+m) /12 /60);
	glVertex2f(0,0);
	glVertex2f(200*x,200*y);
	
	glColor3f(1.0,1.0,1.0);
	 x = sin(2*M_PI*(m*60+s) /60 /60);
	 y = cos(2*M_PI*(m*60+s) /60 /60);
	glVertex2f(0,0);
	glVertex2f(340*x,340*y);
	
	glColor3f(1.0,1.0,1.0);
	x = sin(2*M_PI*s/60);
	y = cos(2*M_PI*s/60);
	glVertex2f(0,0);
	glVertex2f(365*x,365*y);
	
	glEnd();
	
	glutSwapBuffers();
	glFlush();
}
