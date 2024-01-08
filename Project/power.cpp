#include "power.h"

power::power(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	collidable(r_uprleft, r_width, r_height, r_pGame)
{
}
void power::power_move()
{
}
///////////////////////////////////////////////////////////////////////////////////////////
Fireball::Fireball(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	power(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\power\\fireBall.jpg";
}

void Fireball::collisionAction()
{

}
void Fireball::power_move()
{

}
///////////////////////////////////////////////////////////////////////////////////////////
WindGlide::WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	power(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\power\\WindGlide.jpg";
}

void WindGlide::collisionAction()
{

}
void WindGlide::power_move()
{

}
///////////////////////////////////////////////////////////////////////////////////////////
ReverseDirection::ReverseDirection(point r_uprleft, int r_width, int r_height, game* r_pGame) :
	power(r_uprleft, r_width, r_height, r_pGame)
{
	imageName = "images\\power\\ReverseDirection.jpg";
}

void ReverseDirection::collisionAction()
{

}
void ReverseDirection::power_move()
{

}
///////////////////////////////////////////////////////////////////////////////////////////

