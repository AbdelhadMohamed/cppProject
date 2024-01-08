#include "collidable.h"
#include<iostream>
#include "ball.h"
#include<cmath>
using namespace std;
collidable::collidable(point r_uprleft, int r_width, int r_height, game* r_pGame) :
    drawable(r_uprleft, r_width, r_height, r_pGame)
{
}
double const pi = 3.14;
bool collidable::is_collision(collidable* obj, collidable* obj2) {
    collision = false;
    int top_1 = obj->uprLft.y;
    int bot_1 = obj->uprLft.y + obj->height;
    int left_1 = obj->uprLft.x;
    int right_1 = obj->uprLft.x + obj->width;
    int top_2 = obj2->uprLft.y;
    int bot_2 = top_2 + obj2->height;
    int left_2 = obj2->uprLft.x;
    int right_2 = left_2 + obj2->width;
    cout << top_1 << "baddle " << bot_2;
    if (((top_1 == bot_2 && left_1 <= right_2 && right_1 >= left_2) ||
        (top_2 == bot_1 && left_1 <= right_2 && right_1 >= left_2)) &&
        (obj->uprLft.x < 1200 && obj->uprLft.x> 0 && obj->uprLft.y < 600 && obj->uprLft.y > 0)) {
        return true;
    }
    else {
        return collision;
    }
};
void collidable::CollisionHandlerwithpaddle(collidable* obj, collidable* obj2) {
    if (is_collision(obj, obj2)) {
        int paddleCenter = obj2->uprLft.x + (obj2->width / 2);
        int distanceFromCenter = abs(obj->uprLft.x - paddleCenter);
        int normalizedDistance = static_cast<double>(distanceFromCenter) / (obj2->width / 2);
        normalizedDistance = max(0.0, min(1.0, normalizedDistance)); // Corrected to 1.0 because the maximum normalized distance should be 1
        int incidentAngle = (normalizedDistance) * 90.0; // This gives you the incident angle based on the normalized distance
        // Assuming you want to calculate the new position based on the angle
        double angleInRadians = incidentAngle * (pi / 180.0); // Convert to radians
        obj->uprLft.x += static_cast<int>(cos(angleInRadians) + sqrt(2));
        obj->uprLft.y += static_cast<int>(-sin(angleInRadians) - sqrt(2)); // Assuming negative y is up
    }
}
void collidable::CollisionHandlerwithbrick(collidable* obj, collidable* obj2) {
    if (is_collision(obj, obj2)) {
        int BRICKCenter = obj2->uprLft.x + (obj2->width / 2);
        int distanceFromCenter = abs(obj->uprLft.x - BRICKCenter);
        int normalizedDistance = static_cast<double>(distanceFromCenter) / (obj2->width / 2);
        normalizedDistance = max(0.0, min(1.0, normalizedDistance)); // Corrected to 1.0 because the maximum normalized distance should be 1
        int incidentAngle = (normalizedDistance) * 90.0; // This gives you the incident angle based on the normalized distance
        // Assuming you want to calculate the new position based on the angle
        double angleInRadians = incidentAngle * (pi / 180.0); // Convert to radians
        obj->uprLft.x += static_cast<int>(cos(angleInRadians) + sqrt(2));
        obj->uprLft.y += static_cast<int>(-sin(angleInRadians) - sqrt(2)); // Assuming negative y is up
    }
}