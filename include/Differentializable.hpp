#ifndef DIFFERENTIALIZABLE_HPP_INCLUDED
#define DIFFERENTIALIZABLE_HPP_INCLUDED


template <typename T>
class Differentializable
{
    public:
        virtual std::string differentialize(const T& newObject) = 0;
};


#endif
