#ifndef OBJECT_HPP_INCLUDED
#define OBJECT_HPP_INCLUDED


#include <sstream>

#include "Differentializable.hpp"
#include "Serializable.hpp"


class Object : public Serializable, public Differentializable<Object>
{
    public:
        Object();
        Object(float xCenter, float yCenter, float width, float height, float angle);

        inline void reset(float xCenter, float yCenter, float width, float height, float angle);
        inline void setXCenter(float xCenter);
        inline void setYCenter(float yCenter);
        inline void setWidth(float width);
        inline void setHeight(float height);
        inline void setAngle(float angle);

        inline float getXCenter() const;
        inline float getYCenter() const;
        inline float getWidth() const;
        inline float getHeight() const;
        inline float getAngle() const;
        inline bool isPositionSet() const;

        virtual std::string serialize();
        std::string differentialize(const Object& newObject);

    private:
        float xCenter, yCenter, width, height, angle;

        static unsigned int curMaxId;
        unsigned int id;

        bool positionSet[4];
        void resetPosition();
};


#endif
