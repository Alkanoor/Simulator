#ifndef TCP_CONNEXION_HPP
#define TCP_CONNEXION_HPP


#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <iostream>


using boost::asio::ip::tcp;

class Tcp_Connexion : public boost::enable_shared_from_this<Tcp_Connexion>
{
    public:
        typedef std::shared_ptr<Tcp_Connexion> pointer;

        static pointer create(boost::asio::io_service& io_service);
        tcp::socket& getSocket();
        void start();

        void setReadCallback(const std::function<void(const std::string&)>& callback);
        void setDeconnexionCallback(const std::function<void(unsigned int)>& callback);
        void write(const std::string& message);

        unsigned int getId() const;

    private:
        Tcp_Connexion(boost::asio::io_service& io_service);

        void handle_write(const boost::system::error_code& err, size_t bytesTransferred);
        void handle_read(const boost::system::error_code& err, size_t bytesTransferred);

        tcp::socket socket;
        std::string message;
        boost::asio::streambuf rbuf;

        std::function<void(const std::string&)> readCallback;
        std::function<void(unsigned int)> deconnexionCallback;

        unsigned int id;
        static unsigned int numberEntities;
};


#endif
