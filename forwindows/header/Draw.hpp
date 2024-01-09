#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Draw {
public:
    Draw();
    ~Draw();
    void drawRectangle(SDL_Renderer* renderer,const SDL_Rect* rect);
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
void drawCross(SDL_Renderer* renderer,Draw& line, float STARTPOINTX,float STARTPOINTY);
