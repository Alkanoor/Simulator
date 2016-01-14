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

std::string MovableObject::serialize()
{
    std::stringstream converter;
    converter<<"mo["<<Object::serialize()<<";"<<grantMoving<<"]";
    return converter.str();
}

std::string MovableObject::differentialize(const MovableObject& newObject)
{
    std::stringstream converter;
    if(grantMoving==newObject.canMove())
        converter<<"mo_d["<<Object::differentialize(newObject)<<"]";
    else
        converter<<"mo_d1["<<Object::differentialize(newObject)<<";"<<newObject.canMove()<<"]";
    return converter.str();
}
