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
void Object::setAngle(float angle)
{this->angle = angle;}

float Object::getXCenter() const
{return xCenter;}
float Object::getYCenter() const
{return yCenter;}
float Object::getWidth() const
{return width;}
float Object::getHeight() const
{return height;}
float Object::getAngle() const
{return angle;}
bool Object::isPositionSet() const
{return positionSet[0]&&positionSet[1]&&positionSet[2]&&positionSet[3];}

void Object::resetPosition()
{
    for(unsigned int i=0;i<4;i++)
        positionSet[i] = false;
}

std::string Object::serialize()
{
    std::stringstream converter;
    converter<<"ob["<<isPositionSet()<<";"<<xCenter<<";"<<yCenter<<";"<<width<<";"<<height<<";"<<angle<<"]";
    return converter.str();
}

std::string Object::differentialize(const Object& newObject)
{
    std::stringstream converter;
    bool changed[6];
    if(isPositionSet()==newObject.isPositionSet())
        changed[0] = false;
    else
        changed[0] = true;
    if(abs(newObject.getXCenter()-xCenter)<0.00001)
        changed[1] = false;
    else
        changed[1] = true;
    if(abs(newObject.getYCenter()-yCenter)<0.00001)
        changed[2] = false;
    else
        changed[2] = true;
    if(abs(newObject.getWidth()-width)<0.00001)
        changed[3] = false;
    else
        changed[3] = true;
    if(abs(newObject.getHeight()-height)<0.00001)
        changed[4] = false;
    else
        changed[4] = true;
    if(abs(newObject.getAngle()-angle)<0.00001)
        changed[5] = false;
    else
        changed[5] = true;

    converter<<"ob_d";
    for(unsigned int i=0;i<6;i++)
        converter<<changed[i];
    converter<<"[";
    bool firstAdded = false;
    for(unsigned int i=0;i<6;i++)
        if(changed[i])
        {
            if(firstAdded)
                converter<<";";
            firstAdded = true;
            switch(i)
            {
                case 0:
                    converter<<newObject.isPositionSet();
                    break;
                case 1:
                    converter<<newObject.xCenter;
                    break;
                case 2:
                    converter<<newObject.yCenter;
                    break;
                case 3:
                    converter<<newObject.width;
                    break;
                case 4:
                    converter<<newObject.height;
                    break;
                case 5:
                    converter<<newObject.angle;
                    break;
            }
        }
    converter<<"]";
    return converter.str();
}
