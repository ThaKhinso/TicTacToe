#pragma once 

#include "LTexture.h"
#include <string>


class loadFont {
public:
    loadFont(std::string path,int ptsize,int loadFromWhat);
    ~loadFont();
    void loadFontRaw(int ptsize);
    void loadFontWithText(std::string text,SDL_Color textColor,SDL_Renderer* renderer);
    void fontRender(int x,int y,SDL_Renderer* renderer,SDL_Rect* dst);
    void free();
    void loadAgain(int ptsize);

    void setTextColor(SDL_Color &color);

    TTF_Font* getFont();
    LTexture getTexture();
private:
    std::string name;
    TTF_Font* lFont;
    LTexture fontTexture;
    SDL_Color color;
};

