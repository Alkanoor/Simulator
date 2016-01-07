#include "Tcp_Connexion.hpp"


unsigned int Tcp_Connexion::numberEntities = 0;

Tcp_Connexion::Tcp_Connexion(boost::asio::io_service& io_service) : socket(io_service)
{
    this->id = numberEntities;
    numberEntities++;
}

Tcp_Connexion::pointer Tcp_Connexion::create(boost::asio::io_service& io_service)
{
    Tcp_Connexion::pointer ptr(new Tcp_Connexion(io_service));
    return ptr->getThis();
}

tcp::socket& Tcp_Connexion::getSocket()
{
    return socket;
}

void Tcp_Connexion::start()
{
    boost::asio::async_read(socket, rbuf,
        boost::asio::transfer_at_least(1), boost::bind(&Tcp_Connexion::handle_read, shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Tcp_Connexion::setReadCallback(const std::function<void(const std::string&)>& callback)
{
    readCallback = callback;
}

void Tcp_Connexion::setDeconnexionCallback(const std::function<void(unsigned int)>& callback)
{
    deconnexionCallback = callback;
}

void Tcp_Connexion::write(const std::string& message)
{
    boost::asio::async_write(socket, boost::asio::buffer(message),
        boost::bind(&Tcp_Connexion::handle_write, shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

unsigned int Tcp_Connexion::getId() const
{
    return id;
}

Tcp_Connexion::pointer Tcp_Connexion::getThis()
{
    return shared_from_this();
}

void Tcp_Connexion::handle_write(const boost::system::error_code& err, size_t bytesTransferred)
{
    if(err)
    {
        if(deconnexionCallback)
            deconnexionCallback(id);
        std::cout<<"Deconnexion of id "<<id<<std::endl;
    }
}

void Tcp_Connexion::handle_read(const boost::system::error_code& err, size_t bytesTransferred)
{
    if(!err&&bytesTransferred>0)
    {
        rbuf.commit(bytesTransferred);

        std::istream is(&rbuf);
        std::string s;
        is>>s;
        std::cout<<bytesTransferred<<" Read : "<<s<<std::endl;
        readCallback(s);

        boost::asio::async_read(socket, rbuf,
            boost::asio::transfer_at_least(1), boost::bind(&Tcp_Connexion::handle_read, shared_from_this(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));
    }
    else
        if(deconnexionCallback)
            deconnexionCallback(id);
}
