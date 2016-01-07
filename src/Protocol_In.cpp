#include "Protocol_In.hpp"


Protocol_In::Protocol_In(const std::string& paquet)
{}

bool Protocol_In::isCorrect() const
{
    return true;
}

int Protocol_In::numberBytesRead() const
{
    return 1;
}

std::string Protocol_In::header() const
{
    return "";
}

Protocol_Get::Protocol_Get(const std::string& paquet) :
    Protocol_In(paquet)
{}

bool Protocol_Get::isCorrect()
{
    return true;
}

int Protocol_Get::numberBytesRead()
{
    return 0;
}

std::string Protocol_Get::header() const
{
    return "";
}

bool Protocol_Get::isConstructible(const std::string& paquet)
{
    return false;
}

std::shared_ptr<Protocol_Get> Protocol_Get::constructFromReceived(const std::string& paquet)
{
    return std::shared_ptr<Protocol_Get>();
}

Protocol_Action::Protocol_Action(const std::string& paquet) :
    Protocol_In(paquet)
{}

bool Protocol_Action::isCorrect()
{
    return false;
}

int Protocol_Action::numberBytesRead()
{
    return 0;
}

std::string Protocol_Action::header() const
{
    return "";
}

bool Protocol_Action::isConstructible(const std::string& paquet)
{
    return false;
}

std::shared_ptr<Protocol_Action> Protocol_Action::constructFromReceived(const std::string& paquet)
{
    return std::shared_ptr<Protocol_Action>();
}
