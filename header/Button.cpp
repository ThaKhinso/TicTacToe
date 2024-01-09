#include "Button.hpp"
#include <stdio.h>

Button::Button(float stPointx, float stPointy, float sizew, float sizeh) :
    startx(stPointx), starty(stPointy), width(sizew), height(sizeh)
{
    // printf("initialized button\n");
}

void Button::draw(SDL_Renderer* renderer, color& color) {
    SDL_FRect rec = { startx, starty, width, height };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.alpha);
    SDL_RenderFillRect(renderer, &rec);
}