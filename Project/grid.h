#pragma once

#include "drawable.h"
#include "Bricks.h"


class game;

class grid:public drawable
{
	
	brick*** brickMatrix;		//2D array of brick pointers

	int rows, cols;
public:
	grid(point r_uprleft, int r_width, int r_height, game* r_pGame);
	~grid();
	void draw() const;
	int addBrick(BrickType brkType, point clickedPoint);
	void deleBrick(point p);
	brick* getBrick(int i, int j);
	void setBrick(int i, int j, brick* b);
	int getHeight();
	int getWidth();
	point getPoint(int j, int i);
	BrickType getType();
	int getRows() const;
	int getCols() const;
	brick* getBrickAt(int row, int col) const;
	void removeBrickAt(int row, int col);
};

