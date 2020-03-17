#include <GL/glut.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include <cstdlib>
//#include "ball.cpp"
//#include "reflection.cpp"
//#include "settings_game.cpp"

//void keyboardf(unsigned char, int,int);
//void keyboardUpf(unsigned char, int,int);
//void draw();

class game{
	public:
	int orthoWid; // размеры координатной сетки
	int orthoHeid;
	
	int winWid; // размер окна
	int winHeid;
	
	int winXPos; // позиция окна
	int winYPos;
	
	float fieldSizeX; // размеры игрового поля
	float fieldSizeY;
	
	int delay; //временной тик шарика
	
	float pThickness;// толщина платформы
	float ballSize; // размер шарика
	float borderT; // толщина рамки поля
	float mLineT; // толщина линии посередине
	int scoreL; // количество очков игроков
	int scoreR;
	float textPosX; 
	float textPosY;
	float ballSpeedX; // скорость шарика по х
	float pSpeedY; // скорость платформ
	
	game(){
	orthoWid = 700; // размеры координатной сетки
	orthoHeid = 700;
	
	winWid = 700; // размер окна
	winHeid = 700;
	
	winXPos = 100; // позиция окна
	winYPos = 100;
	
	fieldSizeX = 600; // размеры игрового поля
	fieldSizeY = 400;
	
	delay = 1; //временной тик шарика
	
	pThickness = 10;// толщина платформы
	ballSize = 5; // размер шарика
	borderT = 10; // толщина рамки поля
	mLineT = 5; // толщина линии посередине
	scoreL = 0; // количество очков игроков
	scoreR = 0;
	textPosX = 0; 
	textPosY = fieldSizeY+10;
	ballSpeedX = 0.5; // скорость шарика по х
	pSpeedY = 1; // скорость платформ
	}
	void start_settings();
	void win();
	void keyControl();
	void keyReset();
	void drawField();
	void drawScore();
}settings;

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

class reflection{
	public:
		float x,y;
		float vy;
		float size;
		bool Up,Down,hold;
	reflection(){
		vy=0;
		y = 0;
		Up = false;
		Down = false;
		hold = false;
	}
	void draw();
	void move();
	void care();
}leftP, rightP;

void reflection::draw(){
	glColor3f(1,1,1);
	glVertex2f(x+settings.pThickness,y+size/2);
	glVertex2f(x+settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y+size/2);
	
}
class ball{
	public:
		float x;
		float y;
		float vx;
		float vy;
	void move();
	void reflection();
	void draw();
}ball;

void ball::draw(){
	glVertex2f(x+settings.ballSize, y+settings.ballSize);
	glVertex2f(x+settings.ballSize, y-settings.ballSize);
	glVertex2f(x-settings.ballSize, y-settings.ballSize);
	glVertex2f(x-settings.ballSize, y+settings.ballSize);
}

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
	settings.drawField();
	glEnd();
	settings.drawScore();
	glutSwapBuffers();
	
}



