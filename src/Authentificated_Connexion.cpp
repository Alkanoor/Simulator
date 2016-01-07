#include "Authentificated_Connexion.hpp"


Authentificated_Connexion::Authentificated_Connexion(Tcp_Connexion& conn) :
    connexion(conn)
{}

void Authentificated_Connexion::modifyAuthType(unsigned int auth, const std::string& class_)
{}
