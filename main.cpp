#include "Server_Manage_Connexions.hpp"


int main()
{
    try
    {
        boost::asio::io_service io_service;
        Server_Manage_Connexions physicalServer(io_service);

        std::shared_ptr<MainEngine> mainEngine(new MainEngine());
        std::shared_ptr<AuthEngine> authEngine(new AuthEngine());
        std::shared_ptr<Server> server(new Server(mainEngine,authEngine));
        physicalServer.setServer(server);

        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
