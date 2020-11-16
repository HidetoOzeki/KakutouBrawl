#include "Level.h"

Tile *tiles[32];

Level::Level(){
  level = new int[width*height];
  tiles[0] = new Tile(4,3,0xaa9933);
  tiles[1] = new Tile(4,3,0x3399aa);
}
void Level::render(Screen* screen){
  for(int i = 0;i < width;i++){
    for(int j = 0;j < height;j++){
      int id = level[i+j*width];
      //tiles[id].render(screen,i*16,j*16);
    }
  }
}
