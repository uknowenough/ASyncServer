#ifndef SERVER_H
#define SERVER_H

#include <memory>

#include "asio/io_service.hpp"
#include "asio/ip/tcp.hpp"
#include "asio/error_code.hpp"

#include <boost/bind/bind.hpp>

typedef asio::ip::tcp::endpoint Endpoint;
typedef std::shared_ptr<asio::ip::tcp::socket> Socket;
typedef asio::ip::tcp::acceptor Acceptor;

class Server
{
 public:
  /**
   * @brief Конструктор с параметрами
   *
   * @param address IP-адрес
   * @param port    Порт
   */
  Server(const char* address, asio::ip::port_type port);

 public:
  /**
   * @brief Метод запускает сервер
   */
  void start();

  /**
   * @brief Метод запускает приём новых соединений
   */
  void startAccept(Socket sock);

 private:
  //! ASIO Service
  asio::io_service service_;
  //! Endpoint
  Endpoint ep_;
  //! Acceptor
  Acceptor acc_;
};

#endif // SERVER_H
