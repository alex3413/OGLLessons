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
