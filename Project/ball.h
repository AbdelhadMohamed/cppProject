#pragma once
#include "collidable.h"
class ball : collidable
{
protected:
	int x;
	int y;
	int newx;
	int newy;
	int intx = 600;
	int inty = 520;
	int rad = 10;
public:
	ball(point r_uprleft, int ballWidth, int ballHight, game* r_pGame);
	void draw()const;
	void collisionAction();
	void ballmove();
	int getYPosition();
	int getXPosition();
	int getresetposition();
	int getraduis();

};

//class ball : collidable
//{
//protected:
//	int x;
//	int y;
//	int newx;
//	int newy;
//public:
//	ball(point r_uprleft, int ballWidth, int ballHight, game* r_pGame);
//	void draw()const;
//	void collisionAction();
//
//
//
//	void sety(int y);
//	void setx(int x);
//	void setnewx(int newx1);
//	void setnewy(int newy1);
//
//
//
//	int getYPosition();
//	int getPositionx();
//
//	int getnewx();
//
//	int getnewy();
//
//	void ballmove();
//
//};