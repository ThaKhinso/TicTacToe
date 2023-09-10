#OBJS specifies which files to compile as part of the project
OBJS = main.cpp header/framework3.cpp header/Draw.cpp header/LTexture.cpp

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
LINKER_FLAGS = -lSDL3 -lSDL3_image -lSDL3_ttf -s
LINKER_FLAGS2 = -lSDL3 -lSDL3_image -lSDL3_ttf -mwindows#lSDL3_ttf -lX11 -lXext -ldl -lpthread -s

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin/TicTacToe

#This is the target that compiles our executable
gcc : $(OBJS)
		$(CC2) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)

noterminal : $(OBJS)
				g++ $(OBJS) $(LINKER_FLAGS2) -o $(OBJ_NAME)_noter

icc : $(OBJS)
		$(CC1) $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)_icc

g++Static : $(OBJS)
		$(CC1) $(OBJS) /usr/local/lib64/libSDL3.a -o $(OBJ_NAME)_static