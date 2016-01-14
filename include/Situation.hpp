#ifndef SITUATION_HPP_INCLUDED
#define SITUATION_HPP_INCLUDED


#include "Robot.hpp"


class Situation : public Serializable, public Differentializable<Situation>
{
    public:
        void addElement(std::shared_ptr<Object> obstacle);
        void addElement(std::shared_ptr<MovableObject> movableObject);
        void addElement(std::shared_ptr<Robot> robot);

        std::string serialize();
        std::string differentialize(const Situation& newSituation);

    private:
        std::vector<std::shared_ptr<Object> > obstacles;
        std::vector<std::shared_ptr<MovableObject> > movableObjects;
        std::vector<std::shared_ptr<Robot> > robots;
};


#endif
