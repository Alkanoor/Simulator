#ifndef AUTH_ENGINE_HPP
#define AUTH_ENGINE_HPP


#include <string>


class AuthEngine
{
    public:
        AuthEngine();

        std::string check(const std::string& credential);

    private:
};


#endif
