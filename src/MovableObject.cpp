#include "../include/MovableObject.hpp"


MovableObject::MovableObject(bool grantMoving)
{this->grantMoving = grantMoving;}

MovableObject::MovableObject(float xCenter, float yCenter, float width, float height, float angle, bool grantMoving) :
    Object(xCenter,yCenter,width,height)
{this->grantMoving = grantMoving;}

void MovableObject::allowMoving(bool grantMoving)
{this->grantMoving = grantMoving;}

bool MovableObject::canMove() const
{return grantMoving;}
