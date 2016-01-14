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
