class game{
	int othoWid; // ������� ������������ �����
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
	
	game(){
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


