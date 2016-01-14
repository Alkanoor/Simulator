#ifndef MOVABLEOBJECT_HPP_INCLUDED
#define MOVABLEOBJECT_HPP_INCLUDED


#include "Object.hpp"


class MovableObject : public Object
{
    public:
        MovableObject(bool grantMoving = true);
        MovableObject(float xCenter, float yCenter, float width, float height, float angle, bool grantMoving=true);

        inline void allowMoving(bool grantMoving = true);
        inline bool canMove() const;

    private:
        bool grantMoving;
};


#endif
