#ifndef PROTOCOL_IN_HPP
#define PROTOCOL_IN_HPP


class Protocol_In
{
    public:
        Protocol_In(const std::string& paquet);

        virtual bool isCorrect() const;
        virtual int numberBytesRead() const;
        virtual std::string header() const;
};


class Protocol_Get : public Protocol_In
{
    public:
        Protocol_Get(const std::string& paquet);

        bool isCorrect();
        int numberBytesRead();
        std::string header() const;

        static bool isConstructible(const std::string& paquet);
        static std::shared_ptr<Protocol_Get> constructFromReceived(const std::string& paquet);
};


class Protocol_Action : public Protocol_In<Action>
{
    public:
        Protocol_Action(const std::string& paquet);

        bool isCorrect();
        int numberBytesRead();
        std::string header() const;

        static bool isConstructible(const std::string& paquet);
        static std::shared_ptr<Protocol_Action> constructFromReceived(const std::string& paquet);

    private:

};


#endif
