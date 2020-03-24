
#include "OGLPong.h"


reflection::reflection(){
		vy=0;
		y = 0;
		Up = false;
		Down = false;
		hold = false;
	}

void reflection::draw(){
	glColor3f(1,1,1);
	glVertex2f(x+settings.pThickness,y+size/2);
	glVertex2f(x+settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y-size/2);
	glVertex2f(x-settings.pThickness,y+size/2);
	
}
void reflection::move(){
	y+=vy;
	if(y < -settings.fieldSizeY + size/2){
		y = -settings.fieldSizeY +size/2;
		vy = 0;
	}
	if(y > settings.fieldSizeY - size/2){
		y = settings.fieldSizeY -size/2;
		vy = 0;
	}
}
