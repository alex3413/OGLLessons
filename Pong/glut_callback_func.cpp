
#include "OGLPong.h"

void keyboardf(unsigned char key, int x,int y){
	switch(key){
		case 'q':
			leftP.Up = true;
			break;
		case 'a':
			leftP.Down = true;
		case 'z':
			if(leftP.hold){
				leftP.hold=false;
				ball.vx = settings.ballSpeedX;
			}
			break;
			
		case 'p':
			rightP.Up = true;
			break;
		case 'l':
			rightP.Down = true;
		case 'm':
			if(rightP.hold){
				rightP.hold=false;
				ball.vx = -settings.ballSpeedX;
			}
			break;
	}
}
void keyboardUpf(unsigned char key, int x,int y){
	switch (key){
		case 'q':
			leftP.Up = false;
			break;
		case 'a':
			leftP.Down = false;
			break;
			
			
		case 'p':
			rightP.Up = false;
			break;
		case 'l':
			rightP.Down = false;
			break;
	}
	
}
void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	rightP.draw();
	leftP.draw();
	ball.draw();
	settings.drawField();
	glEnd();
	settings.drawScore();
	glutSwapBuffers();
	
}
void Timer (int value){
	settings.win();
	//settings.keyControl();
	leftP.move();
	rightP.move();
	ball.move();
	ball.reflection();
	//leftP.care();
	//rightP.care();
	//settings.keyReset();
	glutPostRedisplay();
	glutTimerFunc(settings.delay, Timer, 0);
}




