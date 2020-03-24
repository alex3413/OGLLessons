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
	int orthoWid; // ������� ������������ �����
	int orthoHeid;
	
	int winWid; // ������ ����
	int winHeid;
	
	int winXPos; // ������� ����
	int winYPos;
	
	float fieldSizeX; // ������� �������� ����
	float fieldSizeY;
	
	int delay; //��������� ��� ������
	
	float pThickness;// ������� ���������
	float ballSize; // ������ ������
	float borderT; // ������� ����� ����
	float mLineT; // ������� ����� ����������
	int scoreL; // ���������� ����� �������
	int scoreR;
	float textPosX; 
	float textPosY;
	float ballSpeedX; // �������� ������ �� �
	float pSpeedY; // �������� ��������
	
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





