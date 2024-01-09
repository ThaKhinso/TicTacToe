#OBJS specifies which files to compile as part of the project
OBJS = main.cpp header/framework3.cpp header/Draw.cpp header/LTexture.cpp header/loadthings.cpp header/Button.cpp
OBJTEST = nvimtst.cpp header/framework3.cpp header/Draw.cpp header/LTexture.cpp header/loadthings.cpp header/Button.cpp
SHARED = header/framework3.cpp header/Draw.cpp header/LTexture.cpp header/loadthings.cpp
#CC specifies which compiler we're using
CC1 = icpx
CC2 = g++

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -Iheader/

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LDependency/

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,--subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL3 -lSDL3_image -lSDL3_ttf
LINKER_FLAGS2 = -lSDL3 -lSDL3_image -lSDL3_ttf -mwindows#lSDL3_ttf -lX11 -lXext -ldl -lpthread -s

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin/TicTacToe

#This is the target that compiles our executable
g++ : $(OBJS)
		$(CC2) -O3 $(OBJS) -I header/ $(LINKER_FLAGS) -o $(OBJ_NAME)

g++shared : $(OBJS)
				$(CC2) -shared $(SHARED)

test : $(OBJS)
		$(CC2) -O3 $(OBJTEST) -I header/ $(LINKER_FLAGS) -o bin/tested

testE : $(OBJS)
		$(CC2) $(OBJTEST) -I header/ -E > preprocced.cpp

icc : $(OBJS)
		$(CC1) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)_icc

g++static : $(OBJS)
		$(CC2) $(OBJS) /usr/local/lib64/libSDL3.a /usr/local/lib64/libSDL3main.a /usr/local/lib64/libSDL3_image.a -lSDL3_ttf -o $(OBJ_NAME)_static