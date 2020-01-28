#include"mywindow.h"

float angle=0.0f;
float red=1.0f,green=1.0f,blue=1.0f;
void render(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	gluLookAt(5.0f,0.0f,10.0f,
			0.0f,0.0f,0.0f,
			0.0f,1.0f,0.0f);
	
	glRotatef(angle,0.0f,1.0f,0.0f);
	glColor3f(red,green,blue);
	glBegin(GL_QUADS);
		glVertex3f(-2.0f,-2.0f,0.0f);
		glVertex3f(2.0f,2.0f,0.0f);
		glVertex3f(-2.0f,2.0f,0.0f);
		glVertex3f(2.0f,0.0f,0.0f);
	
	glEnd();
	
	angle+=0.1f;
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




