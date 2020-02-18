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
	glutInitWindowPosition (100,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("MyWindow");
	
	glutDisplayFunc(render);
	glutTimerFunc(40, timefunc, 0);
	glutReshapeFunc(changeSize);
	glutIdleFunc(render);
	glutKeyboardFunc(processNormalCase);
	glutSpecialFunc(processSpecialCase);
	glutSpecialFunc(pressKey);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
 	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);
	
	Hide();
	glutMainLoop();
	
	return 0;
}
