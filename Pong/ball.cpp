#include "OGLPong.h"


void Ball::draw(){
	glVertex2f(x+settings.ballSize, y+settings.ballSize);
	glVertex2f(x+settings.ballSize, y-settings.ballSize);
	glVertex2f(x-settings.ballSize, y-settings.ballSize);
	glVertex2f(x-settings.ballSize, y+settings.ballSize);
}
void Ball::move(){
	x+=vx;
	y+=vy;
}
void Ball::reflection(){
	if ((y <= -settings.fieldSizeY)||(y>= settings.fieldSizeY))
		vy=-vy;
	if((x <= leftP.x + settings.pThickness)&&(fabs(double(y - leftP.y)) <= leftP.size/2 + fabs(vy))){
		vx = -vx;
		vy += leftP.vy*settings.ballSpeedX/2;
	}
	if((x >= rightP.x - settings.pThickness)&&(fabs(double(y - rightP.y)) <= rightP.size/2 + fabs(vy))){
		vx = -vx;
		vy += rightP.vy*settings.ballSpeedX/2;
	}
	
}
