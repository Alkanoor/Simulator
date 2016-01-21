#include "../include/Situation.hpp"


void Situation::addElement(std::shared_ptr<Object> obstacle)
{
    obstacles.push_back(obstacle);
}

void Situation::addElement(std::shared_ptr<MovableObject> movableObject)
{
    movableObjects.push_back(movableObject);
}

void Situation::addElement(std::shared_ptr<Robot> robot)
{
    robots.push_back(robot);
}

std::string Situation::serialize()
{
    std::stringstream converter;
    converter<<"si[";
    bool addSeparator = false;
    for(unsigned int i=0;i<obstacles.size();i++)
    {
        if(addSeparator)
            converter<<";";
        addSeparator = true;
        converter<<obstacles[i]->serialize();
    }
    for(unsigned int i=0;i<movableObjects.size();i++)
    {
        if(addSeparator)
            converter<<";";
        addSeparator = true;
        converter<<movableObjects[i]->serialize();
    }
    for(unsigned int i=0;i<robots.size();i++)
    {
        if(addSeparator)
            converter<<";";
        addSeparator = true;
        converter<<robots[i]->serialize();
    }
    converter<<"]";
    return converter.str();
}

std::string Situation::differentialize(const Situation& newSituation)
{
    std::stringstream converter;
    converter<<"si_d";
    int dif1 = (int)newSituation.obstacles.size()-(int)obstacles.size();
    int dif2 = (int)newSituation.movableObjects.size()-(int)movableObjects.size();
    int dif3 = (int)newSituation.robots.size()-(int)robots.size();
    converter<<dif1<<";"<<dif2<<";"<<dif3<<"[";

    bool addSeparator = false;
    for(unsigned int i=0;i<newSituation.obstacles.size();i++)
    {
        if(addSeparator)
            converter<<";";
        addSeparator = true;
        if(i<obstacles.size())
            converter<<obstacles[i]->differentializable(newSituation.obstacles[i]);
        else
            converter<<obstacles[i]->serialize();
    }

    for(unsigned int i=0;i<newSituation.movableObjects.size();i++)
    {
        if(addSeparator)
            converter<<";";
        addSeparator = true;
        if(i<movableObjects.size())
            converter<<movableObjects[i]->differentializable(newSituation.movableObjects[i]);
        else
            converter<<movableObjects[i]->serialize();
    }

    for(unsigned int i=0;i<newSituation.robots.size();i++)
    {
        if(addSeparator)
            converter<<";";
        addSeparator = true;
        if(i<robots.size())
            converter<<robots[i]->differentializable(newSituation.robots[i]);
        else
            converter<<robots[i]->serialize();
    }

    converter<<"]";
    return converter.str();
}
