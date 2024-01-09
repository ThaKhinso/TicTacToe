#include "Draw.hpp"
#include <cstdio>
Draw::Draw() {
    red = 0;
    green = 0;
    blue = 0;
    opacity = 0;
}

Draw::~Draw() {
    //nothing to do here
}

void Draw::drawRectangle(SDL_Renderer *renderer, const SDL_Rect* rect) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, opacity);
    SDL_RenderFillRect(renderer, rect);
    
}

void Draw::printValue() {
    printf("%i, %i, %i, %i\n",red,green,blue,opacity);
}

void Draw::drawLine(SDL_Renderer *renderer,float startx,float starty,float endx,float endy) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, opacity);
    SDL_RenderDrawLine(renderer, startx, starty, endx, endy);
}

void Draw::setColor(Uint8 r, Uint8 g, Uint8 b,Uint8 o) {
    this->red = r;
    this->green = g;
    this->blue = b;
    this->opacity = o;
}


void Draw::drawBigLine(SDL_Renderer *renderer, float startx, float starty, float endx, float endy, int width) {
    SDL_SetRenderDrawColor(renderer, red, green, blue, opacity);
    for (int i = 0; i < width; i++) {
        SDL_RenderDrawLine(renderer, startx +i, starty, endx +i, endy);
    }
}

void Draw::drawPoint(SDL_Renderer* renderer, float startx, float starty) {
    SDL_RenderDrawPoint(renderer, startx, starty);
}

void update(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
}

void drawPlayGround(SDL_Renderer *renderer, Draw &line,float STARTPOINTX,float STARTPOINTY) {
    line.setColor(0x00, 0xFF, 0x00, 0xFF);

    for (int i = 0; i < 612; i+= 203) {
    line.drawBigLine(renderer, STARTPOINTX + i, STARTPOINTY, STARTPOINTX + i, STARTPOINTY + 609, 3);
    }

    for(int i = 0;i < 612; i+=203) {
        line.drawBigLine(renderer, STARTPOINTX, STARTPOINTY + i, STARTPOINTX + 609, STARTPOINTY + i, 3);
        
    }
}

void drawCross(SDL_Renderer *renderer, Draw &line, float STARTPOINTX, float STARTPOINTY, float ENDPOINTX,float ENDPOINTY) {
    line.setColor(0xFF, 0x00, 0x00, 0xFF);
    for (int i = 0; i < STARTPOINTX + 100; i++) {
        if (STARTPOINTX < 200 || STARTPOINTY < 200 ) {
            line.drawPoint(renderer, STARTPOINTX + i, STARTPOINTY + i);
        }
    }

}