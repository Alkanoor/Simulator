#ifndef SERVER_HPP
#define SERVER_HPP


#include "ProtocolCutter.hpp"
#include "Entity_Status.hpp"
#include "MainEngine.hpp"
#include "AuthEngine.hpp"

#include <iostream>


class Server
{
    public:
        Server(std::shared_ptr<MainEngine> engine, std::shared_ptr<AuthEngine> authEngine);

        void readMessageFrom(const std::string& str, unsigned int id);

        void addConnexion(std::shared_ptr<Tcp_Connexion> connexion);
        void removeConnexion(unsigned int idConnexion);

    private:
        std::map<unsigned int, Entity_Status> entities;
        std::shared_ptr<MainEngine> engine;
        std::shared_ptr<AuthEngine> authEngine;
};


#endif
