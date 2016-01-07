#ifndef AUTHENTIFICATED_CONNEXION_HPP
#define AUTHENTIFICATED_CONNEXION_HPP


#include "Tcp_Connexion.hpp"
#include "Entity_Status.hpp"


class Authentificated_Connexion
{
    public:
        Authentificated_Connexion(Tcp_Connexion& conn);

        void modifyAuthType(unsigned int auth, const std::string& class_);

    private:
        Tcp_Connexion& connexion;
        Entity_Status status;
        unsigned int id_connexion;

        static std::map<std::string, Authentificated_Connexion> auth_classes;
};


#endif
