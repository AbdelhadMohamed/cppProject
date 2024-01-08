#pragma once
#include "CMUgraphicsLib/CMUgraphics.h"

__declspec(selectany) //This line to prevent "redefinition error"
struct 		//contains all game configurations (MAY be loaded from a configuration file later)
{
	int	windWidth=1215, windHeight=600,	//Window width and height
		wx=5, wy=5,			//Window starting coordinates

		//The window is divded into 4 areas: toolbar, bricks grid area, paddle area, statusbar
		toolBarHeight=40,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		statusBarHeight=50;	//Status Bar Height
	
	int remainingHeight = windHeight - toolBarHeight - statusBarHeight;

	int gridHeight = int(remainingHeight * (2 / 3.0)); 		//The grid is where bricks can be drawn
	int paddleAreaHeight = remainingHeight - gridHeight;	//The area dedicated for paddle

	color	penColor = BLUE,			//color used to draw lines/write messages
			bkGrndColor= LAVENDER,		//Background color
			statusBarColor = LIGHTSEAGREEN;	//background color of the status
	int penWidth=3;			//width of the pen that draws shapes


	int brickWidth = 50;
	int brickHeight = 25;
	color gridLinesColor = LAVENDER;


	int	iconWidth=70;			//Width of each icon in toolbar 
//===========================================================
	int paddleWidth = 200;
	int paddleHight = 15;
	color paddleColor = BLUE;
//===========================================================
	int ballRad = 7;
	int ballWidth = 14;
	int ballHight = 14;
	color ballColor = BLUE;
	//====================================================
	int wallHight = windHeight;
	int wallWidth = 5;
	color wallCollor = BLUE;
	int wallUP_H = 5;
	int wallUP_W = windWidth;

}config;
