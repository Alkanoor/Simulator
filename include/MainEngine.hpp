#ifndef MAINENGINE_HPP
#define MAINENGINE_HPP


#include <string>


class MainEngine
{
    public:
        MainEngine();

        std::string computeDiff(const std::string& str);
        std::string computeSituation(const std::string& str);
        void reacts(const std::string& str, const std::string& typeAuth);
        void changeType(const std::string& str, unsigned int id);

    private:
};


#endif
