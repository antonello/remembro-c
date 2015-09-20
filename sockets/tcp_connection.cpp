//
// server.cpp
// ~~~~~~~~~~
//
// Copyright (c) 2003-2015 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include "tcp_connection.hpp"

using boost::asio::ip::tcp;

typedef boost::shared_ptr<tcp_connection> pointer;

pointer tcp_connection::create(boost::asio::io_service& io_service)
{
	return pointer(new tcp_connection(io_service));
}

tcp::socket& tcp_connection::socket()
{
	return socket_;
}

void tcp_connection::start()
{
	message_ = "aaaa";

	boost::asio::async_write(socket_, boost::asio::buffer(message_),
		boost::bind(&tcp_connection::handle_write, shared_from_this(),
		boost::asio::placeholders::error,
		boost::asio::placeholders::bytes_transferred));

	handle_read();
}

tcp_connection::tcp_connection(boost::asio::io_service& io_service)
	: socket_(io_service)
{
}

void tcp_connection::handle_write(const boost::system::error_code& /*error*/,
  size_t /*bytes_transferred*/)
{
}

void tcp_connection::handle_send_back(const boost::array<char, 128> buf, const boost::system::error_code& error, std::size_t len)
  {
	std::cout << "Q4\n";
    if (!error)
    {
    	std::cout << buf.data() << " aaaa " << len << "\n";
    	async_write(socket_, boost::asio::buffer(buf, len), boost::bind(&tcp_connection::handle_write, shared_from_this(),
    				boost::asio::placeholders::error,
    				boost::asio::placeholders::bytes_transferred));
    	//handle_read();
    }
    else
    {

    }

  }

void tcp_connection::handle_read()
{
	boost::array<char, 128> buf;
	boost::system::error_code error;
	async_read(socket_, boost::asio::buffer(buf), boost::bind(&tcp_connection::handle_send_back, shared_from_this(),
			buf, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}
