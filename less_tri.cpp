#include <iostream>
#include "mywindow.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition (250,250);
	glutInitWindowSize(300,300);
	glutCreateWindow("MyWindow");
	
	glutDisplayFunc(render);
	glutReshapeFunc(changeSize);
	glutIdleFunc(render);
	
	glutMainLoop();
	
	return 0;
}
