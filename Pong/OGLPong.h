#pragma once
#include <GL/glut.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include <cstdlib>
#include <math.h>


void keyboardf(unsigned char, int,int);
void keyboardUpf(unsigned char, int,int);
void draw();
void Timer (int);

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
	
	game();
	void start_settings();
	void win();
	void keyControl();
	void keyReset();
	void drawField();
	void drawScore();
};

class reflection{
	public:
		float x,y;
		float vy;
		float size;
		bool Up,Down,hold;
	reflection();
	void draw();
	void move();
	void care();
};


class Ball{
	public:
		float x;
		float y;
		float vx;
		float vy;
	void move();
	void reflection();
	void draw();
};

extern game settings;
extern reflection leftP;
extern reflection rightP;
extern Ball ball;





