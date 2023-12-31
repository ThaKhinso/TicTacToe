#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
class Draw {
public:
    Draw();
    ~Draw();
    void drawRectangle(SDL_Renderer* renderer,const SDL_FRect* rect);
    void drawLine(SDL_Renderer* renderer,float startx,float starty,float endx,float endy);
    void drawBigLine(SDL_Renderer* renderer,float startx,float starty,float endx,float endy, int width);
    void drawPoint(SDL_Renderer* renderer, float startx, float starty);
    void drawCircle(SDL_Renderer* renderer);
    void setColor(Uint8 r,Uint8 g,Uint8 b,Uint8 o);
    void printValue();

private:
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    Uint8 opacity;
};

void update(SDL_Renderer* renderer);

void drawPlayGround(SDL_Renderer* renderer,Draw& line,float STARTPOINTX,float STARTPOINTY);
void drawCross(SDL_Renderer* renderer,Draw& line, float startpointx,float startpointy,float ENDPOINTX,float ENDPOINTY);
