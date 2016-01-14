#ifndef ROBOT_HPP_INCLUDED
#define ROBOT_HPP_INCLUDED


#include "MovableObject.hpp"


class Robot : public MovableObject
{
    public:
        Robot(int team, int size);
        Robot(int team, int size, float xCenter, float yCenter, float width, float height, float angle);

        inline void setTeam(int team);
        inline void setSize(int size);
        inline int getTeam() const;
        inline int getSize() const;

    private:
        int team;
        int size;
};


#endif
