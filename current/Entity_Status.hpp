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

        void setDefaultOrderReaction(ORDER_REACTION_TYPE reaction);
        void updateOrderReaction(unsigned int orderId, ORDER_REACTION_TYPE reaction);

        ORDER_REACTION_TYPE getIndividualReaction(const Order& order) const;
        ORDER_REACTION_TYPE getIndividualReaction(unsigned int orderId) const;

    private:
        std::shared_ptr<Tcp_Connexion> connexion;
        std::string authType;
        std::string name;

        ORDER_REACTION_TYPE defaultReaction;
        std::map<unsigned int, ORDER_REACTION_TYPE> reactionsToOrders;
};


#endif
