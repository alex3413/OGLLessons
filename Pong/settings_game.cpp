
#include "OGLPong.h"

game::game(){
	orthoWid = 700; // ������� ������������ �����
	orthoHeid = 700;
	
	winWid = 700; // ������ ����
	winHeid = 700;
	
	winXPos = 100; // ������� ����
	winYPos = 100;
	
	fieldSizeX = 600; // ������� �������� ����
	fieldSizeY = 400;
	
	delay = 1; //��������� ��� ������
	
	pThickness = 10;// ������� ���������
	ballSize = 5; // ������ ������
	borderT = 10; // ������� ����� ����
	mLineT = 5; // ������� ����� ����������
	scoreL = 0; // ���������� ����� �������
	scoreR = 0;
	textPosX = 0; 
	textPosY = fieldSizeY+10;
	ballSpeedX = 0.5; // �������� ������ �� �
	pSpeedY = 1; // �������� ��������
	}

void game::drawField(){
	glColor3f(1,1,1);
	
	glVertex2f(-fieldSizeX-borderT, -fieldSizeY-borderT);
	glVertex2f(fieldSizeX+borderT, -fieldSizeY-borderT);
	glVertex2f(fieldSizeX+borderT, -fieldSizeY);
	glVertex2f(-fieldSizeX-borderT, -fieldSizeY);
	
	glVertex2f(-fieldSizeX-borderT, fieldSizeY+ borderT);
	glVertex2f(fieldSizeX+borderT, fieldSizeY+borderT);
	glVertex2f(fieldSizeX+borderT, fieldSizeY);
	glVertex2f(-fieldSizeX-borderT, fieldSizeY);
	
	glVertex2f(-fieldSizeX-borderT, -fieldSizeY- borderT);
	glVertex2f(-fieldSizeX, -fieldSizeY - borderT);
	glVertex2f(-fieldSizeX, fieldSizeY+ borderT);
	glVertex2f(-fieldSizeX-borderT, fieldSizeY+ borderT);
	
	glVertex2f(fieldSizeX, -fieldSizeY - borderT);
	glVertex2f(fieldSizeX+borderT, -fieldSizeY- borderT);
	glVertex2f(fieldSizeX+borderT, fieldSizeY+ borderT);
	glVertex2f(fieldSizeX, fieldSizeY+ borderT);
	
	for(float i = fieldSizeY; i<=fieldSizeY; i+=4*mLineT){
		glVertex2f(-mLineT, i+mLineT);
		glVertex2f(mLineT, i+mLineT);
		glVertex2f(mLineT, i-mLineT);
		glVertex2f(-mLineT, i-mLineT);
		
	}
}
void game::drawScore(){
	glRasterPos2f(textPosX - 50, textPosY + 20);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0'+ scoreL);
	
	glRasterPos2f(textPosX + 30, textPosY + 20);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0'+ scoreR);
	
	if(scoreL == 8){
		glRasterPos2f(textPosX - 200, textPosY + 40);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');	
	}
	
	if(scoreR == 8){
		glRasterPos2f(textPosX + 150, textPosY + 40);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'W');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'E');
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'R');	
		
	}
}
void game::start_settings(){
	leftP.size = 200;
	rightP.size = 200;
	leftP.x = -510;
	rightP.x = 510;
while(ball.vx == 0){
	ball.vx = (rand()%3 - 1)*ballSpeedX;
}
ball.x=0;
ball.y=0;
ball.vy=0;
}
void game::win(){
	if((scoreL == 8 )|| (scoreR == 8)){
	
		glutTimerFunc(2000,exit,0);
		settings.delay = 10000;
	}
	if(ball.x < leftP.x + pThickness - ballSpeedX){
		rightP.hold = true;
		scoreR++;
	}
	if(ball.x > rightP.x - pThickness + ballSpeedX){
		leftP.hold = true;
		scoreL++;
	}
	
}

