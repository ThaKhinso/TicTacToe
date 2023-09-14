#include "framework3.hpp"

framework3::framework3(const char* title,int startposx,int startposy,int32_t screenwidth,int32_t screenheight) {
    if (SDL_Init(SDL_InitFlags::SDL_INIT_VIDEO)) {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
    }
    window = SDL_CreateWindowWithPosition(title,startposx,startposy,screenwidth,screenheight,SDL_WINDOW_VULKAN);
    if (window == NULL)
    {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "Creating window failed: %s\n",SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,NULL,SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "Creating renderer failedL %s\n",SDL_GetError());
    } else {
        int img_flags = IMG_INIT_PNG;
        if( !( IMG_Init( img_flags ) & img_flags ) ) {
            SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "Initializing sdl image failed %s\n",IMG_GetError());
        }

        if (TTF_Init() == -1) {
            SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "Initializing sdl ttf failed %s\n",TTF_GetError());
        } else {
            
        }
    }

    
}

framework3::~framework3() {

    fontTexture.free();


    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_Quit();
}

void framework3::renderFont(float x, float y,SDL_FRect* dst) {
    fontTexture.render(x, y, renderer,dst);
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

void framework3::drawDefaultScreen() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    
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

void framework3::handleMouse(SDL_Event *e) {
    
}

