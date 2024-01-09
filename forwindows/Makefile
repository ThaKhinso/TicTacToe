#OBJS specifies which files to compile as part of the project
OBJS = main.cpp header/framework3.cpp header/Draw.cpp header/LTexture.cpp header/loadthings.cpp
SHARED = header/framework3.cpp header/Draw.cpp header/LTexture.cpp header/loadthings.cpp
#CC specifies which compiler we're using
CC1 = icpx
CC2 = x86_64-w64-mingw32-g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I /home/soethiha/Dev/mainTicTacToe/window/libs/SDL2-devel-2.28.3-mingw/SDL2-2.28.3/x86_64-w64-mingw32/include/SDL2/ -I /home/soethiha/Dev/mainTicTacToe/window/libs/SDL2_image-devel-2.6.3-mingw/SDL2_image-2.6.3/x86_64-w64-mingw32/include/SDL2/ -I /home/soethiha/Dev/mainTicTacToe/window/libs/SDL2_ttf-devel-2.20.2-mingw/SDL2_ttf-2.20.2/x86_64-w64-mingw32/include/SDL2/

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L /home/soethiha/Dev/mainTicTacToe/window/libs/SDL2-devel-2.28.3-mingw/SDL2-2.28.3/x86_64-w64-mingw32/lib/ -L /home/soethiha/Dev/mainTicTacToe/window/libs/SDL2_ttf-devel-2.20.2-mingw/SDL2_ttf-2.20.2/x86_64-w64-mingw32/lib -L /home/soethiha/Dev/mainTicTacToe/window/libs/SDL2_image-devel-2.6.3-mingw/SDL2_image-2.6.3/x86_64-w64-mingw32/lib
STATICLIB_PATHS = libSDL2main.a libSDL2.a libSDL2_image.a libSDL2_ttf.a 
#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,--subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_SECVER = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lsetupapi -lole32 -lgdi32 -limm32 -lversion -loleaut32 -lwinmm
LINKER_FLAGS_WIN = -lmingw32 -lSDL2main -lSDL2 -lsetupapi -lole32 -lgdi32 -limm32 -lversion -loleaut32 -lwinmm -lSDL2_image -lSDL2_ttf -lole32 -lgdi32 
LINKER_FLAGS = -lSDL3 -lSDL3_image -lSDL3_ttf
LINKER_FLAGS2 = -lSDL3 -lSDL3_image -lSDL3_ttf -mwindows#lSDL3_ttf -lX11 -lXext -ldl -lpthread -s

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin/TicTacToe

#This is the target that compiles our executable
ming++ : $(OBJS)
		$(CC2) -O3 $(OBJS) $(INCLUDE_PATHS) -static $(LIBRARY_PATHS) $(LINKER_SECVER) -o $(OBJ_NAME)_static

minstatic : $(OBJS)
		$(CC2) -O3 $(OBJS) $(STATICLIB_PATHS) $(INCLUDE_PATHS) -lmingw32 -lSDL2main -lsetupapi -lole32 -lgdi32 -limm32 -lversion -loleaut32 -lwinmm -static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive -o $(OBJ_NAME)_static

g++shared : $(OBJS)
				$(CC2) -shared $(SHARED)


icc : $(OBJS)
		$(CC1) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)_icc

g++static : $(OBJS)
		$(CC2) $(OBJS) /usr/local/lib64/libSDL3.a /usr/local/lib64/libSDL3main.a /usr/local/lib64/libSDL3_image.a -lSDL3_ttf -o $(OBJ_NAME)_static