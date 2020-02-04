#include <GL/glut.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

#include <cstdlib>


void render();
void render1();
void changeSize(int,int);
void processNormalCase( unsigned char,int,int);
void processSpecialCase(int,int,int);
void pressKey(int key, int xx, int yy);
void computeDir(float deltaAngle);
void computePos(float deltaMove);
void releaseKey(int key, int x, int y);

