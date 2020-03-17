//#pragma once
//#include "OGLPong.h"
#include "settings_game.cpp"
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
