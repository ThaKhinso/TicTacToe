#pragma once

#include <SDL3/SDL.h>

class framework3 {
public:
    framework3() = default;
    framework3(int32_t screenwidth,int32_t screenheight);
    ~framework3();
    int32_t getwidth();
    int32_t getheight();
    SDL_Renderer* getRenderer();

private:
    int32_t screenwidth;
    int32_t screenheight;
    SDL_Window* window;
    SDL_Renderer* renderer;

};