#pragma once

#include "LTexture.h"

class framework3 {
public:
    framework3() = default;
    framework3(const char* title,int startposx,int startposy,int32_t screenwidth,int32_t screenheight);
    ~framework3();
    int32_t getwidth();
    int32_t getheight();
    
    SDL_Renderer* getRenderer();

    void drawDefaultScreen();
    void renderFont(float x,float y,SDL_FRect* dst);
    bool handleInput(bool& running);
    void handleMouse(SDL_Event* e);

private:
    int32_t screenwidth;
    int32_t screenheight;
    SDL_Window* window;
    SDL_Renderer* renderer;
    LTexture fontTexture;
};
