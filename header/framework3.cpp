#include "framework3.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <cstdio>
#include <iostream>

framework3::framework3(const char* title,int startposx,int startposy,int32_t screenwidth,int32_t screenheight) {
    if (SDL_Init(SDL_InitFlags::SDL_INIT_VIDEO)) {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
    }
    window = SDL_CreateWindowWithPosition("Snake",startposx,startposy,screenwidth,screenheight,SDL_WINDOW_VULKAN);
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
bool framework3::handleInput(bool &running) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_EVENT_QUIT) {
            running = false;
        }
        if (e.type == SDL_EVENT_KEY_DOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
        }
    }
    return running;
}

smartRectangle::smartRectangle(float startPointx,float startPointy,float width,float height)
    :startx(startPointx),starty(startPointy),width(width),height(height) {
        rect = new SDL_FRect {startx,starty,width,height};
}

smartRectangle::~smartRectangle() {
    delete rect;
    printf("Destroyed rect\n");
}

void smartRectangle::draw(SDL_Renderer* renderer) {
    SDL_RenderFillRect( renderer, rect);
}