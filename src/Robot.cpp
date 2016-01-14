#include "../include/Robot.hpp"


Robot::Robot(int team, int size)
{
    this->team = team;
    this->size = size;
}

Robot::Robot(int team, int size, float xCenter, float yCenter, float width, float height, float angle) :
    MovableObject(xCenter,yCenter,width,height,angle)
{
    this->team = team;
    this->size = size;
}

void Robot::setTeam(int team)
{this->team = team;}

void Robot::setSize(int size)
{this->size = size;}

int Robot::getTeam() const
{return team;}

int Robot::getSize() const
{return size;}

std::string Robot::serialize()
{
    std::stringstream converter;
    converter<<"ro["<<MovableObject::serialize()<<";"<<team<<";"<<size<<"]";
    return converter.str();
}

std::string Robot::differentialize(const Robot& newObject)
{
    std::stringstream converter;
    if(team==newObject.team)
        if(size==newObject.size)
            converter<<"ro_d00["<<MovableObject::differentialize(newObject)<<"]";
        else
            converter<<"ro_d01["<<MovableObject::differentialize(newObject)<<";"<<newObject.size<<"]";
    else
        if(size==newObject.size)
            converter<<"ro_d10["<<MovableObject::differentialize(newObject)<<";"<<newObject.team<<"]";
        else
            converter<<"ro_d11["<<MovableObject::differentialize(newObject)<<";"<<newObject.team<<";"<<newObject.size<<"]";
    return converter.str();
}
