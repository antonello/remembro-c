/*
 * tcp_connection.hpp
 *
 *  Created on: 15 Sep 2015
 *      Author: delio
 */

#ifndef SOCKETS_TCP_CONNECTION_HPP_
#define SOCKETS_TCP_CONNECTION_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::tcp;

class tcp_connection
  : public boost::enable_shared_from_this<tcp_connection>
{
public:
  typedef boost::shared_ptr<tcp_connection> pointer;

  tcp_connection();
  
  static pointer create(boost::asio::io_service& io_service);

  tcp::socket& socket();

  void start();

private:
  tcp_connection(boost::asio::io_service& io_service);

  void handle_write(const boost::system::error_code& /*error*/,
      size_t /*bytes_transferred*/);

  void handle_send_back(const boost::system::error_code& error, const std::size_t len);
  void handle_read();

  tcp::socket socket_;
  std::string message_;
  boost::array<char, 1> buf;
  std::string message = "";
};



#endif /* SOCKETS_TCP_CONNECTION_HPP_ */
