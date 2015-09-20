/*#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>*/
#include "sockets/tcp_server.hpp"

using boost::asio::ip::tcp;

/*io_service ioservice;
tcp::endpoint tcp_endpoint(tcp::v4(), 2014);
tcp::acceptor tcp_acceptor(ioservice, tcp_endpoint);
//typedef boost::shared_ptr<tcp::socket> tcp_socket;
tcp::socket tcp_socket(ioservice);
std::string data;

void write_handler(const boost::system::error_code &ec,
  std::size_t bytes_transferred)
{
  if (!ec)
    tcp_socket.shutdown(tcp::socket::shutdown_send);
}*/

/*void doSomething() {
	boost::array<char, 128> buf;
	boost::system::error_code error;
	size_t len = tcp_socket.read_some(buffer(buf), error);
	async_write(tcp_socket, buffer(buf, len), write_handler);
	//doSomething();
}*/

int main()
{
	/*tcp_acceptor.listen();

	tcp_acceptor.accept(tcp_socket);
	async_write(tcp_socket, buffer("aaaaa"), write_handler);
	doSomething();
	ioservice.run();*/
	try
	  {
	    boost::asio::io_service io_service;
	    tcp_server server(io_service);
	    io_service.run();
	  }
	  catch (std::exception& e)
	  {
	    std::cerr << e.what() << std::endl;
	  }

	  return 0;
}
