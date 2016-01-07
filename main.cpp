#include "Server_Read_Orders.hpp"


int main()
{
  try
  {
    boost::asio::io_service io_service;
    Server_Read_Orders server(io_service);
    io_service.run();
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
