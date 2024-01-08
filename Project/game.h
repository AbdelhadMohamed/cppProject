#pragma once
#include "CMUgraphicsLib\CMUgraphics.h"
#include "toolbar.h"
#include "grid.h"
#include "paddle.h"
#include "ball.h"
#include "wall.h"
#include <chrono>



//Main class that coordinates the game operation
class game
{
	/// Add more members if needed

protected:
	std::chrono::steady_clock::time_point startTime;
	int lives;
	window* pWind;	//Pointer to the CMU graphics window
	toolbar* gameToolbar;
	grid* bricksGrid;
	wall* gamewall_L;
	wall* gamewall_R;

public:
	paddle* playerPaddle;
	ball* gameBall;
	enum MODE	//Game mode
	{
		MODE_DSIGN,	//Desing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	MODE gameMode;
	game();
	~game();

	clicktype getMouseClick(int& x, int& y) const;//Get coordinate where user clicks and returns click type (left/right)
	string getSrting() const;	 //Returns a string entered by the user

	void checkballbottom();


	window* CreateWind(int, int, int, int) const; //creates the game window


	void clearStatusBar() const;	//Clears the status bar


	void printMessage(string msg) const;	//Print a message on Status bar

	void go() const;

	window* getWind() const;		//returns a pointer to the graphics window

	void saveBricksLocation(grid* bricksGrid, const string& file1);

	void loadBricksLocation(grid* bricksGrid, const string& file1);
	paddle* getPaddle() const;
	void displayLives() const;
	void displayTime() const;
	void decreaseLife();

	grid* getGrid() const;
};

