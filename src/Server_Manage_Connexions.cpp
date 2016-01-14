#include "Server_Manage_Connexions.hpp"


Server_Manage_Connexions::Server_Manage_Connexions(boost::asio::io_service& io_service) : acceptor(io_service, tcp::endpoint(tcp::v4(), 13120))
{
    start_accept();
}

void Server_Manage_Connexions::setServer(std::shared_ptr<Server> serv)
{
    server = serv;
}

void Server_Manage_Connexions::start_accept()
{
    std::cout<<"Start accept "<<getpid()<<std::endl;
    Tcp_Connexion::pointer new_connection = Tcp_Connexion::create(acceptor.get_io_service());
    std::cout<<"Start accept "<<getpid()<<" "<<&new_connection<<std::endl;

    acceptor.async_accept(new_connection->getSocket(),
        boost::bind(&Server_Manage_Connexions::handle_accept, this, new_connection,
        boost::asio::placeholders::error));
    std::cout<<"Start accept "<<getpid()<<" "<<&(*new_connection)<<std::endl;
}

void Server_Manage_Connexions::handle_accept(Tcp_Connexion::pointer new_connection, const boost::system::error_code& error)
{
    if(!error)
    {
        std::cout<<"Accept connexion "<<getpid()<<" "<<&(*new_connection)<<std::endl;
        new_connection->start();
        std::cout<<"Accept connexion "<<getpid()<<std::endl;
        server->addConnexion(new_connection);
        std::cout<<"Accept connexion "<<getpid()<<std::endl;
        start_accept();
        std::cout<<"Accept connexion "<<getpid()<<std::endl;
    }
}
