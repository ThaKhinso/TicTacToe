#include "header/framework3.hpp"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <iostream>
//store user click data
void drawDefaultScreen();
void getInput(bool & running);
int main() {
    // char data[3][3] = {0,0,0, 0,0,0, 0,0,0};
    // int32_t sdlver;
    // std::cout << "which version you want to use 2 or 3?:"<<"\n";
    // std::cin >> sdlver;
    // if (sdlver == 2) {
    //     /*run here*/
    //     framework frame(800,600);
    // bool tworunning = true;
    
    // while (tworunning) {
    //     SDL_Event e;
    //     while (SDL_PollEvent(&e) != 0) {
    //         if (e.type == SDL_QUIT) {
    //             tworunning = false;
    //         }
    //         SDL_SetRenderDrawColor(frame.getRenderer(), 0x00, 0x00, 0x00, 0xFF);
    //         SDL_RenderClear(frame.getRenderer());

    //         SDL_SetRenderDrawColor(frame.getRenderer(), 0x00, 0xFF, 0x00, 0xFF);
    //         for (int i = 0; i < 10; i ++) {
    //             SDL_RenderDrawLine(frame.getRenderer(), 50 +i, 50+i, 200 +i, 200+i);
    //         }

    //         SDL_RenderPresent(frame.getRenderer());
    //     }
    // };
    // }
    // if (sdlver == 3){
        /* run here */
        framework3 frame3("TicTacToe",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600);
        bool running = true;
    
        while (running) {
            frame3.handleInput(running);
            SDL_SetRenderDrawColor(frame3.getRenderer(), 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderClear(frame3.getRenderer());

            smartRectangle d(50,50,700,500);
            SDL_SetRenderDrawColor(frame3.getRenderer(), 128, 128, 0x00, 0xFF);
            d.draw(frame3.getRenderer());
            SDL_SetRenderDrawColor(frame3.getRenderer(), 0x00, 0xFF, 0x00, 0xFF);
            for (int i = 0; i < 2; i++) {
                SDL_RenderLine(frame3.getRenderer(), 50 , 50 +i, 750, 50 + i);

            }
            // for (int i = 0; i<2;i++) {
            //     SDL_RenderLine(frame3.getRenderer(), 100 +i, 50, 700+i, 50);
            // }
            SDL_RenderLine(frame3.getRenderer(), 50, 50, 50, 550);
            SDL_RenderLine(frame3.getRenderer(), 50, 550, 750, 550);
            SDL_RenderLine(frame3.getRenderer(), 750, 550, 750, 50);

            SDL_RenderPresent(frame3.getRenderer());
        };
    // }
    return 0;
}