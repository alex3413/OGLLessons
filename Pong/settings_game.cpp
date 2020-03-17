class game{
	int othoWid; // размеры координатной сетки
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
	glColor(1,1,1);
	
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
		glVertex2F(mLineT, i+mlineT);
		glVertex2F(mLineT, i-mlineT);
		glVertex2F(-mLineT, i-mlineT);
		
	}
}
void game::drawScore(){
	glRasterPos2f(textPosX - 50, textPosY + 20);
	glutBitmapCharacter(Glut_BitMap_9_BY_15, '0'+ scoreL);
	
	glRasterPos2f(textPosX + 30, textPosY + 20);
	glutBitmapCharacter(Glut_BitMap_9_BY_15, '0'+ scoreR);
	
	if(scoreL == 8){
		glRasterPos2f(textPosX - 200, textPosY + 40);
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'W');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'I');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'N');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'N');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'E');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'R');	
	}
	
	if(scoreR == 8){
		glRasterPos2f(textPosX + 150, textPosY + 40);
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'W');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'I');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'N');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'N');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'E');
		glutBitmapCharacter(Glut_BitMap_9_BY_15, 'R');	
		
	}
}


