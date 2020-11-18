#ifndef SERVER_H
#define SERVER_H
#include <SDL.h>
#include <SDL_net.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
class Server{
  public :
  Server();
  ~Server();
  void start();
  void listen();
  void send(char* data,Uint32 host,Uint16 port);
  void close();
};
#endif
