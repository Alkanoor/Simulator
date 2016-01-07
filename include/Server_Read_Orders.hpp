#ifndef SERVER_READ_ORDERS_HPP
#define SERVER_READ_ORDERS_HPP


#include "Tcp_Connexion.hpp"
#include "Server.hpp"


class Server_Read_Orders
{
    public:
        Server_Read_Orders(boost::asio::io_service& io_service);

        void setServer(std::shared_ptr<Server> serv);

    private:
        void start_accept();
        void handle_accept(Tcp_Connexion::pointer new_connection, const boost::system::error_code& error);

        tcp::acceptor acceptor;
        std::shared_ptr<Server> server;
};


#endif
