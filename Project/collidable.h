#pragma once
#include "drawable.h"

class collidable : public drawable {
public:
    bool collision;

    collidable(point r_uprleft, int r_width, int r_height, game* r_pGame);
    bool is_collision(collidable* obj, collidable* obj2);
    virtual void collisionAction() = 0; // action that should be performed upon collision
    void CollisionHandlerwithpaddle(collidable* obj, collidable* obj2);
    void CollisionHandlerwithbrick(collidable* obj, collidable* obj2);
};
