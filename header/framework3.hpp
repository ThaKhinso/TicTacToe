#pragma once

#include "LTexture.h"


#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>

class framework3 {
public:
    framework3() = default;
    framework3(const char* title,int startposx,int startposy,int32_t screenwidth,int32_t screenheight);
    ~framework3();
    int32_t getwidth();
    int32_t getheight();
    
    SDL_Renderer* getRenderer();
    TTF_Font* getFont();

    void drawDefaultScreen();
    void renderFont(float x,float y,SDL_FRect* dst);
    bool handleInput(bool& running);

private:
    int32_t screenwidth;
    int32_t screenheight;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    LTexture fontTexture;
};
