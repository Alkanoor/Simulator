#include "MainEngine.hpp"


MainEngine::MainEngine()
{}

std::string MainEngine::computeDiff(const std::string& str, unsigned int id)
{
    if(!situations.count(id))
    {
        situations[id] = currentSituation;
        mutexForSituationChange.lock();
        std::string toReturn = currentSituation.serialize();
        mutexForSituationChange.unlock();
        return toReturn;
    }

    mutexForSituationChange.lock();
    std::string toReturn = situations[id].differentialize(currentSituation);
    mutexForSituationChange.unlock();
    return toReturn;
}

std::string MainEngine::computeSituation(const std::string& str)
{
    mutexForSituationChange.lock();
    std::string toReturn = currentSituation.serialize();
    situations[id] = currentSituation;
    mutexForSituationChange.unlock();
    return toReturn;
}

void MainEngine::reacts(const std::string& str, unsigned int id)
{
    std::shared_ptr<Order> order = constructOrder(str,id,time());
    ORDER_REACTION_TYPE firstReaction = AuthEngine::getReactionType(orderCounter, id, order);

    if(firstReaction==AGREE)
    {
        currentSituation.apply(order);
        currentSituation.addOrderAccepted(order);
    }
    else if(firstReaction==WAIT_NETWORK)
    {
        ordersToTreat[orderCounter] = order;
        currentSituation.addOrderWaiting(order);
    }
    else
        currentSituation.addOrderDeleted(order);

    orderCounter++;
}

void MainEngine::updateOrderReaction(const std::string& str)
{
    unsigned int idOrder = getIdOrder(str);
    ORDER_REACTION_TYPE reaction = AuthEngine::getReactionType(idOrder);

    if(firstReaction==AGREE)
    {
        currentSituation.apply(ordersToTreat[idOrder]);
        currentSituation.addOrderAccepted(ordersToTreat[idOrder]);
    }
    else if(firstReaction==DISAGREE)
        currentSituation.addOrderDeleted(ordersToTreat[idOrder]);
}

void MainEngine::removeId(unsigned int id)
{

}

Order MainEngine::constructOrder(const std::string& order)
{

}

void MainEngine::updateOrders()
{
    orderMutex.lock();
    for(std::map<std::string, std::priority_queue<Order> >::iterator it=ordersToTreat.begin();it!=ordersToTreat.end();it++)
    {

    }
    std::map<std::string, OrderPolicy> policiesForAccessRights;
    orderMutex.unlock();
}
