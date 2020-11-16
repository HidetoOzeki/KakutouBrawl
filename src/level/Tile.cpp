#include "Tile.h"
Tile::Tile(int tx,int ty,int col){
  xtex = tx;
  ytex = ty;
  color = col;
}
Tile::Tile(int tx,int ty){
  Tile(tx,ty,0xFFFFFF);
}
void Tile::render(Screen* screen,int x,int y){
  screen->render(nullptr,x,y,xtex,ytex,color);
}
