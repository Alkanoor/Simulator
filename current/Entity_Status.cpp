#include "Entity_Status.hpp"


Entity_Status::Entity_Status()
{}

Entity_Status::Entity_Status(std::shared_ptr<Tcp_Connexion> connexion, const std::string& name)
{
    this->connexion = connexion;
    this->name = name;
}

void Entity_Status::write(const std::string& toSend)
{
    connexion->write(toSend);
}

void Entity_Status::update(const std::string& str)
{
    name = str;
}

void Entity_Status::setAuth(const std::string& auth)
{
    authType = auth;
}

std::string Entity_Status::typeAuth() const
{return authType;}

std::string Entity_Status::getName() const
{return name;}

void Entity_Status::setDefaultOrderReaction(ORDER_REACTION_TYPE reaction)
{
    defaultReaction = reaction;
}

void Entity_Status::updateOrderReaction(unsigned int orderId, ORDER_REACTION_TYPE reaction)
{
    if(reactionsToOrders.count(orderId))
        reactionsToOrders[orderId] = reaction;
}

ORDER_REACTION_TYPE Entity_Status::getIndividualReaction(const Order& order) const
{
    return getIndividualReaction(order.getId());
}

ORDER_REACTION_TYPE Entity_Status::getIndividualReaction(unsigned int orderId) const
{
    if(!reactionsToOrders.count(orderId))
        reactionsToOrders[orderId] = defaultReaction;
    return reactionsToOrders[orderId];
}
