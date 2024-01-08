#include "Bricks.h"
#include "game.h"


////////////////////////////////////////////////////  class brick  ///////////////////////////////////////
brick::brick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}

////////////////////////////////////////////////////  class normalBrick  /////////////////////////////////
normalBrick::normalBrick(point r_uprleft, int r_width, int r_height, game* r_pGame):
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\NormalBrick.jpg";
}

void normalBrick::collisionAction()
{
	//if (collidable::is_collision())
	//{
	//	STR -= 1;
	//}
	//if (STR == 0)
	//{
	//	pGame->getGrid()->deleBrick(uprLft);
	//}
}
//===============================================
hardBrick::hardBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\HardBrick.jpg";
}

void hardBrick::collisionAction()
{
	/*if (collidable::is_collision())
	{
		STR -= 1;
	}
	if (STR == 0)
	{
		pGame->getGrid()->deleBrick(uprLft);
	}*/
}
//=========================================================
rockBrick::rockBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\RockBrick.jpg";
}

void rockBrick::collisionAction()
{
	/*if (collidable::is_collision())
	{
		STR += 1;
	}*/
	//if (STR == 0)
	//{
	//	pGame->getGrid()->deleBrick(uprLft);
	//}*/

}
//================================================
powerBrickup1::powerBrickup1(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\PowerBrickup1.jpg";
}

void powerBrickup1::collisionAction()
{
	/*if (collidable::is_collision())
	{
		STR -= 1;
	}
	if (STR == 0)
	{
	pGame->getGrid()->deleBrick(uprLft);
	}*/
}

powerBrickup2::powerBrickup2(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\PowerBrickup2.jpg";
}

void powerBrickup2::collisionAction()
{
	/*if (collidable::is_collision())
	{
		STR -= 1;
	}
	if (STR == 0)
	{
	pGame->getGrid()->deleBrick(uprLft);
	}*/
}


powerBrickdown1::powerBrickdown1(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\PowerBrickdown1.jpg";
}

void powerBrickdown1::collisionAction()
{
	/*if (collidable::is_collision())
	{
		STR -= 1;
	}
		if (STR == 0)
	{
	pGame->getGrid()->deleBrick(uprLft);
	}*/
}

delBrick::delBrick(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	brick(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\bricks\\delBrick.jpg";
}

void delBrick::collisionAction()
{

}

/////////////////////////////////////////////////////////////////////////////////////
BrickType brick::getType()
{
	return BrickType();
}

