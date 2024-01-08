#include "game.h"
#include "gameConfig.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "gameConfig.h"
#include"collidable.h"

void game::displayTime() const {
	using namespace std::chrono;

	auto now = steady_clock::now();
	auto elapsed = duration_cast<seconds>(now - startTime);
	int hours = elapsed.count() / 3600;
	int minutes = (elapsed.count() % 3600) / 60;
	int seconds = elapsed.count() % 60;

	std::ostringstream timeStream;
	timeStream << std::setfill('0') << std::setw(2) << hours << ":"
		<< std::setfill('0') << std::setw(2) << minutes << ":"
		<< std::setfill('0') << std::setw(2) << seconds;
	std::string timeString = timeStream.str();

	// Set the drawing color to something that contrasts with the background
	pWind->SetPen(BLUE, 1); // Example: White text

	// Ensure the font is appropriate for the status bar
	pWind->SetFont(14, BOLD, BY_NAME, "Arial"); // Example: Smaller font size

	// Determine the correct position for the timer based on the status bar's location
	int timerX = config.windWidth - 100; // Example: Right-aligned position
	int timerY = 0; // Vertically centered in status bar

	pWind->DrawRectangle(timerX, timerY, config.windWidth, config.toolBarHeight);

	// Draw the formatted time string in the designated position
	pWind->DrawString(timerX, timerY, "TIMER");
}

game::game()
{
	//Initialize playgrond parameters
	gameMode = MODE_DSIGN;


	//1 - Create the main window
	pWind = CreateWind(config.windWidth, config.windHeight, config.wx, config.wy);

	//2 - create and draw the toolbar
	point toolbarUpperleft;
	toolbarUpperleft.x = 0;
	toolbarUpperleft.y = 0;

	gameToolbar = new toolbar(toolbarUpperleft,0,config.toolBarHeight, this);
	gameToolbar->draw();

	//3 - create and draw the grid
	point gridUpperleft;
	gridUpperleft.x = 0;
	gridUpperleft.y = config.toolBarHeight;
	bricksGrid = new grid(gridUpperleft, config.windWidth, config.gridHeight, this);
	bricksGrid->draw();
	
	//4- Create the Paddle
	//TODO: Add code to create and draw the paddle

	point paddleupperlift;
	paddleupperlift.x = 500;
	paddleupperlift.y = 570;
	playerPaddle = new paddle(paddleupperlift, config.paddleWidth, config.paddleHight, this);
	playerPaddle->draw();


	//5- Create the ball
	//TODO: Add code to create and draw the ball
	point ballCentre;
	ballCentre.x = 600;
	ballCentre.y = 563;
	gameBall = new ball(ballCentre, config.ballHight, config.ballWidth, this);
	gameBall->draw();

	//wall
	point wall_L;
	point wall_R;
	wall_L.x = 0;
	wall_L.y = 0;
	wall_R.x = config.windWidth;
	wall_R.y = 0;
	gamewall_L = new wall(wall_L, config.wallHight, config.wallWidth, this);
	gamewall_R = new wall(wall_R, config.wallHight, config.wallWidth, this);
	startTime = std::chrono::steady_clock::now();
	lives = 3;
	
	//6- Create and clear the status bar
	clearStatusBar();
}

game::~game()
{
	delete pWind;
	delete gameToolbar;
	delete bricksGrid;
}


clicktype game::getMouseClick(int& x, int& y) const
{
	return pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
//////////////////////////////////////////////////////////////////////////////////////////
window* game::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(config.bkGrndColor);
	pW->SetPen(config.bkGrndColor, 1);
	pW->DrawRectangle(0, 0, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void game::clearStatusBar() const
{
	//Clear Status bar by drawing a filled rectangle
	pWind->SetPen(config.statusBarColor, 1);
	pWind->SetBrush(config.statusBarColor);
	pWind->DrawRectangle(0, config.windHeight - config.statusBarHeight, config.windWidth, config.windHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////

void game::printMessage(string msg) const	//Prints a message on status bar
{
	clearStatusBar();	//First clear the status bar

	pWind->SetPen(config.penColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, config.windHeight - (int)(0.85 * config.statusBarHeight), msg);
}



window* game::getWind() const		//returns a pointer to the graphics window
{
	return pWind;
}



void game::saveBricksLocation(grid* bricksGrid, const string& file1)
{
	ofstream file("file.txt");
	for (int i = 0; i < bricksGrid->getHeight(); i++) {
		for (int j = 0; j < bricksGrid->getWidth(); j++) {
			if (bricksGrid->getBrick(i, j) != nullptr) {
				file << i << " " << j << " " << bricksGrid->getBrick(i, j)->getType() << "\n";
			}
		}
	}
	file.close();
}

void game::loadBricksLocation(grid* bricksGrid, const string& file1)
{
	ifstream file("file.txt");
	int i, j;
	BrickType type;
	while (file >> i >> j /* >> type*/) {
		bricksGrid->addBrick(type, bricksGrid->getPoint(i, j));
	}
	file.close();
}


string game::getSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		printMessage(Label);
	}
}
void game::decreaseLife()
{
	if (lives > 0) {
		--lives;
	}
}
void game::displayLives() const
{
	std::ostringstream livesStream;
	livesStream << "Lives: " << lives;
	std::string livesString = livesStream.str();

	pWind->SetPen(RED);
	pWind->SetFont(14, BOLD, BY_NAME, "Arial");
	pWind->DrawString(1000, 550, livesString);
}
paddle* game::getPaddle() const {
	return playerPaddle;
}
void game::checkballbottom()
{
	if (gameBall->getYPosition() >= pWind->GetHeight() - (gameBall->getraduis() + 10))
	{
		//lives--;

		/*if (lives == 0)
		{
			printMessage("game over");
			gameBall->getresetposition();
		}*/
	}
}

grid* game::getGrid() const
{
	// TODO: Add your implementation code here.
	return bricksGrid;
}



////////////////////////////////////////////////////////////////////////
void game::go() const
{
	//This function reads the position where the user clicks to determine the desired operation
	int x, y;
	bool isExit = false;
	char key;

	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - Brick Breaker (CIE202-project) - - - - - - - - - -");

	do
	{
		displayLives();
		displayTime();
		//printMessage("Ready...");
		if (gameMode == MODE_DSIGN)
		{
			if (pWind->GetMouseClick(x, y) && y >= 0 && y < config.toolBarHeight)
			{
				isExit = gameToolbar->handleClick(x, y);
			}
			/*checkballbottom();*/
		}
		else
		{
			if (pWind->GetKeyPress(key) && key == ' ') {
				gameBall->ballmove();

				//playerPaddle->paddleMove();
			}
			playerPaddle->paddleMove();
		}

	} while (lives);
}
