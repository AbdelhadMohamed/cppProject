#include "ball.h"
#include "game.h"
#include "gameConfig.h"
#include "CMUgraphicsLib/auxil.h"


ball::ball(point r_uprleft, int ballWidth, int ballHight, game* r_pGame) :
	collidable(r_uprleft, ballWidth, ballHight, r_pGame) {}
void ball::draw() const
{

		window* pWind = pGame->getWind();
		pWind->SetPen(config.ballColor, 20);
		pWind->DrawCircle(600, 520, 10);

}
void ball::collisionAction()
{

}
int ball::getresetposition() {

    return x = intx;
    return y = inty;

}
int ball::getraduis() 
{
    return rad;
}


int ball::getYPosition()
{
	return y;
}

int ball::getXPosition()
{
	return x;
}
void ball::ballmove()
{
    window* pWind = pGame->getWind();
    char cKeyData;
    keytype kType;
    color c = BLUE;
    color bg = LAVENDER;
    pWind->SetFont(20, BOLD, BY_NAME, "Arial");
    int x = 600;
    int y = 520;
    int rad = 10;
    int newy = 0;
    int newx = 0;

    do {
        grid* gameGrid = pGame->getGrid();
        for (int i = 0; i < gameGrid->getRows(); ++i) {
            for (int j = 0; j < gameGrid->getCols(); ++j) {
                brick* currentBrick = gameGrid->getBrickAt(i, j);
                if (currentBrick && is_collision(this, currentBrick)) {
                    this->CollisionHandlerwithpaddle(this, currentBrick);
                }
            }
        }
        paddle* thePaddle = (pGame->getPaddle());
        bool collisionOccurred = is_collision(this, thePaddle);
        if (collisionOccurred) {
            this->CollisionHandlerwithpaddle(this, thePaddle);
        }
        if (uprLft.y >= (pGame->getWind()->GetHeight() - (rad + 50))) {
            pGame->decreaseLife();
        }
        kType = pWind->GetKeyPress(cKeyData);


        if (cKeyData == ' ')
        {
            newy = -10;
        }


        if ((x <= rad) || (x >= pWind->GetWidth() - rad))
            newx = -newx;
        if ((y <= (rad + 55)))
            newy = -newy;


        pWind->SetPen(bg);
        pWind->SetBrush(bg);
        pWind->DrawCircle(x, y, rad);


        y += newy;
        x += newx;


        pWind->SetPen(c);
        pWind->SetBrush(c);
        pWind->DrawCircle(x, y, rad);

        Pause(20);

    } while (kType != ESCAPE);
}

//void ball::sety(int y1)
//{
//    y1 = y;
//}
//
//void ball::setx(int x1)
//{
//    x1 = x;
//}
//
//void ball::setnewx(int newx1)
//{
//    newx1 = newx;
//}
//void ball::setnewy(int newy1)
//{
//    newy1 = newy;
//}
//
//int ball::getYPosition()
//{
//    return y;
//}
//
//int ball::getPositionx()
//{
//    return 0;
//}
//
//int ball::getnewx()
//{
//    return 0;
//}
//
//int ball::getnewy()
//{
//    return 0;
//}
//
//void ball::ballmove()
//{
//    window* pWind = pGame->getWind();
//    char cKeyData;
//    keytype kType;
//    color c = BLUE;
//    color bg = LAVENDER;
//    pWind->SetFont(20, BOLD, BY_NAME, "Arial");
//    int rad = 10;
//
//    kType = pWind->GetKeyPress(cKeyData);
//
//    if (cKeyData == ' ')
//    {
//        setnewy(-10);
//    }
//
//    if ((getPositionx() <= rad) || (getPositionx() >= pWind->GetWidth() - rad))
//        setnewx(-getnewx());
//    if ((getYPosition() <= (rad + 55)) || (getYPosition() >= (pWind->GetHeight() - (rad + 50))))
//        setnewy(-getnewy());
//
//    pWind->SetPen(bg);
//    pWind->SetBrush(bg);
//    pWind->DrawCircle(getPositionx(), getYPosition(), rad);
//
//    sety(getYPosition() + getnewy());
//    setx(getPositionx() + getnewx());
//
//    draw();
//
//    Pause(20);
//}
