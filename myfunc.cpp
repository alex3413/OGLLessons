#include"mywindow.h"

float angle=0.0f;
void render(){
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	gluLookAt(0.0f,0.0f,10.0f,
			0.0f,0.0f,0.0f,
			0.0f,1.0f,0.0f);
	
	glRotatef(angle,0.0f,1.0f,0.0f);
	
	glBegin(GL_TRIANGLES);
		glVertex3f(-2.0f,-2.0f,0.0f);
		glVertex3f(0.0f,2.0f,0.0f);
		glVertex3f(2.0f,-2.0f,0.0f);
	
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
