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

tcp_connection::tcp_connection() : message(std::string()) { }

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

void tcp_connection::handle_send_back(const boost::system::error_code& error, std::size_t len)
  {
	std::cout << "Q4\n";
    if (!error)
    {
    	if (buf.data()[0] != '|') {
    		std::cout << "NO " << buf.data()[0] << "\n";
    		message += buf.data()[0];
    		std::cout << "NO " << message << "\n";
    	}
    	else {
    		std::cout << "SI " << buf.data()[0] << "\n";
    		std::cout << buf.data()[0] << "\n";
    		std::cout << message << " |aaaa| " << len << "\n";
    		    	async_write(socket_, boost::asio::buffer(message, message.length()), boost::bind(&tcp_connection::handle_write, shared_from_this(),
    		    				boost::asio::placeholders::error,
    		    				boost::asio::placeholders::bytes_transferred));
    	}

    	handle_read();
    }
    else
    {
    	std::cout << error << '\n';
    }

  }

void tcp_connection::handle_read()
{
	boost::system::error_code error;
	async_read(socket_, boost::asio::buffer(buf), boost::bind(&tcp_connection::handle_send_back, shared_from_this(),
			boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}
