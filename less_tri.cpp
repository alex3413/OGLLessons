#include <iostream>
#include "mywindow.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void Hide()
{
  HWND Hide;
  AllocConsole(); 
  Hide = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Hide,0);
}

int main(int argc, char** argv) {
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition (250,250);
	glutInitWindowSize(500,500);
	glutCreateWindow("MyWindow");
	
	glutDisplayFunc(render);
	glutReshapeFunc(changeSize);
	glutIdleFunc(render);
	glutKeyboardFunc(processNormalCase);
	glutSpecialFunc(processSpecialCase);
	
	Hide();
	
	glutMainLoop();
	
	return 0;
}
