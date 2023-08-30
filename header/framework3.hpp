#pragma once

#include <SDL3/SDL.h>

class framework3 {
public:
    framework3() = default;
    framework3(const char* title,int startposx,int startposy,int32_t screenwidth,int32_t screenheight);
    ~framework3();
    int32_t getwidth();
    int32_t getheight();
    SDL_Renderer* getRenderer();
    bool handleInput(bool& running);

private:
    int32_t screenwidth;
    int32_t screenheight;
    SDL_Window* window;
    SDL_Renderer* renderer;

};

class smartRectangle {
public:
    smartRectangle(float startPointx,float startPointy,float width,float height);
    
    ~smartRectangle();
    void draw(SDL_Renderer* renderer);
private:
    float startx;
    float starty;
    float width;
    float height;
    SDL_FRect* rect;
};