#ifndef AUTH_ENGINE_HPP
#define AUTH_ENGINE_HPP


#include <string>

#include "OrderPolicy.hpp"
#include "OrderPolicyWithPrivileges.hpp"


class AuthEngine
{
    public:
        AuthEngine();

        void setEntitiesForReaction(std::map<unsigned int, Entity_Status>* entities);

        std::string check(const std::string& credential);

        static std::string defaultAuth();
        static void setPossibleAuths(const std::vector<std::string>& auths);

        ///pour tous les id de la map ayant un niveau de privilège supérieur (verticalement) à l'id emitter, les agglomérer en map de vector et les passer dans la politique
        ///correspondante. Passer les résultats dans la dernière politique avec privilèges. Ajout de l'ordre (id) et des entités supérieures dans concernedEntitiesForOrders.
        static ORDER_REACTION_TYPE getReactionType(unsigned int idOrder, unsigned int idOrderEmitter, const Order& order);
        static ORDER_REACTION_TYPE getReactionType(unsigned int idOrder);

    private:
        static std::vector<std::string> possibleAuths;

        static std::map<unsigned int, std::string> accesses;
        static std::map<std::string, std::shared_ptr<OrderPolicy> > policiesForOrderReaction;
        static OrderPolicyWithPrivileges finalPolicy;

        std::vector<unsigned int, std::vector<unsigned int> > concernedEntitiesForOrders;
        std::map<unsigned int, Entity_Status>* entitiesForReaction;
};


#endif
