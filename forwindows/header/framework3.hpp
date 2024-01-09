#pragma once

#include "LTexture.h"

enum gm_state {
    
};

typedef struct {
    bool running;
    bool startgame;
}bValues;

class framework3 {
public:
    framework3() = default;
    framework3(const char* title,int startposx,int startposy,int32_t screenwidth,int32_t screenheight);
    ~framework3();
    int32_t getwidth();
    int32_t getheight();
    SDL_Renderer* getRenderer();

    void drawDefaultScreen();
    void renderFont(float x,float y,SDL_Rect* dst);
    bool handleInput(bValues& values);
    bool handleMouse(SDL_Event* e,bool &handle);
    bool getStartGame();
    

private:
    int x; int y;
    bool startgame;
    int32_t screenwidth;
    int32_t screenheight;
    SDL_Window* window;
    SDL_Renderer* renderer;
    LTexture fontTexture;
};
