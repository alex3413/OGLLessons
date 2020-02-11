#include"mywindow.h"
#include<math.h>


float angle=0.0f;
float red=1.0f,green=1.0f,blue=1.0f;
float lx=0.0f, lz=-1.0f,ly = 0.0f;

float x=0.0f, z=5.0f, y=1.0f;

float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin=-1;
int yOrigin=-1;
void render(){
	if (deltaMove)
		computePos(deltaMove);
//	if (deltaAngle)
//		computeDir(deltaAngle);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	gluLookAt(	  x,	1.0f,  z,
				x+lx,	1.0f,  z+lz,
				0.0f,   1.0f,  0.0f	);
	
//	glRotatef(angle,0.0f,1.0f,0.0f);
	glColor3f(red,green,blue);
/*glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);;
	
	glEnd();*/
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);
	glPushMatrix();
/*	glColor3f(red-0.5f,green-0.5f,blue-0.5f);
	glTranslatef(0.0f ,0.5f, 0.0f);
	glutSolidSphere(0.5f,20,20);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);   */
//	angle+=0.1f;
	glutSwapBuffers();
	
}
void changeSize(int w,int h){
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	
	glMatrixMode(GL_MODELVIEW);
	
	
}
void processNormalCase(unsigned char key,int x,int y){
	if(key==27)
		exit(0);
	
}
void processSpecialCase(int key,int x,int y){
	switch (key){
		case GLUT_KEY_F1:{
			red=1.0f;
			green=0.0f;
			blue=0.0f;
			break;
		}
		case GLUT_KEY_F2:{
			red=0.0f;
			green=0.0f;
			blue=1.0f;
			break;
		}
		case GLUT_KEY_F3:{
			red=0.0f;
			green=1.0f;
			blue=0.0f;
			break;
		}
		case GLUT_KEY_UP:{
			red=0.5f;
			green=0.5f;
			blue=0.5f;
			break;
		}
	}
	
}
void computePos(float deltaMove) {
 
	x += deltaMove * lx * 0.01f;
	z += deltaMove * lz * 0.01f;
	y += deltaMove * ly * 0.01f;
}
 
void computeDir(float deltaAngle) {
 
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
	ly = sin(angle);
}
void pressKey(int key, int xx, int yy) {
 
	switch (key) {
		case GLUT_KEY_LEFT:
			deltaAngle = -1.0f;
			break;
		case GLUT_KEY_RIGHT:
			deltaAngle = 1.0f;
			break;
		case GLUT_KEY_UP:
			deltaMove = 0.5f;
			red=1.0f;
			green=0.0f;
			blue=0.0f;
			break;
		case GLUT_KEY_DOWN:
			deltaMove = -0.5f;
			red=0.0f;
			green=1.0f;
			blue=0.0f;
			break;
	}
}
 
void releaseKey(int key, int x, int y) {
 
	switch (key) {
		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT: 
			deltaAngle = 0.0f;
			break;
		case GLUT_KEY_UP:
			deltaMove = 0;
			red=1.0f;
			green=1.0f;
			blue=1.0f;
			break;
		case GLUT_KEY_DOWN: 
			deltaMove = 0;
			red=1.0f;
			green=1.0f;
			blue=1.0f;
			break;
	}
}
void mouseMove(int x,int y){
	if(xOrigin>=0){
		deltaAngle= (x-xOrigin)*0.001f;
		lx = sin(angle+deltaAngle);
		lz = -cos(angle+deltaAngle);
		ly = yOrigin;
	}
}
void mouseButton(int key,int state,int x,int y){
	if (key == GLUT_LEFT_BUTTON) {
		if(state == GLUT_UP){
			angle+=deltaAngle;
			xOrigin=-1;
			yOrigin=-1;
			red=1.0f;
			green=1.0f;
			blue=1.0f;
		}
		else{
		 //state=GLUT_DOWN;
			 xOrigin=x;
			 yOrigin=y;
			red=0.0f;
			green=1.0f;
			blue=0.0f;
		 
		}
	}
}



