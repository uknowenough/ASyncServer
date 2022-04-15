#include <iostream>

#include "asio/io_service.hpp"
#include "asio/ip/tcp.hpp"
#include "asio/error_code.hpp"

#include <boost/bind/bind.hpp>

typedef std::shared_ptr<asio::ip::tcp::socket> socket_ptr;

using namespace asio;

typedef std::shared_ptr<ip::tcp::socket> socket_ptr;

using asio::io_service;

io_service service;

ip::tcp::endpoint ep  = ip::tcp::endpoint(ip::address::from_string("127.0.0.1"), 2001);
ip::tcp::acceptor acc(service, ep);

void start_accept(socket_ptr sock);
void handle_accept(socket_ptr sock, const asio::error_code& err);

int main()
{
  socket_ptr sock(new ip::tcp::socket(service));
  start_accept(sock);

  service.run();

  return 0;
}

void start_accept(socket_ptr sock)
{
  asio::error_code ec;
  acc.async_accept(*sock, boost::bind(handle_accept, sock, ec));
}

void handle_accept(socket_ptr /*sock*/, const asio::error_code& err)
{
  if (err)
    return;
  // at this point, you can read/write to the socket
  socket_ptr sock(new asio::ip::tcp::socket(service));
  start_accept(sock);
}
