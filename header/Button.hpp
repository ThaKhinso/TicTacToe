#pragma once

#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <cstdint>

struct color {
    int r;
    int g;
    int b;
    int alpha;
};
class Button {
public:
    Button() = default;
    Button(float stPointx, float stPointy, float sizew, float sizeh);

    void draw(SDL_Renderer* renderer, color& color);
    bool onClicked(SDL_Event* e, bool& handle);
    
private:
    float startx,starty,width,height;
    int32_t mousepos_x;
    int32_t mousepos_y;
};