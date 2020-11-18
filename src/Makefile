OBJS = main.cpp Game.cpp gfx/Bitmap.cpp gfx/Screen.cpp gfx/Vec2.cpp gfx/Vec3.cpp gfx/text.cpp level/Level.cpp level/Tile.cpp network/Server.cpp
CC = g++
INCLUDE = -IC:\MinGW_lib\SDL2x86\include\SDL2
LIBRARY = -LC:\MinGW_lib\SDL2x86\lib
LINKER = -lmingw32 -lSDL2main -lSDL2 -lSDL2_net
NAME = game
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE) $(LIBRARY) $(LINKER) -o $(NAME)
