#include "Server.h"

asio::io_service service;

static void handleAccept(Server* server, Socket sock, const asio::error_code &err);

Server::Server(const char *address, asio::ip::port_type port)
    : ep_(asio::ip::address::from_string(address), port),
      acc_(service, ep_)
{

}

void Server::start()
{
  Socket sock(new asio::ip::tcp::socket(service));
  this->startAccept(sock);

  service.run();
}

void Server::startAccept(Socket sock)
{
  asio::error_code ec;
  acc_.async_accept(*sock, boost::bind(handleAccept, this, sock, ec));
}

void handleAccept(Server* server, Socket /*sock*/, const asio::error_code &err)
{
  if (err)
    return;
  // at this point, you can read/write to the socket
  Socket sock(new asio::ip::tcp::socket(service));
  server->startAccept(sock);
}
