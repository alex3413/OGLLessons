#include <iostream>
#include "OGLPong.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void Hide(){
  HWND Hide;
  AllocConsole(); 
  Hide = FindWindowA("ConsoleWindowClass", NULL);
  ShowWindow(Hide,0);
}
int main(int argc, char** argv) {
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition (settings.winXPos,settings.winYPos);
	glutInitWindowSize(settings.winWid, settings.winHeid);
	glutCreateWindow("Ping_POng");
	glutDisplayFunc(draw);
	glutKeyboardFunc(keyboardf);
	glutKeyboardUpFunc(keyboardUpf);
	glClearColor(0,0,0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIentity();
	gluOrtho2D(-settings.orthoWid, settings.orthoWid, -settings.othoHeid, settings.orthoHeid);
	Hide();
	glutMainLoop();
	
	return 0;
}
