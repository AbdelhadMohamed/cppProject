#include "paddle.h"
#include "game.h"
#include "gameConfig.h"
#include "CMUgraphicsLib/auxil.h"


paddle::paddle(point r_uprleft, int paddleWidth, int paddleHight, game* r_pGame) :
	collidable(r_uprleft, paddleWidth, paddleHight, r_pGame)
{
}

void paddle::draw()
{
	window* pWind = pGame->getWind();
	pWind->SetBrush(LIGHTGREEN);
	pWind->SetPen(config.paddleColor);
	//pWind->DrawRectangle(500,530,(500+config.paddleWidth),(530+config.paddleHight));
	pWind->DrawRectangle(uprLft.x, uprLft.y-40, (uprLft.x + width), (uprLft.y + height-40), FILLED);
}
void paddle::collisionAction()
{
	//if (collidable::is_collision(game::playerPaddle,game::gameBall))
}

void paddle::paddleMove()
{
	window* pWind = pGame->getWind();
	//paddle::draw();
	char Key;
	keytype kType;
	int speed = 10;
	kType = pWind->WaitKeyPress(Key);
	color c = BLUE;
	color bg = LAVENDER; 
	if (Key == 4 && uprLft.x != 0)
		{
			uprLft.x -= speed;
		}
	if (Key == 6 && uprLft.x < 1200 - width)
		{
			uprLft.x += speed;
		}
		pWind->SetBrush(bg);
		pWind->SetPen(bg);
		pWind->DrawRectangle(0, uprLft.y-40, (1200), (uprLft.y + height-40), FILLED);
		paddle::draw();
		pWind->UpdateBuffer();
}
//===============================================================================================
