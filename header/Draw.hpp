#ifndef DRAW_HPP
#define DRAW_HPP
#include <SDL3/SDL.h>
class Draw {
public:
    Draw();
    ~Draw();
    void drawRectangle(SDL_Renderer* renderer,const SDL_FRect* rect);
    void drawLine(SDL_Renderer* renderer,float startx,float starty,float endx,float endy);
    void drawBigLine(SDL_Renderer* renderer,float startx,float starty,float endx,float endy, int width);
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
#endif