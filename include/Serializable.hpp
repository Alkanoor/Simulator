#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP


class Serializable
{
    public:
        virtual std::string serialize() = 0;
};


#endif
