#include"mywindow.h"
#include<math.h>

float alfa=0.0f;
float gamma=0.0f;
float angle=0.0f;
float beta=0.0f;
float red=1.0f,green=1.0f,blue=1.0f;
float lx=0.0f, lz=-1.0f,ly = 0.0f;

float x=0.0f, z=5.0f, y=0.0f;

float deltaAngle = 0.0f;
float deltaBeta = 0.0f; 
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
	gluLookAt(	  x,	y,  z,
				x-lx,	y+ly,  z+lz,
				0.0f,   1.0f,  0.0f	);
	
	glRotatef(alfa,0.0f,1.0f,0.0f);
	glPushMatrix();
	glColor3f(red,green,blue);
	
	glBegin(GL_TRIANGLES);
	glVertex3d(0.0f,0.5f,0.0f);  
	glVertex3d(-0.5f,0.0f,0.0f);
	glVertex3d(0.5,0.0f,0.0f);
	glEnd();
	glPopMatrix();
	
	glRotatef(gamma,0.0f,1.0f,0.0f);
	glPushMatrix();
	glColor3f(0.5f,green,blue);
	glBegin(GL_TRIANGLES);
	glVertex3d(0.0f,0.0f,0.0f);
	glVertex3d(-0.5f,-0.5f,0.0f);
	glVertex3d(0.5,-0.5f,0.0f);
	glEnd();
	glPopMatrix();
/*	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);
	glTranslatef(-1.0f ,0.0f, 0.0f);
//	glPopMatrix();
	
	
	glColor3f(red-0.5,green-0.5,blue-0.5);
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.25f,20,20);
	glTranslatef(-1.0f ,0.0f, 0.0f);
	*/
	
	gamma+=0.1f;
	alfa+=0.1f;
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
			deltaBeta = -1.0f;
			break;
		case GLUT_KEY_RIGHT:
			deltaAngle = 1.0f;
			deltaBeta = 1.0f;
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
			deltaBeta = 0.0f;
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
	if(xOrigin>=0&&yOrigin>=0){
		deltaAngle= (x-xOrigin)*0.001f;
		deltaBeta= (y-yOrigin)*0.001f;
		lx = sin(angle+deltaAngle);
		lz = -cos(angle+deltaAngle);
		ly = cos(angle+deltaAngle)*sin(beta+deltaBeta);
	}
}
void mouseButton(int key,int state,int x,int y){
	if (key == GLUT_LEFT_BUTTON) {
		if(state == GLUT_UP){
			angle+=deltaAngle;
			beta+=deltaBeta;
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
void timefunc(int value) // Timer function
{
  glutPostRedisplay();  // Redraw windows
  glutTimerFunc(40, timefunc, 0); // Setup next timer
}



