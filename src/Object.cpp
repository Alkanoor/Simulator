#include "../include/Object.hpp"


Object::Object() :
    id(currentMaxId),
    angle(0)
{currentMaxId++;}

Object::Object(float xCenter, float yCenter, float width, float height, float angle) :
    id(currentMaxId)
{
    currentMaxId++;
    reset(xCenter, yCenter, width, height, angle);
}

void Object::reset(float xCenter, float yCenter, float width, float height, float angle)
{
    this->xCenter = xCenter;
    this->yCenter = yCenter;
    this->width = width;
    this->height = height;
    this->angle = angle;
    for(unsigned int i=0;i<4;i++)
        positionSet[i] = true;
}

void Object::setXCenter(float xCenter)
{this->xCenter = xCenter;positionSet[0] = true;}
void Object::setYCenter(float yCenter)
{this->yCenter = yCenter;positionSet[1] = true;}
void Object::setWidth(float width)
{this->width = width;positionSet[2] = true;}
void Object::setHeight(float height)
{this->height = height;positionSet[3] = true;}

float Object::getXCenter() const
{return xCenter;}
float Object::getYCenter() const
{return yCenter;}
float Object::getWidth() const
{return width;}
float Object::getHeight() const
{return height;}
bool Object::isPositionSet() const
{return positionSet[0]&&positionSet[1]&&positionSet[2]&&positionSet[3];}

void Object::resetPosition()
{
    for(unsigned int i=0;i<4;i++)
        positionSet[i] = false;
}
