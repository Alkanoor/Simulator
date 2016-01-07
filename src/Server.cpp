#include "Server.hpp"


Server::Server(std::shared_ptr<MainEngine> engine, std::shared_ptr<AuthEngine> authEngine)
{
    this->engine = engine;
    this->authEngine = authEngine;
}

void Server::readMessageFrom(const std::string& str, unsigned int id)
{
    std::pair<ActionType,std::string> cut = ProtocolCutter::cut(str);
    std::cout<<"Action : "<<cut.first<<" next : "<<cut.second<<std::endl;
    switch(cut.first)
    {
        case GET_DIFF:
            entities[id].write(engine->computeDiff(cut.second));
            break;
        case GET_ALL:
            entities[id].write(engine->computeSituation(cut.second));
            break;
        case ACTION:
            engine->reacts(cut.second,entities[id].typeAuth());
            break;
        case AUTH:
            entities[id].setAuth(authEngine->check(cut.second));
            break;
        case UPDATE_ENTITY:
            entities[id].update(cut.second);
            break;
        case CHANGE_SYN:
            engine->changeType(cut.second,id);
            break;
        default:
            std::cout<<"Break"<<std::endl;
            break;
    }
}

void Server::addConnexion(std::shared_ptr<Tcp_Connexion> connexion)
{
    std::cout<<"Add connexion "<<getpid()<<std::endl;
    entities[connexion->getId()] = Entity_Status(connexion);
    std::cout<<connexion->getId()<<std::endl;
    connexion->setReadCallback(std::bind(&Server::readMessageFrom,*this,std::placeholders::_1,connexion->getId()));
    connexion->setDeconnexionCallback(std::bind(&Server::removeConnexion,*this,std::placeholders::_1));
}

void Server::removeConnexion(unsigned int idConnexion)
{
    std::cout<<"On rerase "<<idConnexion<<std::endl;
    entities.erase(idConnexion);
}
