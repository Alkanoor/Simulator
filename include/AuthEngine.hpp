#ifndef AUTH_ENGINE_HPP
#define AUTH_ENGINE_HPP


#include <string>


class AuthEngine
{
    public:
        AuthEngine();

        std::string check(const std::string& credential);

        static std::string defaultAuth();
        static void setPossibleAuths(const std::vector<std::string>& auths);

    private:
        static std::vector<std::string> possibleAuths;
};


#endif
