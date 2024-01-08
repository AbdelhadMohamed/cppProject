#pragma once
#include "collidable.h"
#include "game.h"
#include "gameConfig.h"

enum {
	PowerUp_Fireball,

	PowerUp_WindGlide,

	PowerDown_ReverseDirection

};

class power : public collidable
{
public:
	power(point r_uprleft, int r_width, int r_height, game* r_pGame);
	virtual void power_move();
};

class Fireball : public power
{
	Fireball(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	void power_move()override;
};

class WindGlide : public power
{
	WindGlide(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	void power_move()override;
};

class ReverseDirection : public power
{
	ReverseDirection(point r_uprleft, int r_width, int r_height, game* r_pGame);
	void collisionAction();
	void power_move()override;
};

