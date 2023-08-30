
#include <SDL3/SDL.h>
void getInput(bool &running);
int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;
    char data[3][3] = {0,0,0, 0,0,0, 0,0,0};
    SDL_Init(SDL_InitFlags::SDL_INIT_VIDEO);
    window = SDL_CreateWindowWithPosition("Test sdl3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 680, 0);
    if (window == NULL) {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, "%s",SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, NULL, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
    // initWindow(window, renderer,"Test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,600,600);
    bool running = true;
    while (running) {
        getInput(running);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
        SDL_RenderLine(renderer,50,50,230,230);
        SDL_RenderPresent(renderer);
        
    }

    SDL_DestroyWindow(window);
    window = NULL;


    SDL_DestroyRenderer(renderer);
    
    renderer = NULL;
    SDL_Quit();
}

void getInput(bool &running) {
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
}