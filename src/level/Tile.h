#ifndef TILE_H
#define TILE_H
#include "../gfx/Screen.h"
class Tile{
  int xtex = 0;
  int ytex = 0;
  int color = 0;
public:
  Tile(int tx,int ty);
  Tile(int tx,int ty,int col);
  void render(Screen* screen,int x,int y);
};
#endif
