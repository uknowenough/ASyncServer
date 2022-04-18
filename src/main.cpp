#include "Server.h"

int main()
{
  std::unique_ptr<Server> server = std::make_unique<Server>("127.0.0.1", 2001);
  server->start();

  return 0;
}
