#ifndef MAINENGINE_HPP
#define MAINENGINE_HPP


#include <string>
#include <queue>
#include <mutex>


class MainEngine
{
    public:
        MainEngine();

        std::string computeDiff(const std::string& str, unsigned int id);
        std::string computeSituation(const std::string& str);
        void reacts(const std::string& str, unsigned int id);
        void updateAuth(unsigned int id, const std::string& auth);
        void updateOrderReaction(const std::string& str, unsigned int id);

        void removeId(unsigned int id);

        typedef std::function<void(float)> Order;
        static Order constructOrder(const std::string& order);

    private:
        std::mutex mutexForSituationChange;
        Situation currentSituation;
        std::map<unsigned int, Situation> previousSituations;

        std::map<std::string, std::priority_queue<Order> > ordersToTreat;
        std::map<std::string, OrderPolicy> policiesForAccessRights;
        std::map<unsigned int, std::string> accesses;

        std::mutex orderMutex;
        void updateOrders();
};


#endif
