#include "initSDL.h"

void initWindow(SDL_Window *window, SDL_Renderer *renderer, const char* title, int x, int y,int width,int height){
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title, x,y,width, height, SDL_WINDOW_VULKAN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    


}