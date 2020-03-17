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
