#ifndef ENTITY_STATUS_HPP
#define ENTITY_STATUS_HPP


#include "Tcp_Connexion.hpp"


class Entity_Status
{
    public:
        Entity_Status();
        Entity_Status(std::shared_ptr<Tcp_Connexion> connexion, const std::string& name = "");

        void write(const std::string& toSend);

        void update(const std::string& str);

        void setAuth(const std::string& auth);
        std::string typeAuth() const;
        std::string getName() const;

        ORDER_REACTION_TYPE getIndividualReaction();

    private:
        std::shared_ptr<Tcp_Connexion> connexion;
        std::string authType;
        std::string name;

        std::map<unsigned int, ORDER_REACTION_TYPE> reactionsToOrders;
};


#endif
