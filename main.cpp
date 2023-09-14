#include "header/framework3.hpp"
#include "header/Draw.hpp"
#include "header/loadthings.h"
#include <SDL3/SDL_rect.h>
#include <SDL3_ttf/SDL_ttf.h>
#define STARTPOINTX 25
#define STARTPOINTY 25
#define FPS_INTERVAL 1.0

//constants
const int SCREEN_WIDTH = 662;
const int SCREEN_HEIGHT = 662;

enum gameStates {
    START_SCREEN,
    PLAY_SCREEN,
    END_SCREEN,
};

//store user click data
void getInput(bool & running);

int main() {
    framework3 frame3("TicTacToe",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT);
    
    Draw mainFrame;
    Draw line;
    bool running = true;
    int i= 0;

    int defaultState = START_SCREEN;

    Uint32 fps_lasttime = SDL_GetTicks(); //the last recorded time.
    Uint32 fps_current; //the current FPS.
    Uint32 fps_frames = 0; 
    while (running) {
        frame3.handleInput(running);
        
        SDL_SetRenderDrawColor(frame3.getRenderer(), 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(frame3.getRenderer());

        SDL_FRect font1Destination = {0,0,662-30 -30,25 + 30};
        if (defaultState == START_SCREEN) {
            loadFont loadedFont1("Resources/fonts/lazy.ttf",28,2);
            SDL_Color font1Color = {255,0,0,255};
            loadedFont1.loadFontWithText("Welcome to TicTacToe!", font1Color, frame3.getRenderer());
            loadedFont1.fontRender(30, 30, frame3.getRenderer(), &font1Destination);
            // frame3.renderFont(30 , 30,&fontDestination);

            Draw rect;
            SDL_FRect recta = {30,150,662-30 -30,70};
            rect.setColor(206, 206, 13, 153);
            rect.drawRectangle(frame3.getRenderer(), &recta);

            SDL_FRect secondRect;
            secondRect.x = recta.x ;
            secondRect.y = recta.y + 120 + 150;
            secondRect.w = recta.w;
            secondRect.h = recta.h;
            Draw secondRectangle;
            secondRectangle.setColor(206, 206, 13, 153);
            secondRectangle.drawRectangle(frame3.getRenderer(), &secondRect);


            SDL_Color font2Color = {0,255,0,255};
            SDL_FRect font2Destination= {0,0,662-30-30,55};
            // loadFont loadedFont2("Resources/font/lazy.ttf",28,2);
            // loadedFont2.loadFontWithText("PLAY", font2Color, frame3.getRenderer());
            // loadedFont2.fontRender(30, 150, frame3.getRenderer(), &font2Destination);
            // loadedFont2.fontRender(30, 300, frame3.getRenderer(), &font2Destination);
            loadedFont1.free();
            loadedFont1.loadAgain("Resources/font/lazy.ttf", 28);
            loadedFont1.loadFontWithText("PLAY", font2Color, frame3.getRenderer());
            loadedFont1.fontRender(30, 155, frame3.getRenderer(), &font2Destination);

            

            
            
        }

        
        // drawPlayGround(frame3.getRenderer(), line, STARTPOINTX, STARTPOINTY);

        update(frame3.getRenderer());
        fps_frames++;
        if (fps_lasttime < SDL_GetTicks() - FPS_INTERVAL*1000)
        {
            fps_lasttime = SDL_GetTicks();
            fps_current = fps_frames;
            SDL_Log("fps: %i\n",fps_current);
            fps_frames = 0;
        }


        };
    return 0;
}
