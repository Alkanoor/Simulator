#include "Server_Read_Orders.hpp"


Server_Read_Orders::Server_Read_Orders(boost::asio::io_service& io_service) : acceptor(io_service, tcp::endpoint(tcp::v4(), 13))
{
    start_accept();
}

void Server_Read_Orders::start_accept()
{
    Tcp_Connexion::pointer new_connection = Tcp_Connexion::create(acceptor.get_io_service());

    acceptor.async_accept(new_connection->getSocket(),
        boost::bind(&Server_Read_Orders::handle_accept, this, new_connection,
        boost::asio::placeholders::error));
}

void Server_Read_Orders::handle_accept(Tcp_Connexion::pointer new_connection, const boost::system::error_code& error)
{
    if(!error)
    {
        new_connection->start();
        start_accept();
        server->addConnexion(new_connection);
    }
}
