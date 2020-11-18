#include "Server.h"
#include <iostream>
  UDPsocket udpsock;
  IPaddress address;
  int channel;
  bool listening;
  Server::Server(){}
  Server::~Server(){}
  void Server::start(){
    SDLNet_Init();
    printf("starting server....\n");
    //ソケットを開く、ポートを6666に設定
    udpsock = SDLNet_UDP_Open(6666);
    if(!udpsock){
      printf("SDLNet_UDP_Open: %s\n",SDLNet_GetError());
      std::exit(2);
    }

    //IPアドレスの"解決"
    if(SDLNet_ResolveHost(&address,,6666)==-1){
      printf("SDLNet_ResolveHost: %s\n",SDLNet_GetError());
    }

    //バインド

    channel = SDLNet_UDP_Bind(udpsock,-1,&address);
    if(channel==-1){
      printf("SDLNet_UDP_Bind: %s\n",SDLNet_GetError());
    }
    std::cout << "host : " << address.host << " port : " << address.port << std::endl;
    printf("server successfully started.\n");
    listening = true;
  }
  void Server::listen(){
    /*while(listening){

    }
    */
  }
  void Server::send(char* data,Uint32 host,Uint16 port){
    UDPpacket *packet = SDLNet_AllocPacket(1024);

    packet->address.host = host;
    packet->address.port = port;
    packet->len = strlen(data)+1;
    memcpy(packet->data,data,packet->len);

    int numsent;
    numsent = SDLNet_UDP_Send(udpsock,packet->channel,packet);
    if(!numsent){
      printf("SDLNet_UDP_Send: %s\n",SDLNet_GetError());
    }else{
      std::cout << "a data sent to port : " << port << " ipaddress : " << host <<  std::endl;
    }
  }
  void Server::close(){
    SDLNet_UDP_Unbind(udpsock,0);
    SDLNet_UDP_Close(udpsock);
    udpsock = NULL;
  }
