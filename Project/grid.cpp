#include "grid.h"
#include "game.h"
#include "gameConfig.h"
#include <random>

grid::grid(point r_uprleft, int wdth, int hght, game* pG) :
	drawable(r_uprleft, wdth, hght, pG)
{
	random_device rd;  // Obtain a random number from hardware
	mt19937 gen(rd()); // Seed the generator
	uniform_int_distribution<> distr(0, 3); // Define the range

	rows = hght / config.brickHeight;
	cols = wdth / config.brickWidth;

	brickMatrix = new brick * *[rows];
	for (int i = 0; i < rows; ++i) {
		brickMatrix[i] = new brick * [cols];

		for (int j = 0; j < cols; ++j) {
			point brickTopLeft = { r_uprleft.x + j * config.brickWidth, r_uprleft.y + i * config.brickHeight };
			int brickType = distr(gen); // Generate a random number between 0 and 3

			// Use the random number to determine the brick type
			switch (brickType) {
			case 0:
				brickMatrix[i][j] = new normalBrick(brickTopLeft, config.brickWidth, config.brickHeight, pG);
				break;
			case 1:
				brickMatrix[i][j] = new hardBrick(brickTopLeft, config.brickWidth, config.brickHeight, pG);
				break;
			case 2:
				brickMatrix[i][j] = new rockBrick(brickTopLeft, config.brickWidth, config.brickHeight, pG);
				break;
			case 3:
				brickMatrix[i][j] = new powerBrickup1(brickTopLeft, config.brickWidth, config.brickHeight, pG);
				break;
			case 4:
				brickMatrix[i][j] = new powerBrickup2(brickTopLeft, config.brickWidth, config.brickHeight, pG);
				break;
			case 5:
				brickMatrix[i][j] = new powerBrickdown1(brickTopLeft, config.brickWidth, config.brickHeight, pG);
				break;
			case 6:
				brickMatrix[i][j] = new delBrick(brickTopLeft, config.brickWidth, config.brickHeight, pG);
				break;
			}
		}
	}
}

grid::~grid() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			delete brickMatrix[i][j]; // Delete each allocated brick
			brickMatrix[i][j] = nullptr; // Set the pointer to nullptr after deletion
		}
		delete[] brickMatrix[i]; // Delete the brick array for the row
	}
	delete[] brickMatrix; // Delete the array of pointers
	brickMatrix = nullptr; // Set the pointer to nullptr after deletion
}

void grid::draw() const
{
	window* pWind = pGame->getWind();
	//draw lines showing the grid
	pWind->SetPen(config.gridLinesColor,1);

	//draw horizontal lines
	for (int i = 0; i < rows; i++) {
		int y = uprLft.y + (i + 1) * config.brickHeight;
		pWind->DrawLine(2, y, width, y);
	}
	//draw vertical lines
	for (int i = 0; i < cols; i++) {
		int x = (i + 1) * config.brickWidth;
		pWind->DrawLine(x, uprLft.y, x, uprLft.y+ rows* config.brickHeight);
	}

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (brickMatrix[i][j])
				brickMatrix[i][j]->draw();	//draw exisiting bricks


}
brick* grid::getBrick(int i, int j)
{
	return brickMatrix[i][j];
}

void grid::setBrick(int i, int j, brick* b)
{
	brickMatrix[i][j] = b;

}

int grid::getHeight()
{
	return rows;
}

int grid::getWidth()
{
	return cols;
}
point grid::getPoint(int j, int i)
{
	point p;
	p.x = uprLft.x + j * config.brickWidth;
	p.y = uprLft.y + i * config.brickHeight;
	return p;
}


int grid::addBrick(BrickType brkType, point clickedPoint)
{
	//TODO:
	// 1- Check that the clickedPoint is within grid range (and return -1)
	// 2- Check that the clickedPoint doesnot overlap with an exisiting brick (return 0)

	//Here we assume that the above checks are passed
	
	//From the clicked point, find out the index (row,col) of the corrsponding cell in the grid
	int gridCellRowIndex = (clickedPoint.y-uprLft.y) / config.brickHeight;
	int gridCellColIndex = clickedPoint.x / config.brickWidth;

	//Now, align the upper left corner of the new brick with the corner of the clicked grid cell
	point newBrickUpleft;
	newBrickUpleft.x = uprLft.x + gridCellColIndex * config.brickWidth;
	newBrickUpleft.y = uprLft.y+ gridCellRowIndex * config.brickHeight;

	switch (brkType)
	{
	case BRK_NRM:	//The new brick to add is Normal Brick
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new normalBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_HRD:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new hardBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_ROCK:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new rockBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_POWERup1:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new powerBrickup1(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_POWERup2:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new powerBrickup2(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_POWERdown1:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new powerBrickdown1(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;
	case BRK_DEL:
		brickMatrix[gridCellRowIndex][gridCellColIndex] = new delBrick(newBrickUpleft, config.brickWidth, config.brickHeight, pGame);
		break;


	}
	return 1;
}

int grid::getRows() const {
	return rows;
}
int grid::getCols() const {
	return cols;
}
brick* grid::getBrickAt(int row, int col) const {
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		return brickMatrix[row][col];
	}
	return nullptr;
}
void grid::deleBrick(point p)
{
	int row = (p.y - uprLft.y) / config.brickHeight;
	int column = p.x / config.brickWidth;

	delete brickMatrix[row][column];
	brickMatrix = nullptr;
}
void grid::removeBrickAt(int row, int col) {
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		delete brickMatrix[row][col];
		brickMatrix[row][col] = nullptr;
	}
}