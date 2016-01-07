#ifndef MAINENGINE_HPP
#define MAINENGINE_HPP


class MainEngine
{
    public:
        MainEngine();

        std::string computeDiff();
        std::string computeSituation();
        void reacts(const std::string& str);
        void changeType(const std::string& str, unsigned int id);

    private:
};


#endif
