#include <iostream>
#include <chrono>
using namespace std;

#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
using namespace boost::asio;

int main()
{
    io_service ioservice;

    steady_timer timer{ioservice, std::chrono::seconds{3}};
    timer.async_wait([](const boost::system::error_code &ec)
    {std::cout << "3 sec\n";});
 
    ioservice.run();
    return 0;
}
