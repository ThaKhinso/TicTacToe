#include "header/framework.hpp"
#include <SDL2/SDL_render.h>
#include "header/framework3.hpp"
#include <cstdint>
#include <iostream>
#include <string>
//store user click data

int main() {
    char data[3][3] = {0,0,0, 0,0,0, 0,0,0};
    int32_t sdlver;
    std::cout << "which version you want to use 2 or 3?:"<<"\n";
    std::cin >> sdlver;
    if (sdlver == 2) {
        /*run here*/
        framework frame(800,600);
    bool tworunning = true;
    
    while (tworunning) {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                tworunning = false;
            }
            SDL_SetRenderDrawColor(frame.getRenderer(), 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderClear(frame.getRenderer());

            SDL_SetRenderDrawColor(frame.getRenderer(), 0x00, 0xFF, 0x00, 0xFF);
            SDL_RenderDrawLine(frame.getRenderer(), 50, 50, 200, 200);

            SDL_RenderPresent(frame.getRenderer());
        }
    };
    }
    if (sdlver == 3){
        /* run here */
        framework3 frame3(800,600);
        bool running = true;
    
        while (running) {
            SDL_Event e;
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    running = false;
                }
                SDL_SetRenderDrawColor(frame3.getRenderer(), 0x00, 0x00, 0x00, 0xFF);
                SDL_RenderClear(frame3.getRenderer());

                SDL_SetRenderDrawColor(frame3.getRenderer(), 0x00, 0xFF, 0x00, 0xFF);
                SDL_RenderDrawLine(frame3.getRenderer(), 50, 50, 200, 200);

                SDL_RenderPresent(frame3.getRenderer());
            }
        };
    }
    
    return 0;
}

void getInput(bool &running) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }

            if (e.type == SDL_KEYDOWN) {
                if (e.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }
}