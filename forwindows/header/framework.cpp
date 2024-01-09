#include "framework.hpp"
#include <iostream>

framework::framework(int32_t screenwidth,int32_t screenheight) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Snake",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screenwidth,screenheight,SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("winodw failed %s\n",SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    
}

framework::~framework() {
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_Quit();
}

int32_t framework::getwidth() {
    return screenwidth;
}

int32_t framework::getheight() {
    return screenheight;
}

SDL_Renderer* framework::getRenderer() {
    return renderer;
}