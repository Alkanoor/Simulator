#ifndef SERVER_MANAGE_CONNEXIONS_HPP
#define SERVER_MANAGE_CONNEXIONS_HPP


#include "Tcp_Connexion.hpp"
#include "Server.hpp"


class Server_Manage_Connexions
{
    public:
        Server_Manage_Connexions(boost::asio::io_service& io_service);

        void setServer(std::shared_ptr<Server> serv);

    private:
        void start_accept();
        void handle_accept(Tcp_Connexion::pointer new_connection, const boost::system::error_code& error);

        tcp::acceptor acceptor;
        std::shared_ptr<Server> server;
};


#endif
