#ifndef LEVEL_H
#define LEVEL_H
#include "../gfx/Screen.h"
#include "Tile.h"
class Level{
  private:
    int width = 128;
    int height = 128;
    int* level;
  public :
  Level();
  ~Level(){delete level;}
  void render(Screen* screen);
};
#endif
