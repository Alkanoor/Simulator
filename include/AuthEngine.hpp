#ifndef AUTH_ENGINE_HPP
#define AUTH_ENGINE_HPP


class AuthEngine
{
    public:
        AuthEngine();

        std::string check(const std::string& credential);

    private:
};


#endif
