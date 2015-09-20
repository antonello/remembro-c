/*
 * tcp_server.hpp
 *
 *  Created on: 15 Sep 2015
 *      Author: delio
 */

#ifndef SOCKETS_TCP_SERVER_HPP_
#define SOCKETS_TCP_SERVER_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include "tcp_connection.hpp"

using boost::asio::ip::tcp;

class tcp_server
{
public:
  tcp_server(boost::asio::io_service& io_service);

private:
  void start_accept();

  void handle_accept(tcp_connection::pointer new_connection,
      const boost::system::error_code& error);
  tcp::acceptor acceptor_;
};






#endif /* SOCKETS_TCP_SERVER_HPP_ */
