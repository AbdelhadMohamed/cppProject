#include "wall.h"
#include "game.h"
#include "gameConfig.h"

wall::wall(point r_uprleft, int wallWidth, int wallHight, game* r_pGame) :
	collidable(r_uprleft, wallWidth, wallHight, r_pGame) {}

void wall::draw() const
{
	window* pWind = pGame->getWind();
	pWind->SetPen(config.wallCollor, 5);
	pWind->DrawRectangle(0, 0, (config.wallWidth), (config.windHeight));
	pWind->DrawRectangle((config.windWidth-5), 0,( config.windWidth), (config.windHeight));
}
void wall::collisionAction()
{

}