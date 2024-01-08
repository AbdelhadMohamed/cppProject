#pragma once

//This file contains all classes bricks classes 
#include "collidable.h"

enum BrickType	//add more brick types
{
	BRK_NRM,	//Normal Brick
	BRK_ROCK,
	BRK_POWERup1,
	BRK_POWERup2,
	BRK_POWERdown1,
	BRK_DEL,
	BRK_HRD		//Hard Brick

	//TODO: Add more types
};

////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
//Base class for all bricks
class brick :public collidable
{
public:
	brick(point r_uprleft, int r_width, int r_height, game* r_pGame);

	BrickType getType();
	//virtual void setSTR(int S) = 0;
	//virtual int getSTR() = 0;
};


////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
class normalBrick :public brick
{
protected:
	int STR = 1;
public:
	normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	/*void setSTR(int S) override;
	int getSTR() override;*/
};
//===========================================
class hardBrick :public brick
{
protected:
	int STR = 3;
public:
	hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	/*void setSTR(int S) override;
	int getSTR() override;*/
};
//=======================================================
class rockBrick :public brick
{
protected:
	int STR = 1;
public:
	rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	//void setSTR(int S) override;
	//int getSTR() override;
};
//=====================================================
class powerBrickup1 :public brick
{
protected:
	int STR = 1;
public:
	powerBrickup1(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	/*void setSTR(int S) override;
	int getSTR() override*/;
};

class powerBrickup2 :public brick
{
protected:
	int STR = 1;
public:
	powerBrickup2(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	/*void setSTR(int S) override;
	int getSTR() override;*/
};

class powerBrickdown1 :public brick
{
protected:
	int STR = 1;
public:
	powerBrickdown1(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	/*void setSTR(int S) override;
	int getSTR() override;*/
};

class delBrick :public brick
{
public:
	delBrick(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
};
