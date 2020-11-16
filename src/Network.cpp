#include <SDL.h>
#include <SDL_net.h>
#include <cstdio>
class Network {
public:
  Network(){}
  ~Network(){}

int receive(){
  UDPsocket sock;
  IPaddress *address;
  int channel;

  sock = SDLNet_UDP_Open(666);
  if(!sock){
    printf("SDLNet_UDP_Open: %s\n",SDLNet_GetError());
  }

  channel = SDLNet_UDP_Bind(sock,-1,address);
  if(channel==-1){
    printf("SDLNet_UDP_Bind: %s\n",SDLNet_GetError());
  }

  UDPpacket * packet = SDLNet_AllocPacket(1024);
  int numrecv;
  numrecv = SDLNet_UDP_Recv(sock,packet);
  if(numrecv){
    printf("%s\n",packet->data);
  }


  return 0;
}
int send(){
  UDPsocket sock;
  UDPpacket *packet = SDLNet_AllocPacket(1024);
  IPaddress *address;
  int channel;
  int numsent;

  static const char* data = "aye";
  packet->len = strlen(data)+1;
  memcpy(packet->data,data,p->len);
  packet->address =

  sock = SDLNet_UDP_Open(666);
  if(!sock){
    printf("SDLNet_UDP_Open: %s\n",SDLNet_GetError());
  }

  channel = SDLNet_UDP_Bind(sock,-1,address);
  if(channel==-1){
    printf("SDLNet_UDP_Bind: %s\n",SDLNet_GetError());
  }

  numsent = SDLNet_UDP_Send(sock,packet->channel,packet);
  if(!numsent){
    printf("SDLNet_UDP_Send: %s\n",SDLNet_GetError());
  }

  return 0;
}

};
