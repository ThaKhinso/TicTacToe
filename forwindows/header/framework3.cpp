#include "framework3.hpp"
framework3::framework3(const char* title,int startposx,int startposy,int32_t screenwidth,int32_t screenheight) 
    :startgame(false){
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "%s", SDL_GetError());
    }
    window = SDL_CreateWindow(title,startposx,startposy,screenwidth,screenheight,SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "Creating window failed: %s\n",SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
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

void framework3::renderFont(float x, float y,SDL_Rect* dst) {
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


bool framework3::handleInput(bValues& values) {
    SDL_Event e;
    static bool handle = true;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            values.running = false;
        }
        if (handle == true) {
            handleMouse(&e, handle);
        }
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                values.running = false;
            }
        }
    }
    return values.running;
}

bool framework3::handleMouse(SDL_Event *e,bool& handle) {
    if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP){
        int x,y;
        SDL_GetMouseState(&x, &y);
        bool inside = true;
        if (x < 30 ) {
            printf("mouse is left of button\n");
            inside = false;
        } else if (x > 30 + 602) {
            printf("mouse if right of the button \n");
            inside = false;
        } else if (y < 155) {
            printf("mouse is above the button\n");
            inside = false;
        } else if (y > 155 + 55) {
            printf("mouse is below the button\n");
            inside = false;
        } else {
            printf("mouse is inside the button\n");
            inside = true;
        }

        if (inside == true) {
            switch (e->type) {
                case SDL_MOUSEBUTTONDOWN:
                handle = false;
                startgame = true;
                handle = false;
                return handle;
            }
        }

    }
    return handle;
}

bool framework3::getStartGame() {
    return startgame;
}
