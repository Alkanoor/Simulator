#include "MainEngine.hpp"


MainEngine::MainEngine()
{}

std::string MainEngine::computeDiff(const std::string& str, unsigned int id)
{
    if(!situations.count(id))
        situations[id] = SituationDifferential();

    mutexForSituationChange.lock();
    std::string toReturn = situations[id].serialize(currentSituation);
    mutexForSituationChange.unlock();
    return toReturn;
}

std::string MainEngine::computeSituation(const std::string& str) const
{
    mutexForSituationChange.lock();
    std::string toReturn = currentSituation.serialize();
    mutexForSituationChange.unlock();
    return toReturn;
}

void MainEngine::reacts(const std::string& str, unsigned int id)
{
    Order o = constructOrder(str,id,time());
    if(!accesses.count(id))
        accesses[id] = AuthEngine::defaultAuth();

    if(policiesForAccessRights[accesses[id]].isVerified(o))
        currentSituation.apply(o);
    else
        ordersToTreat[accesses[id]].push(o);
}

void MainEngine::updateAuth(unsigned int id, const std::string& auth)
{
    accesses[id] = auth;
    updateOrders();

    if(!accesses.count(id))
        accesses[id] = auth;
    else
    {
        if(accesses[id]==auth)
            return;
        else
        {
            for(Order o : ordersToTreat[accesses[id]])
                if(policiesForAccessRights[accesses[id]].isVerified(o))
                    currentSituation.apply(o);
        }
    }
}

void MainEngine::updateOrderReaction(const std::string& str, unsigned int id)
{
    std::pair<unsigned int, AnswerType> orderIdAndAnswerType = extractIdAndTypeAcceptFromString(str);
    if(orderAcceptations.count(orderIdAndAnswerType.first))
    {
        orderAcceptations[orderIdAndAnswerType.first][id] = orderIdAndAnswerType.second;
        updateOrders();
    }
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
