#include "framework3.hpp"
#include <iostream>

framework3::framework3(int32_t screenwidth,int32_t screenheight) {
    if (SDL_Init(SDL_InitFlags::SDL_INIT_VIDEO)) {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
    }
    window = SDL_CreateWindowWithPosition("Snake",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screenwidth,screenheight,SDL_WINDOW_VULKAN);
    if (window == NULL)
    {
        printf("winodw failed %s\n",SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,NULL,SDL_RENDERER_ACCELERATED);

    
}

framework3::~framework3() {
    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_Quit();
}

int32_t framework3::getwidth() {
    return screenwidth;
}

int32_t framework3::getheight() {
    return screenheight;
}

SDL_Renderer* framework3::getRenderer() {
    return renderer;
}