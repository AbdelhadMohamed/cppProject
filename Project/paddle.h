#pragma once
#include "collidable.h"
class paddle : public collidable 
{
public:
	paddle(point r_uprleft, int paddleWidth, int paddleHight, game* r_pGame);
	void draw();
	void collisionAction();
	void paddleMove();

};

