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
        void updateOrderReaction(const std::string& str, unsigned int id);

        void removeId(unsigned int id);

        typedef std::function<void(float)> Order;
        static Order constructOrder(const std::string& order);

    private:
        std::mutex mutexForSituationChange;
        Situation currentSituation;
        std::map<unsigned int, Situation> previousSituations;

        static unsigned int orderCounter;
        std::map<unsigned int, std::shared_ptr<Order> > ordersToTreat;

        std::mutex orderMutex;
        void updateOrders();
};


#endif
