#ifndef MOVABLEOBJECT_HPP_INCLUDED
#define MOVABLEOBJECT_HPP_INCLUDED


#include "Object.hpp"


class MovableObject : public Object, public Differentializable<MovableObject>
{
    public:
        MovableObject(bool grantMoving = true);
        MovableObject(float xCenter, float yCenter, float width, float height, float angle, bool grantMoving=true);

        inline void allowMoving(bool grantMoving = true);
        inline bool canMove() const;

        virtual std::string serialize();
        std::string differentialize(const MovableObject& newObject);

    private:
        bool grantMoving;
};


#endif
